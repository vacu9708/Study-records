# Programmers' Model

## Data Types
- **Byte (8 bits):** Smallest data type.
- **Halfword (16 bits):** Introduced in ARM version 4.
- **Word (32 bits):** Main data type for operations.
- **Support for Unaligned Data:** ARMv6 introduced unaligned data support for words and halfwords.
- **Signed and Unsigned Types:** Represent integers using normal binary format or two's complement format.

## Processor Modes
![image](https://github.com/vacu9708/Embedded-system/assets/67142421/f5629faf-1c3b-4986-9b55-c75fdfc76cc1)<br>
- **Mode changes**: Can be made under software control, or can be caused by external interrupts or exceptions.<br>
- **User mode**: Most application programs run in User mode, which cannot access protected system resources or to change mode, other than triggering an exception.<br>
- **Privileged modes**: The modes other than User mode are known as privileged modes. They have full access to system resources and can change mode freely.<br>
Five of them are known as exception modes: FIQ, IRQ, Supervisor, Abort, Undefined. These are entered when specific exceptions occur. Each of them has some additional registers to avoid
corrupting User mode state when the exception occurs.
- **System mode**: System mode is one of the privileged modes, and it shares the same register set as the User mode. It has full access to the system's privileged resources.

Switching between these modes is generally controlled by the ARM processor itself in response to certain events (like interrupts). However, software can also change modes explicitly, usually done by system-level code. This is achieved by modifying specific bits in the CPSR.
### Exception level
![image](https://github.com/vacu9708/Embedded-system/assets/67142421/7f28fbca-f3d2-4a1e-a5e2-50d572e5f3df)<br>
Exception Levels (ELs): ARMv8 replaces the above modes with a hierarchy of exception levels:
- **EL0**: The least privileged level, typically for application code (similar to User mode in ARMv7).
- **EL1**: For operating system kernel code, similar to the Supervisor mode.
- **EL2**: A new level, typically used by hypervisors in virtualized environments.
- **EL3**: The most privileged level, used for secure boot and trusted execution environments, like TrustZone.

## Registers
![image](https://github.com/vacu9708/Embedded-system/assets/67142421/c4274b11-1a5f-4e1d-bbe9-49a0cfdbf5b2)<br>
- Total of 37 registers(Sum of the registers in the picture above is 37)
  - 31 general-purpose 32-bit registers, including a program counter. R0 ~ R15 visible at any time. (The PC is no longer treated as a general-purpose register in ARMv8 or later)
  - 6 status registers
### General-purpose registers
- **Unbanked Registers (R0 to R7 and R15)**: Each of them refers to the same 32-bit physical register in all processor modes. They are completely general-purpose registers, with no special uses implied by the architecture
- **Banked Registers (R8 to R14)**: Different physical registers depending on the processor mode. A specific name is used to point to a particular physical register.
  - Almost all instructions allow the banked registers to be used wherever a general-purpose register is allowed.
  - Some of the banked registers are unique to the mode, while others are shared (or overlapped) with other modes:<br>
    - Registers R8 to R12 have two banked physical registers each. One is used in all processor modes other than FIQ mode, and the other is used in FIQ mode.<br>
    - Registers R13 and R14 have six banked physical registers each. One is used in User and System modes, and each of the remaining five is used in one of the five exception modes. 
### Special Uses of these registers
- R13 (Stack Pointer): Used for stack operations.
- R14 (Link Register): Holds return address after a subroutine call. This is more efficient than using a call stack for every function call, which INTEL uses.
- R15 (Program Counter)(deprecated): R15 can be used in place of other general-purpose registers for certain special-case effects.<br>
By default, R15 operates as a program counter, used for storing the address of the next's next instruction. Storing the next's next instruction is due to the pipeline, where instructions are pre-fetched.<br>

## Program Status Registers
- **Current Program Status Register(CPSR)**: Holds processor status, condition code flags, interrupt disable bits, processor mode, etc.
- **Saved Program Status Register(SPSR)**: Holds the CPSR of the task before an exception occurred. Each exception mode has a SPSR.

![image](https://github.com/vacu9708/Embedded-system/assets/67142421/a8d11d29-e894-4dab-aa30-fa40bdaacdd0)
### Types of PSR bits
![image](https://github.com/vacu9708/Embedded-system/assets/67142421/62c15732-41b0-4431-8a3c-22fc6feb9cb8)<br>
`Permissions`<br>
- **Reserved bits**: Reserved for future expansion. Implementations must read these bits as 0 and ignore writes to them.
- **User-writable bits(N, Z, C, V, Q, GE[3:0], E)**: Can be written from any mode.
- **Privileged bits(A, I, F, and M[4:0])**: Can be written from any privileged mode. Writes to privileged bits in User mode are ignored.
- **Execution state bits(J, T)**: Can be written from any privileged mode. Writes to execution state bits in User mode are ignored.
### The condition code flags
The N, Z, C, and V (Negative, Zero, Carry and oVerflow) bits are collectively known as the condition code flags, often referred to as flags.
- The condition code flags in the CPSR can be tested by most instructions to determine whether the instruction is to be executed.(if else)
- They are usually modified by the execution of some arithmetic, logical, move instruction, or comparison instruction (CMN, CMP, TEQ or TST).
### The Q flag
bit[27] of the CPSR is known as the Q flag and is used to indicate whether overflow and/or saturation has occurred in some DSP-oriented instructions.<br>
### The GE[3:0] bits
The SIMD instructions use bits[19:16] as Greater than or Equal (GE) flags for individual bytes or halfwords of the result.<br>
You can use these flags to control a later SEL instruction<br>
### The E bit
Controls load and store endianness for data handling.<br>
### The interrupt disable bits
- **A bit**: Disables imprecise data aborts when it is set. This is available only in ARMv6 and above. In earlier versions, bit[8] of CPSR and SPSRs must be treated as a reserved bit, as described in Types of PSR bits on page A2-11.
I bit Disables IRQ interrupts when it is set.
F bit Disables FIQ interrupts when it is set.
### The mode bits
M[4:0] are the mode bits. These determine the mode in which the processor operates.<br>
![image](https://github.com/vacu9708/Embedded-system/assets/67142421/c8ce20f3-44b9-4d2f-8eb8-646f2ba047a4)<br>
### The T and J bits
The T and J bits select the current instruction set, as shown in Table A2-3.<br>
![image](https://github.com/vacu9708/Embedded-system/assets/67142421/c46e77e9-2693-4351-b576-62c73d8edc3a)
### Other bits
Other bits in the program status registers are reserved for future expansion.<br>
In general, programmers must take care to write code in such a way that these bits are never modified. Failure to do this might result in code that has unexpected side effects on future versions of the architecture.

## Exceptions
Exceptions are generated by internal and external sources to cause the processor to handle an event, such as an externally generated interrupt.<br>
More than one exception can arise at the same time.<br>
All exception modes have replacement banked registers. When an exception occurs, standard registers are replaced with registers specific to the exception mode.
### Exception process
- When an exception occurs, execution is forced from a fixed memory address corresponding to the type of exception. These fixed addresses are called the **exception vectors**. There is a separate vector location for each exception.
- The banked versions of R14 and the SPSR are used to save state so that the original program can be resumed when the exception routine has completed.
- To return after handling the exception, the SPSR is moved into the CPSR, and R14 is moved to the PC.
### Types of exceptions
The ARM architecture supports seven types of exception. Table A2-4 lists the types of exception and the processor mode that is used to process each type.<br>
![image](https://github.com/vacu9708/Embedded-system/assets/67142421/8f983210-851f-4d21-abf1-833acaa9c486)<br>
#### Reset
When the Reset input is asserted on the processor, the ARM processor immediately stops execution of the current instruction.
#### Undefined Instruction exception
Occurs when the processor encounters an instruction that is either **not defined** in the ARM instruction set or is **not valid** for the current state of the processor
#### Software Interrupt exception
The Software Interrupt instruction (SWI) enters Supervisor mode to request a particular supervisor function.(OS system call)
#### Prefetch Abort (Instruction fetch memory abort)
- **Precondition to occur**: A memory abort is signaled by the memory system. Attempting to fetch an instruction from a memory location that it cannot access correctly marks the data as invalid.
- **Occurs when**: A Prefetch Abort exception is generated if the processor tries to execute the invalid instruction.
- **Does not occur when**: If the instruction is not executed (for example, as a result of a branch being taken while it is in the pipeline), no Prefetch Abort occurs.
#### Data Abort (Data access memory abort)
A data abort occurs when a problem arises during a data access operation, such as reading from or writing to memory.
#### Interrupt request (IRQ) exception
The IRQ exception is generated externally by asserting the IRQ input on the processor.
#### Fast interrupt request (FIQ) exception
The FIQ exception is generated externally by asserting the FIQ input on the processor.<br>
FIQ is designed to support a data transfer or channel process.<br>
- `Why fast interrupt is faster`
  - **Dedicated Registers:**: FIQ has additional banked registers(private) to remove the need for register saving in such applications, therefore minimizing the overhead of context switching.
  - **Shorter vector**: There are fewer instructions to process before the ISR code is reached.
  - **Higher Priority**: FIQ has a higher priority than IRQ 
### Exception priorities
![image](https://github.com/vacu9708/Embedded-system/assets/67142421/8a47a1ec-e28e-4cf5-b4a9-087883a2e507)

## Endian
Endianness is the order of bytes of digital data.<br>
ARMv6 supports both big-endian and little-endian operation<br>
(Least Significant bit: the bit that has the lowest value)
- In little-endian mode, the least significant bit is stored at the smallest address. (most common)
- In big-endian mode, the most significant bit is stored at the smallest address.

![image](https://github.com/vacu9708/Embedded-system/assets/67142421/a8bf33ea-c471-40fc-b048-ab2c0b6592bf)

## Unaligned access support
- **Aligned Access**: An access is aligned if the memory address being accessed is a multiple of the size of the data type. For example, accessing a 4-byte integer at memory addresses 0, 4, 8, etc., is considered aligned.<br>
Aligned memory accesses are typically faster because they align with the natural boundaries of memory buses and caches.
- **Unaligned Access**: An access is unaligned if the memory address is not a multiple of the size of the data type. For instance, accessing a 4-byte integer at memory addresses 2, 6, 10, etc., would be unaligned.
#### Changes with ARMv6:
Traditionally, ARM expects memory accesses to be aligned.<br>
ARMv6 introduced support for unaligned word and halfword data access.

## Synchronization primitives
#### LDREX (Load-Exclusive)
- When a thread executes an LDREX instruction, it reads data from a memory location and the processor marks this location as having been accessed exclusively by this thread.
- However, this 'exclusive' mark doesn't block other threads or cores from accessing the same memory location. They can still read from and write to this location.
#### STREX (Store-Exclusive)
- STREX checks if the memory location still has its exclusive access status. If no other thread has written to this location since the LDREX was executed, STREX considers the operation successful and writes the new value.
- If, however, another thread has written to the location, the STREX operation will fail, returning a non-zero value.
#### Typical Usage in a Loop:
In practice, the thread often repeatedly reads (LDREX) and tries to write (STREX) in a loop until STREX reports success (indicating no other writes occurred in the meantime).

## Jazelle extension
- **Background**: Jazelle was introduced to mitigate the overheads of JVM by allowing for the native execution of Java bytecode.
- **Operation**: When in Jazelle mode, the processor can directly execute Java bytecode instructions. This is achieved by mapping Java bytecodes to equivalent ARM processor instructions or sequences of instructions.
- **Decline of Jazelle**: The advancements in JIT have largely overshadowed the need for direct bytecode execution.

## Saturated integer arithmetic
Saturated arithmetic prevents the overflow/underflow. Instead, if an operation results in a value outside the representable range, it is set to the closest representable value (the maximum or minimum value of the data type).
- **For instance**, in 8-bit saturated arithmetic, if adding two numbers results in a value greater than 255, the result is set to 255. Similarly, if subtraction would result in a negative value, the result is set to 0.
