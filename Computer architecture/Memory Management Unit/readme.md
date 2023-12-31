# Memory Management Unit
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/2d9eaa20-c99b-4dec-a5e3-9a2fc480aaf2)<br>
The MMU, or Memory Management Unit is primarily responsible for handling memory access and management.<br>
The MMU is crucial in managing the virtual memory system where both RAM and a portion of the secondary memory are used to create the illusion of a very large memory space.<br>

- ### Memory Translation
The MMU translates virtual memory addresses into physical memory addresses using the **Base register**. When a program accesses a memory location, it uses a virtual address, which the MMU maps to the actual physical address in RAM.
- ### Memory Protection
By managing access to memory, the MMU helps ensure that each program operates within its allocated space using the **Limit register**. This prevents one program from accidentally or maliciously modifying the memory used by another program, enhancing system stability and security.
- ### Paging and Swapping
The MMU facilitates paging, a process where sections of memory (pages) are moved between physical RAM and secondary memory to optimize available RAM usage. When a page is not in physical memory, the MMU can trigger a page fault, leading to page swapping where required data is loaded into RAM from secondary storage.
