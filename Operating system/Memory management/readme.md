# Types of memory fragmentation
### Internal fragmentation
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/a9694841-3cd6-4fff-951f-b6a445b0d724)<br>
When a piece of allocated memory leaves some unused space.<br>
Ex) When a piece memory whose size is 10bytes has 8bytes of data, leaving 2 bytes unused
### External framentation
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/2bf06256-ac2a-4471-91b4-4f371fa8f396)<br>
When memory space between pieces of allocated memory is unavailable.

# Contiguous memory allocation
In **contiguous memory allocation**, the whole process is allocated to a contiguous partition of memory.
## Fixed(or static) partitioning
This is the oldest and simplest. The size of a partition is fixed in RAM when allocated, which can cause big internal fragmentation.

## Variable(or dynamic) partitioning
The partition size varies according to the need of the process, which can cause big external fragmentation.
### Initial memory state
![image](https://user-images.githubusercontent.com/67142421/178162536-1a5042e4-9e23-489b-bd69-88ce7df6dbd3.png)

### First fit
![image](https://user-images.githubusercontent.com/67142421/178162569-8906b416-30f6-4fd2-a24b-36a424388021.png)<br>
The partition is allocated which is first sufficient from the top of memory. The OS doesn’t search for the best partition but just the first partition available with a sufficient size.<br>
* It is fast in processing but can waste a lot of memory.

### Best fit
![image](https://user-images.githubusercontent.com/67142421/178162618-28cc7cab-20f1-4731-b0da-625dfd91d433.png)<br>
The entire list of free partitions is searched and the smallest adequate hole is allocated.
* Slower process than First fit.
* The minimum possible space in the memory is allocated, making memory management efficient. To save memory from getting wasted, it is the best method.

### Worst fit
![image](https://user-images.githubusercontent.com/67142421/178162994-d644b1ff-6a79-4b3c-a1eb-4b96f1020cf8.png)<br>
The entire list of free partitions is searched and the biggest hole possible is allocated.

# Non-contiguous memory allocation
Non-contiguous memory allocation is a method of storing data in multiple memory locations rather than in a single contiguous block.
### Techniques
- Paging: Divides a process's memory space into fixed-size blocks called pages. Each process is divided into pages of the same size, which can be stored anywhere in the physical memory.
- Segmentation: Divides a process's memory space into different segments, where each segment represents a specific type of data or code (e.g., code segment, data segment, stack segment). They can be non-contiguously allocated.
### Advantages
- Helps reduce fragmentation since it minimizes wasted space in memory by effectively utilizing small pockets of available memory.
### Challenges
- More complex memory management.
- Overhead of maintaining page tables or segment tables.

# Virtual memory
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/10b1de02-1f68-431f-b03f-f869be8cffb2)<br>
Virtual memory is a memory management technique that creates an illusion of a very large memory space by using both physical memory (RAM) and a part of secondary storage (like a hard disk).<br>
Virtual memory inherently relies on non-contiguous memory allocation.
### How It Works
The operating system maintains a page table to track which virtual pages are mapped to which physical frames of memory.
When a process accesses data, the virtual memory address is translated to a physical address. If the data is not in RAM, a page fault occurs, and the OS loads the required data from the disk to RAM(page replacement).
### Benefits
- Provides a large address space to processes, irrespective of the actual physical memory available.
### Considerations
- Overhead of page table management.
- Performance can be affected by the paging process, especially if the system frequently accesses data that is not in the main memory (page faults).

## Page replacement
Page replacement refers to a scenario in which a page from the main memory should be replaced by a page from the secondary memory. Page replacement occurs due to page faults.<br>
A Page Fault occurs when a requested page is currently not loaded into the main physical memory.

### page-replacement algorithmss
* **First-In First-Out** : This is the simplest. the oldest page is moved out.
* **Optimal page replacement** : a page that will be used the least is moved out. This reduces page-faults the most theoretically
but it is the problem that such a page is hard to predict.
* **Least-Recently-Used** : exploits the fact that pages that were not used recently have a high probability not to be used constantly.
It reduces page-faults less than the optimal page replacement but is one of the practically best algorithms.
