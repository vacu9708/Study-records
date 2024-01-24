# Von Neumann architecture
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/10b13dcb-dac3-4b09-8272-c935e7354593)

Von Neumann architecture is a computer architecture framework that serves as the foundation for most modern computers.<br>

## Components
#### CPU
The CPU is the brain of the computer, responsible for executing instructions and performing calculations.<br>
It consists of an arithmetic logic unit (ALU) for mathematical and logical operations and a control unit (CU) that manages the instruction execution process, data transfer between memory and CPU, and control flow (branching and jumping).
#### Memory
a single shared memory unit that stores both program instructions and data. This memory is often referred to as RAM (Random Access Memory). It allows the CPU to read and write data and instructions,
#### External mass storage
#### Input and output mechanisms

## Key features
#### Instruction Set
Von Neumann architecture uses a well-defined set of instructions that the CPU can execute. These instructions include arithmetic operations (addition, subtraction, etc.), logical operations (AND, OR, NOT, etc.), data transfer operations (load, store), and control flow operations (branching, jumping).
#### Fetch-Decode-Execute Cycle
The CPU operates in a cycle known as the Fetch-Decode-Execute cycle. In this cycle, the CPU fetches an instruction from memory based on the value in the program counter, decodes the instruction to determine the operation to be performed, and then executes the instruction.
#### Sequential Execution
Von Neumann machines execute instructions sequentially, one after the other. This means that programs are executed step by step, following the order of instructions in memory.
#### Stored Program Concept
One of the key innovations of the Von Neumann architecture is the concept of a "stored program." This means that both program instructions and data are stored in the same memory, and instructions can be treated as data. This flexibility allows the CPU to work with different programs by loading them into memory.<br>
The term "von Neumann architecture" has evolved to refer to any stored-program computer in which an instruction fetch and a data operation cannot occur at the same time (since they share a common bus).<br>
This is referred to as the von Neumann bottleneck, which often limits the performance of the corresponding system.
