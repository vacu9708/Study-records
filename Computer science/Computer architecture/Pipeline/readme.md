![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/bf4ee443-c3ad-4599-8bdd-fe7a80d6303e)

In computer architecture, a pipeline is a technique used to improve the throughput and efficiency of a CPU (Central Processing Unit) by breaking down the instruction execution process into a series of stages, with each stage performing a specific operation on the instruction.<br>
This allows multiple instructions to be processed simultaneously, overlapping the execution of different instructions to achieve higher performance. The pipeline concept is commonly used in modern CPUs to make better use of available resources.

## Pipeline stages:
1. Instruction Fetch (IF): In this stage, the CPU fetches the next instruction from memory based on the program counter (PC) and loads it into a special instruction register.
2. Instruction Decode (ID): Here, the CPU decodes the fetched instruction to determine the operation to be performed and identifies the source and destination operands.
3. Execute (EX): In this stage, the CPU performs the actual computation or operation specified by the instruction. For example, if the instruction is an arithmetic operation, this stage would perform the addition or subtraction.
4. Memory Access (MEM) if needed: If the instruction involves accessing memory (e.g., loading data from or storing data to memory), this stage handles those memory transactions.
5. Write Back (WB) if needed: In the final stage, the CPU writes the results of the instruction execution back to the appropriate registers or memory locations.

### Why the pipeline is necessary
The CPU can execute different stages of multiple instructions simultaneously.<br>
This overlap of operations results in increased throughput and improved performance.<br>
For example, while one instruction is being executed, the CPU can fetch the next instruction, and while that instruction is being executed, the CPU can decode the following one, and so on.<br>
**Without the pipeline**, the CPU can't start the next instruction until the previous one has completed all stages.<br>
This can lead to significant idle time for the CPU, where it is not doing any useful work while waiting for the current instruction to finish.

## Pipeline hazards
Pipeline hazards are a concern in pipelined architectures, as they can lead to stalls or delays in instruction processing.<br>
These hazards include:
- Structural Hazards: These occur when multiple pipeline stages need access to the same hardware resource simultaneously. For example, if two instructions need to access the same memory unit, a structural hazard can occur, leading to a stall.
- Data Hazards: Data hazards occur when an instruction depends on the result of a previous instruction that is still in an earlier stage of the pipeline. These dependencies can cause pipeline stalls or the need for forwarding mechanisms to resolve them.
- Control Hazards: Control hazards arise due to conditional branches or jumps in the program. When a branch instruction is encountered, the pipeline may need to be flushed (discarding instructions in later stages) if the branch is taken. Techniques like branch prediction are used to mitigate control hazards.

Modern CPUs employ various strategies to mitigate these hazards and improve pipeline efficiency, such as out-of-order execution, speculative execution, and advanced branch prediction techniques.<br>
These techniques aim to keep the pipeline filled with instructions and minimize stalls, ultimately enhancing the CPU's overall performance.

## Out-of-Order Execution (Async)
In an in-order execution, instructions are processed sequentially the entire pipeline might stall until the hazard is resolved (e.g., waiting for data to be fetched from memory).<br>
Out-of-order execution minimizes these stalls by finding and executing other independent instructions in the meantime.
### Example
1. add a, 1
2. add b, a
3. add c, b
4. 5, 6, 7., and so on

In this case, the third instruction must wait until the first and second are completed.<br>
Out-of-order execution is used to process subsequent instructions that do not depend on the third instruction earlier while waiting for it. This prevents the pipeline from stalling.<br>
**Compiler optimization** rearranges the instructions

## Fetching cycle
1. The memory address of the instruction is transferred to MAR
2. The instruction located on the address is fetched and stored in MBR
3. The value of PC is increased to fetch the next instruction
4. The instruction stored in MBR is transferred to IR
