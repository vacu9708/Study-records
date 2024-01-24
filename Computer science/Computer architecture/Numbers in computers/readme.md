![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/71f0e5a2-b821-4959-94ba-4b104463b3f8)
# Negative Representation in Binary
Negative numbers in binary are represented by calculating the two's complement and using this value as the negative number.<br>
The dictionary definition of two's complement is 'the value obtained by subtracting a number from a larger power of 2, 2^n'.<br>
For example, the two's complement of 011 is the result of subtracting 011 from a larger 2^n, which is 100, resulting in 001.<br>
Simply put, it's 'flipping all 0s and 1s, then adding 1 to this value'.<br>

### Reason for Using Two's Complement
Computers use full adders in their logic circuits to process all operations (there are no subtraction units).<br>
Using the two's complement allows for performing subtraction using addition.<br>
`Example`
The two's complement and ten's complement work in the same way, so using the ten's complement as an example:
**54 - 34**
1. 2's complement of 34 = 100 - 34 = 66
2. 54 + 66 = 120
3. Discard carry → 20

**34 - 54**
1. 10's complement of 54 = 100 - 54 = 46
2. 34 + 46 = 80
3. 2's complement of 80 = 100 - 80 = 20 (attach minus)

# Hexadecimal
Binary numbers are long, so hexadecimal is used to shorten binary numbers.
One hexadecimal character (0-9, A-F) can represent 2^4 numbers, meaning it can represent 4 bits.
`Example`: 1101 0101 → D5

# ✨Fixed point and Floating point
## Fixed point representation
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/153f813c-9b4d-48da-8758-cd4fea293400)<br>
The location for the point to be placed is fixed in advance.
- Advantage : Simple and precise.
- Disadvantage : Too small a range of digits available

## Floating point representation
![image](https://user-images.githubusercontent.com/67142421/177052503-2f8fff7b-28ca-486a-8a13-e2cbf473930a.png)<br>
![image](https://user-images.githubusercontent.com/67142421/177052506-bb3fb3dd-9ddc-4043-9ef8-13158f628f29.png)<br>
The floating point is a trade-off between range and precision, which is used the most.<br>
A floating-point number is represented approximately with a fixed number of significand digits and exponent digits.

* Advantage : A wide range of digits are available.
* Disadvantage : There may be an error in the fractional part.
### Example: 5.125 in a floating-point representation
1. Convert 5.125 to binary<br>
   5 (integer part) = 101 (binary)<br>
   0.125 (fractional part) = 2^-3 = 1/8 = 0.125 = 001 (binary)<br>
   5.125 (decimal) = 101.001 (binary)<br>
2. Normalize the binary representation<br>
   101.001 (binary) = 1.01001 × 2^2<br>
3. 32bit Floating-point representation<br>
   **Sign bit (1 bit)**: 0 (positive number)<br>
   **Exponent (8 bits)**: The exponent is determined by adding the exponent part of the normalized representation and the bias (127)-> 2 + 127 = 129, which is represented as 10000001 in binary.<br>
   **Significand (23 bits)**: The significand is the fractional part -> 01001.

**Result: 0 | 10000001 | 01001000000000000000000**

### 5.125 can be represented precisely without any errors. Why 0.1 is not accurate?
It is because 0.1 becomes a repeating fraction 0.0001100110011001100110011..., which is approximated<br>
