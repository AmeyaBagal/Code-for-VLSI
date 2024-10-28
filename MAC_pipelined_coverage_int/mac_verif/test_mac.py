import os
import random
from pathlib import Path

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
from model_mac import *

A_options = list(range(-16,16)) + [127, -128]
B_options = list(range(-16,16)) + [127, -128]
C_options = list(range(-16,16)) + [2147483647, -2147483648]

A = []
B = []
C = []

for a, b, c in itertools.product(A_options, B_options, C_options):
    # Check if A * B + C is within the range of 32-bit signed integers
    result = a * b + c
    if -2147483648 <= result <= 2147483647:
        A.append(a)
        B.append(b)
        C.append(c)

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
    dut._log.info('Performing mac_int')
    for i in range(len(A)):
        dut.start_a.value = A[i]
        dut.start_b.value = B[i]
        dut.start_c.value = C[i]
        await RisingEdge(dut.CLK)
        await RisingEdge(dut.CLK)
        await RisingEdge(dut.CLK)
        await RisingEdge(dut.CLK)
        dut._log.info(f'output {dut.get_result.value}')
        output = model_mac(1, 0, A[i], B[i], C[i])
        assert output == str(dut.get_result.value), f'MAC Output Mismatch, Expected = {output} DUT = {str(dut.get_result.value)}'
        
    dut._log.info("Done!")
    
    coverage_db.export_to_yaml(filename="coverage_mac.yml")
