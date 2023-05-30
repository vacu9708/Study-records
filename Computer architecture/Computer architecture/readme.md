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
   0.125 (fractional part) = 001 (binary) 2^-3 = 1/8 = 0.125<br>
   5.125 (decimal) = 101.001 (binary)<br>
2. Normalize the binary representation<br>
   101.001 (binary) = 1.01001 × 2^2<br>
3. 32bit Floating-point representation<br>
   **Sign bit (1 bit)**: 0 (positive number)<br>
   **Exponent (8 bits)**: The exponent is determined by adding the bias (127) to the power of 2 -> 2 + 127 = 129, which is represented as 10000001 in binary.<br>
   **Significand (23 bits)**: The significand is the fractional part -> 01001.

**Result: 0 | 10000001 | 01001000000000000000000**

### 5.125 can be represented precisely without any errors. Why 0.1 is not accurate?
It is because 0.1 becomes a repeating fraction 0.0001100110011001100110011..., which is approximated<br>

---

# ✨Central Processing Unit
A CPU is the brain of a computer that fetches instructions from memory and executes them<br>

**Instruction** : 
>consists of operation code and operand<br>
>operation code : an operation to execute / operand : the object of an operation

A CPU consists of
* **Arithmetuc Logic Unit** that performs arithemetic and logic operations
* **registers** that are the fastest memory of a computer, which supply operands to the ALU and store the results of ALU operations
* a **control unit** that orchestrates the fetching of instructions (from memory) and execution of them

## Special Purpose Registers
* **Instruction Register** : holds the instruction that is currently being executed.
* **Program Counter** : stores the memory address of the next instruction to be fetched.
* **Memory Address Register** : stores the memory address to fetch some data that is required by the current instruction being executed (not an instruction).
* **Memory Buffer Register** : stores a copy of the value in the memory location specified by the memory address register.
* **Accumulator** : intermediate result of arithmetic logic unit is stored
### 32bit VS 64bit computer
A 32-bit computer includes a 32-bit memory address register that can distinguish 2^32 addresses(4GB).
A 64-bit computer includes a 64-bit memory address register that can distinguish 2^64 addresses(almost infinite size).


### CISC (Complex Instruction Set Computer)
A computer in which individual instructions may perform many operations and take many cycles to execute, in contrast with Reduced Instruction Set Computer (**RISC**).

### Fetching cycle
1. The memory address of the instruction is transferred to MAR
2. The instruction located on the address is fetched and stored in MBR
3. The value of PC is increased to fetch the next instruction
4. The instruction stored in MBR is transferred to IR

---

# ✨Cache memory
In computing, a **cache** is a hardware or software component that stores data so that future requests for that data can be served faster.<br>
It is used to decrease the bottleneck between a fast device and a slow device.<br>

## Types of cache memory
Normally a CPU has 3 pieces of cache memory, which are called L1, L2, L3 each in the order of slower speed.<br>
L1 cache is in the CPU and searched first. L2 is between the CPU and RAM. L3 is in main board and the last to be searched.

## Cache memory works based on these principles
* **Temporal locality** : Data that has been referenced is likely to be referenced shortly again.
* **Space locality** : Data next to data that has been referenced is likely to be referenced shortly.

## Cache hit and Cache miss
* On a cache hit : the CPU can quickly retrieve data from the cache.
* A cache miss is an event in which an attempt to retrieve data from a cache, where the CPU has to fetch the data from the main memory to the cache.<br>
* **If cache misses happen too much**, having cache memory is worse than not having it because the time taken to find data in cache memory was wasted.<br>

## Cache placement policies
* **Direct Mapped Cache**

![image](https://user-images.githubusercontent.com/67142421/177051043-23ec7372-938a-4b7c-b317-b7174a99eabd.png)<br>
In this structure multiple addresses of RAM map to a single address in cache memory.<br>
It works the same way as hash table. Therefore, there is a possibility that a collision occurs. (conflict miss)

* **Fully Associative Cache**
A method by which data is stored in any empty location. It is simple when storing, but searching is the problem because the cache has to be searched until sought data is found.

* **Set Associative Cache**
It is a trade-off between direct-mapped cache and fully associative cache. A hybrid cache that combines the associative cache and the direct-mapped cache.<br>
A set-associative cache can be imagined as a (n by m)matrix.<br>
The cache is divided into 'n' rows and each row contains 'm' columns. A memory block in RAM is first mapped onto a row and then placed into any column of a row.

## Cache replacement algorithms:
[It is similar to page replacement algorithms](https://github.com/vacu9708/Fundamental-knowledge/tree/main/Operating%20system/Memory%20management)

---

# ✨System bus
A **system bus** is a pathway that transmits data between the components of hardware that consists of data bus, address bus, control bus

![image](https://user-images.githubusercontent.com/67142421/176787286-3282d915-5840-4a2a-8759-2577fa50ff02.png)

* **data bus** : A pathway that transfers data between the CPU and other components.<br>
It is a bidirectional bus that either transfers the data and instructions of memory and I/O devices to the CPU or transfers the operation results of the CPU to memory and I/O devices
* **address bus** : In order to carry data to an exact location, the address of the location has to be set.<br>
The address bus is a pathway where the CPU transmits memory address to memory or I/O devices, so it is called "unidirectional bus".<br>
If there are 16 address buses, 2^16=65536 addresses can be distinguished.
* **control bus** : A control bus is a pathway where the CPU transmits control signals to memory or I/O devices.
