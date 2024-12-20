# model for increment alone

import cocotb
from cocotb_coverage.coverage import *
import numpy as np
import struct


def bf16_to_decimal(bf16_binary):
    """Converts a BF16 binary string to a decimal number."""
    # Ensure the input is 16 bits long
    if len(bf16_binary) != 16:
        raise ValueError("BF16 binary string must be 16 bits long.")
    
    # Extract the sign, exponent, and mantissa from the binary string
    sign_bit = int(bf16_binary[0], 2)
    exponent = int(bf16_binary[1:9], 2)
    mantissa = int(bf16_binary[9:], 2)
    
    # Construct the 32-bit FP32 bit pattern
    # (1 sign bit | 8 exponent bits | 7 mantissa bits | 16 extra zeros)
    fp32_bits = (sign_bit << 31) | (exponent << 23) | (mantissa << 16)

    # Convert the 32-bit integer back to a float
    fp32_bytes = struct.pack('>I', fp32_bits)
    decimal_number = struct.unpack('>f', fp32_bytes)[0]
    
    return decimal_number
    
def fp32_to_decimal(fp32_binary):
    if len(fp32_binary) != 32:
        raise ValueError("FP32 binary string must be 32 bits long")
    
    sign = int(fp32_binary[0], 2)
    exp = int(fp32_binary[1:9], 2)
    mant = int(fp32_binary[9:], 2)
    
    fp32_bits = (sign<<32) | (exp<<23) | (mant)
    
    fp32_bytes = struct.pack('>I', fp32_bits)
    decimal_number = struct.unpack('>f', fp32_bytes)[0]
    return decimal_number


bf16_options = []
for exponent in range(1 << 8):  
    for mantissa_upper in range(1 << 6):  
        bf16_value = 0<<15 |(exponent << 7) | (mantissa_upper << 1)
        bf16_options.append(format(bf16_value, '016b'))
bf16_decimal = []
for i in range(len(bf16_options)):
    bf16_decimal.append(bf16_to_decimal(bf16_options[i]))
    
fp32_options = []
for exponent_lower in range(1 << 8):  
    for mantissa_upper in range(1 << 14): 
        fp32_value =  0<<31 | (exponent_lower << 23) | (mantissa_upper << 9)
        fp32_options.append(format(fp32_value, '032b'))
fp32_decimal = []
for i in range(len(fp32_options)):
    fp32_decimal.append(fp32_to_decimal(fp32_options[i]))


mac_coverage = coverage_section(
    CoverPoint('top.get_inputs_s', vname='get_inputs_s', bins = list(range(0,1))),
    CoverPoint('top.get_inputs_a', vname='get_inputs_a', bins = [10.75, 7012876288.0, 46.0, 34340864.0, 15971909632.0, 5120.0, 17582522368.0, 1546188226560.0, 6016.0]),
    CoverPoint('top.get_inputs_b', vname='get_inputs_b', bins = [7868380086272.0, 4707284156416.0, 9502720.0, 8053063680.0, 98.5, 704374636544.0, 11403264.0, 0.2314453125, 1294336.0]),
    CoverPoint('top.get_inputs_c', vname='get_inputs_c', bins = [25.345001220703125, 3236962500608.0, 159383.5625, 76965814272.0, 415236.125, 244091600896.0, 214748368.0, 805306.375, 4160749.75]),
    CoverPoint('top.EN_get_inputs', vname='EN_get_inputs', bins = list(range(0,2))),
    CoverCross('top.cross_cover', items = ['top.get_inputs_s', 'top.get_inputs_a', 'top.get_inputs_b', 'top.get_inputs_c', 'top.EN_get_inputs'])
)
@mac_coverage
def model_mac(EN_get_inputs: int, get_inputs_s: int, get_inputs_a: float, get_inputs_b: float, get_inputs_c: float) -> str:
    #Condition for int mac operation
    if(EN_get_inputs == 1 and get_inputs_s == 1):
        
        #Code to compute mac
        value = get_inputs_a*get_inputs_b
        value = decimal_to_bf16_signed(value)
        value = bf16_to_decimal(value) + get_inputs_c
        value_fp = decimal_to_fp32_signed(value)
        return value_fp
    return 'wrong'

def decimal_to_fp32_signed(decimal_number):
    """Converts a decimal number to a binary FP32 signed representation."""
    fp32 = np.float32(decimal_number)
    # Pack float as bytes in IEEE 754 format and unpack as unsigned int
    fp32_bits = struct.unpack('>I', struct.pack('>f', fp32))[0]
    # Extract the sign, exponent, and mantissa to construct binary FP32 format
    sign_bit = (fp32_bits >> 31) & 0x1
    exponent = (fp32_bits >> 23) & 0xFF  # Next 8 bits
    mantissa = fp32_bits & 0x7FFFFF      # Last 23 bits
    
    # Combine into the final FP32 binary format
    fp32_binary = f"{sign_bit}{exponent:08b}{mantissa:023b}"
    return fp32_binary

def bf16_to_decimal(bf16_binary):
    """Converts a BF16 binary string to a decimal number."""
    # Ensure the input is 16 bits long
    if len(bf16_binary) != 16:
        raise ValueError("BF16 binary string must be 16 bits long.")
    
    # Extract the sign, exponent, and mantissa from the binary string
    sign_bit = int(bf16_binary[0], 2)
    exponent = int(bf16_binary[1:9], 2)
    mantissa = int(bf16_binary[9:], 2)
    
    # Construct the 32-bit FP32 bit pattern
    # (1 sign bit | 8 exponent bits | 7 mantissa bits | 16 extra zeros)
    fp32_bits = (sign_bit << 31) | (exponent << 23) | (mantissa << 16)

    # Convert the 32-bit integer back to a float
    fp32_bytes = struct.pack('>I', fp32_bits)
    decimal_number = struct.unpack('>f', fp32_bytes)[0]
    
    return decimal_number

def decimal_to_bf16_signed(decimal_number):
    """Converts a decimal number to a binary BF16 signed representation with rounding."""
    # Convert the decimal number to 32-bit IEEE 754 float
    fp32 = np.float32(decimal_number)
    
    # Pack the float into bytes and unpack it as an unsigned 32-bit integer
    fp32_bits = struct.unpack('>I', struct.pack('>f', fp32))[0]
    
    # Extract the top 16 bits (candidate BF16 bits) and the lower 16 bits
    top_16_bits = (fp32_bits >> 16) & 0xFFFF
    lower_16_bits = fp32_bits & 0xFFFF  # Remaining bits after the top 16
    
    # Check if we need to round up
    if lower_16_bits > 0x8000 or (lower_16_bits == 0x8000 and (top_16_bits & 1) == 1):
        # If rounding up, add 1 to the top 16 bits
        top_16_bits += 1

    # Extract the sign, exponent, and mantissa from the (possibly rounded) BF16 bits
    sign_bit = (top_16_bits >> 15) & 0x1            # 1 bit
    exponent = (top_16_bits >> 7) & 0xFF            # 8 bits
    mantissa = top_16_bits & 0x7F                   # 7 bits

    # Construct the final BF16 binary representation as a string
    bf16_binary = f"{sign_bit}{exponent:08b}{mantissa:07b}"
    
    return bf16_binary
    
'''def decimal_to_bf16_signed(decimal_number):
    """Converts a decimal number to a binary BF16 signed representation."""
    fp32 = np.float32(decimal_number)
    fp32_bits = struct.unpack('>I', struct.pack('>f', fp32))[0]
    # Shift and mask for BF16: top 16 bits
    bf16_bits = (fp32_bits >> 16) & 0xFFFF
    # Extract the sign, exponent, and mantissa to construct binary BF16 format
    sign_bit = (bf16_bits >> 15) & 0x1
    exponent = (bf16_bits >> 7) & 0xFF  # Next 8 bits
    mantissa = bf16_bits & 0x7F         # Last 7 bits for BF16
    
    # Combine into the final BF16 binary format
    bf16_binary = f"{sign_bit}{exponent:08b}{mantissa:07b}"
    return bf16_binary'''
