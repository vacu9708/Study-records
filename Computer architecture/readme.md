# Central Processing Unit
A CPU is the brain of a computer that fetches instructions from memory and executes them<br>

**Instruction** : 
>consists of operation code and operand<br>
>operation code : an operation to execute / operand : the object of an operation

A CPU consists of
* **Arithmetuc Logic Unit** that performs arithemetic and logic operations
* **registers** that are the fastest memory of a computer, which supply operands to the ALU and store the results of ALU operations
* a **control unit** that orchestrates the fetching of instructions (from memory) and execution of them

### Special Purpose Register
* **Memory Address Register** : stores the memory address where reading and writing operations will be performed
* **Program Counter** : a register that stores the memory address of the instruction to be executed next.
* **Instruction Register** : holds a machine instruction that is currently being executed.
* **Memory Buffer Register** : stores data that will be used in the next clock
* **Accumulator** : intermediate arithmetic logic unit results are stored

**CISC** : A computer in which individual instructions may perform many operations and take many cycles to execute, in contrast with reduced instruction set computer (**RISC**).

### Fetching cycle
1. The memory address of the instruction is transferred to MAR
2. The instruction located on the address is fetched and stored in MBR
3. The value of PC is increased to fetch the next instruction
4. The instruction stored in MBR is transferred to IR
---
# System bus
A **system bus** is a pathway that transmits data between the components of hardware that consists of data bus, address bus, control bus

![image](https://user-images.githubusercontent.com/67142421/176787286-3282d915-5840-4a2a-8759-2577fa50ff02.png)

* **data bus** : A pathway that transfers data between the CPU and other components.<br>
It is a bidirectional bus that either transfers the data and instructions of memory and I/O devices to the CPU or transfers the operation results of the CPU to memory and I/O devices
* **address bus** : In order to carry data to an exact location, the address of the location has to be set.<br>
The address bus is a pathway where the CPU transmits memory address to memory or I/O devices, so it is called "unidirectional bus".<br>
If there are 16 address buses, 2^16=65536 addresses can be distinguished.
* **control bus** : A control bus is a pathway where the CPU transmits control signals to memory or I/O devices.
---
# Cache memory
In computing, a **cache** is a hardware or software component that stores data so that future requests for that data can be served faster.<br>
It is used to decrease the bottleneck between a fast device and a slow device.

