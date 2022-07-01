### Central Processing Unit
It is the brain of a computer that fetches instructions from memory and executes them<br>

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
