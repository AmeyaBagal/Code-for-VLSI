# This file is public domain, it can be freely copied without restrictions.
# SPDX-License-Identifier: CC0-1.0

import os
import random
from pathlib import Path
import numpy as np
import struct

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
from model_mac import *

    
def decimal_to_fp32_signed(decimal_number):
    """Converts a decimal number to a binary FP32 signed representation."""
    fp32 = np.float32(decimal_number)
    # Pack float as bytes in IEEE 754 format and unpack as unsigned int
    fp32_int = struct.unpack('>I', struct.pack('>f', fp32))[0]
    fp32_bits = format(fp32_int, '032b')
    return fp32_bits
    
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
#-----------------------------------------------------------------------------------------------------
#Some test cases to show the extremities of the input values. This will be coupled with random values to show coverage
A = [10.75, 7012876288.0, 46.0, 34340864.0, 15971909632.0, 5120.0, 17582522368.0, 1546188226560.0, 6016.0]
B = [7868380086272.0, 4707284156416.0, 9502720.0, 8053063680.0, 98.5, 704374636544.0, 11403264.0, 0.2314453125, 1294336.0]
C = [25.345001220703125, 3236962500608.0, 159383.5625, 76965814272.0, 415236.125, 244091600896.0, 214748368.0, 805306.375, 4160749.75]
#-----------------------------------------------------------------------------------------------------

@cocotb.test()
async def test_mac(dut):
    """Test to check counter"""

    dut.EN_start.value = 0
 
    clock = Clock(dut.CLK, 10, units="us")  # Create a 10us period clock on port clk
    # Start the clock. Start it low to avoid issues on the first RisingEdge
    cocotb.start_soon(clock.start(start_high=False))
    
    #Reset
    dut.RST_N.value = 0
    await RisingEdge(dut.CLK)
    dut.RST_N.value = 1
    
    #Enable all methods
    dut.EN_start.value = 1
    dut.start_s.value = 1
    dut._log.info('Performing mac_float')
    for i in range(len(A)+3):
        if i < len(A):
            dut.start_a.value = int(decimal_to_bf16_signed(A[i]),2)
            dut.start_b.value = int(decimal_to_bf16_signed(B[i]),2)
            dut.start_c.value = int(decimal_to_fp32_signed(C[i]),2)
        await RisingEdge(dut.CLK)
        if i > 2:
            dut._log.info(f'output {dut.get_result.value}')
            output = model_mac(1, 1, A[i-3], B[i-3], C[i-3])
            assert output[0:30] == str(dut.get_result.value)[0:30], f'MAC Output Mismatch, Expected = {output} DUT = {str(dut.get_result.value)}'
    
        
    dut._log.info("Done!")
    
    coverage_db.export_to_yaml(filename="coverage_mac.yml")

