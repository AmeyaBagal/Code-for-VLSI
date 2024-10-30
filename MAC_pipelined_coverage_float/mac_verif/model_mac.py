# model for increment alone

import cocotb
from cocotb_coverage.coverage import *
import numpy as np
import struct

mac_coverage = coverage_section(
    CoverPoint('top.get_inputs_s', vname='get_inputs_s', bins = list(range(0,1))),
    CoverPoint('top.get_inputs_a', vname='get_inputs_a', bins = [10.75, 7012876288.0, 46.0, 34340864.0, 15971909632.0, 5120.0, 17582522368.0, 1546188226560.0, 9371648.0, 6016.0]),
    CoverPoint('top.get_inputs_b', vname='get_inputs_b', bins = [7868380086272.0, 4707284156416.0, 9502720.0, 8053063680.0, 98.5, 704374636544.0, 11403264.0, 0.2314453125, 49.25, 1294336.0]),
    CoverPoint('top.get_inputs_c', vname='get_inputs_c', bins = [25.345001220703125, 3236962500608.0, 159383.5625, 76965814272.0, 415236.125, 244091600896.0, 214748368.0, 805306.375, 206158432.0, 4160749.75]),
    CoverPoint('top.EN_get_inputs', vname='EN_get_inputs', bins = list(range(0,2))),
    CoverCross('top.cross_cover', items = ['top.get_inputs_s', 'top.get_inputs_a', 'top.get_inputs_b', 'top.get_inputs_c', 'top.EN_get_inputs'])
)
@mac_coverage
def model_mac(EN_get_inputs: int, get_inputs_s: int, get_inputs_a: int, get_inputs_b: int, get_inputs_c: int) -> str:
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
    fp32_int = struct.unpack('>I', struct.pack('>f', fp32))[0]
    fp32_bits = format(fp32_int, '032b')
    return fp32_bits

def bf16_to_decimal(bf16_binary):
    """Converts a BF16 binary string to a decimal number."""
    # Ensure the input is 16 bits long
    if len(bf16_binary) != 16:
        raise ValueError("Not BF16 Type")
    
    # Extract the sign, exponent, and mantissa from the binary string
    sign = int(bf16_binary[0], 2)
    exp = int(bf16_binary[1:9], 2)
    mant = int(bf16_binary[9:], 2)
   
    fp32_bits = (sign << 31) | (exp << 23) | (mant << 16)

    # Convert the 32-bit integer back to a float
    fp32_bytes = struct.pack('>I', fp32_bits)
    decimal = struct.unpack('>f', fp32_bytes)[0]
    
    return decimal

def decimal_to_bf16_signed(decimal):
    """Converts a decimal number to a binary BF16 signed representation with rounding."""
    # Convert the decimal number to 32-bit IEEE 754 float
    fp32 = np.float32(decimal)
    
    # Pack the float into bytes and unpack it as an unsigned 32-bit integer
    fp32_int = struct.unpack('>I', struct.pack('>f', fp32))[0]
    # Extract the top 16 bits (candidate BF16 bits) and the lower 16 bits
    fp16_bits = (fp32_int >> 16) & 0xFFFF
    discard_bits = fp32_int & 0xFFFF  # Remaining bits after the top 16
    
    # Rounding off checking
    if (discard_bits == 0x8000 and (fp16_bits & 1) == 1) or discard_bits > 0x8000:
        fp16_bits +=1

    # Extract the sign, exponent, and mantissa from the (possibly rounded) BF16 bits
    sign = (fp16_bits >> 15) & 0x1            # 1 bit
    exp = (fp16_bits >> 7) & 0xFF            # 8 bits
    mant = fp16_bits & 0x7F                   # 7 bits

    # Construct the final BF16 binary representation as a string
    bf16_bits = f"{sign}{exp:08b}{mant:07b}"
    
    return bf16_bits
