# Assignment 1:

1. int32 :
a. pipelined design: code - completed, verification - completed
b. unpipeined design : code - completed, verification - completed

2. bfloat16:
a. pipelined design: code - completed, verification - completed
b. unpipeined design : code - completed, verification - completed

# Assignment 2:

int32: code - completed, verification - not-completed
bfloat16: code - completed, verification - not-completed
# Multiply-Accumulate (MAC) Module

## Overview

This module implements a Multiply-Accumulate (MAC) operation based on the following formula:

\[
MAC = A * B + C
\]

The MAC operation is a fundamental component in digital signal processing, machine learning, and numerical computation tasks. This module provides two operational modes with different input types and output formats to handle both integer and floating-point data.

## File Structure
1. **MAC_int32**
   -This file is an implemenetation we did for the MAC unit for int32 operation with a six stage pipeline. We have not used it in our final code.
2. **MAC_pipelined**
   -Pipelined MAC unit
3. **MAC_pipelined_coverage_float**
   -Coverage for pipelined MAC unit for bf16 inputs
4. **MAC_pipelined_coverage_int**
   -Coverage for pipelined MAC unit for int8 inputs
5. **MAC_unpipelined**
   -Unipelined MAC unit
6. **MAC_unpipelined_coverage_float**
   -Coverage for unpipelined MAC unit for bf16 inputs
7. **MAC_unpipelined_coverage_int**
   -Coverage for unpipelined MAC unit for int8 inputs
8. **Project2**
   -Systolic Array Multiplier for project 2

## Supported Input and Output Formats

The module accepts inputs in two distinct forms:

1. **Integer Mode (S1)**
   - **Inputs:** 
     - `A`: 8-bit signed integer (`int8`)
     - `B`: 8-bit signed integer (`int8`)
     - `C`: 32-bit signed integer (`int32`)
   - **Output:**
     - `MAC`: 32-bit signed integer (`int32`)

2. **Floating-Point Mode (S2)**
   - **Inputs:** 
     - `A`: 16-bit brain floating-point (`bf16`)
     - `B`: 16-bit brain floating-point (`bf16`)
     - `C`: 32-bit single-precision floating-point (`fp32`)
   - **Output:**
     - `MAC`: 32-bit single-precision floating-point (`fp32`)
     
## Data Type Specifications

### bf16 (Brain Floating Point 16)
- **Total Bits**: 16
- **Sign Bit**: 1 bit
- **Exponent**: 8 bits
- **Mantissa**: 7 bits (with an implicit leading 1)

The **bf16** format is a reduced-precision version of **fp32** (standard single-precision floating point). It uses fewer bits in the mantissa, which can reduce computational requirements and memory usage, but at the cost of precision in fractional parts.

### fp32 (Floating Point 32)
- **Total Bits**: 32
- **Sign Bit**: 1 bit
- **Exponent**: 8 bits
- **Mantissa**: 23 bits (with an implicit leading 1)

The **fp32** format is the standard IEEE 754 single-precision floating point format, which provides a wide range and greater precision compared to **bf16**, making it suitable for accumulative operations where higher accuracy is needed.

## Overview of Calculation Flow

1. **Multiplication**: The `bf16` values **A** and **B** are multiplied. 
2. **Conversion to fp32**: The result of `A * B` is then converted to `fp32` by extending the mantissa.
3. **Accumulation**: This `fp32` result is added to operand **C** (already in `fp32` format), giving the final MAC output in `fp32` format.

## Multiplication of bf16 Types

When performing multiplication between two `bf16` values, **A** and **B**, the process involves aligning the formats and converting them to achieve an accurate result within the constraints of reduced-precision `bf16`.

### Steps in bf16 Multiplication

1. **Extract Fields**: 
   - Each `bf16` operand has three components:
     - **Sign Bit** (1 bit)
     - **Exponent** (8 bits)
     - **Mantissa** (7 bits, with an implicit leading 1)

2. **Multiply the Mantissas**:
   - The mantissas of **A** and **B** are multiplied. Since `bf16` has only 7 mantissa bits, this multiplication can produce up to a 14-bit result. This intermediate product is temporarily in higher precision to capture more significant bits.

3. **Add the Exponents**:
   - The exponents of **A** and **B** are added together, and a bias (127 for IEEE 754 formats) is subtracted to maintain the proper range in `fp32` or `bf16` representation.

4. **Determine the Sign Bit**:
   - The result's sign is determined by XOR’ing the sign bits of **A** and **B**.

5. **Normalize the Result**:
   - If the mantissa product exceeds 7 bits, the result is normalized by shifting and adjusting the exponent accordingly to fit within the `bf16` format.

6. **Round to Nearest**:
   - To keep the precision within `bf16` limits, the result is rounded to the nearest `bf16` format, typically by truncating the excess bits in the mantissa and adjusting based on the discarded bits.

7. **Conversion to fp32**:
   - After obtaining the `bf16` multiplication result, it is converted to `fp32` by extending the mantissa to 23 bits (with trailing zeros) and retaining the sign and exponent fields, making it ready for further operations in `fp32`.

## Addition of fp32 Types

Once the `bf16` multiplication result is converted to `fp32`, it is added to the operand **C**, which is already in `fp32` format. The `fp32` addition process follows these steps to ensure precision:

### Steps in fp32 Addition

1. **Align Exponents**:
   - Identify the exponents of both `fp32` operands (the converted result from `bf16` multiplication and **C**).
   - Shift the mantissa of the operand with the smaller exponent to the right, aligning it with the larger exponent. This ensures the numbers are in the same scale for addition, though some precision may be lost due to the shift.

2. **Add the Mantissas**:
   - After alignment, the mantissas of both operands are added (or subtracted, if the signs differ).
   - The sum may temporarily exceed 23 bits due to the added precision.

3. **Normalize the Result**:
   - If the mantissa sum exceeds the 23-bit limit, it is normalized by shifting right and incrementing the exponent. This step ensures the result fits within the `fp32` format.

4. **Handle Overflow/Underflow**:
   - If the exponent exceeds the maximum allowable range, overflow occurs, resulting in an `Inf` or `NaN` value.
   - Conversely, if the exponent falls below the minimum range, underflow occurs, producing a result close to zero.

5. **Round the Result**:
   - The final mantissa is rounded to the nearest representable value in `fp32`, keeping accuracy within the 23-bit mantissa.

6. **Combine the Components**:
   - The final result combines the sign, normalized exponent, and rounded mantissa, yielding a 32-bit floating-point output in `fp32` format.

### Final Result

After following these steps, the addition process results in a final `fp32` value, representing the accurate MAC operation output. This high precision output, despite the initial `bf16` inputs.

