# ✨Central Processing Unit
A CPU is the brain of a computer that fetches instructions from memory and executes them<br>

### Instruction
consists of operation code and operand<br>
- `operation code`: an operation to execute
- `operand`: the object of an operation

## A CPU consists of
- ### Arithmetuc Logic Unit
performs arithemetic and logic operations
- ### Registers
are the fastest memory of a computer, which supply operands to the ALU and store the results of ALU operations
- ### Control unit
- `Execution of insturction`: The CU fetches, decodes, and execute instructions.
- `Directing Operations`: Once the instructions are decoded, the Control Unit sends control signals to the relevant parts of the computer to execute the operations.
- `Data Flow Management`: It controls the flow of data within the CPU and between the CPU and other components of the computer. This includes managing data transfers to and from the memory, ALU, and input/output devices.

## Special Purpose Registers
* **Instruction Register** : holds the instruction that is currently being executed.
* **Program Counter(Instruction pointer)** : stores the memory address of the next instruction to be fetched.
* **Memory Address Register** : stores the memory address to fetch some data that is required by the current instruction being executed (not an instruction).
* **Memory Buffer Register** : stores a copy of the value in the memory location specified by the memory address register.
* **Accumulator** : intermediate result of arithmetic logic unit is stored
### 32bit VS 64bit computer
A 32-bit computer includes a 32-bit memory address register that can distinguish 2^32 addresses(4GB).
A 64-bit computer includes a 64-bit memory address register that can distinguish 2^64 addresses(almost infinite size).

## CISC (Complex Instruction Set Computer)
In a CISC architecture, instructions can vary in length, with some instructions being quite complex and encoding multiple operations within a single instruction.<br>
This flexibility allows for more powerful instructions but can make instruction decoding and pipelining more challenging.<br>
## RISC (Reduced Instruction Set Computer)
RISC architectures have fixed-length instructions and aim for simplicity and uniformity in their instruction encoding.

### Fetching cycle
1. The memory address of the instruction is transferred to MAR
2. The instruction located on the address is fetched and stored in MBR
3. The value of PC is increased to fetch the next instruction
4. The instruction stored in MBR is transferred to IR
