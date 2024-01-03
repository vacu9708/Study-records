# Contiguous memory allocation
In **contiguous memory allocation**, the whole process is allocated to a contiguous partition of memory.

### Initial memory state
![image](https://user-images.githubusercontent.com/67142421/178162536-1a5042e4-9e23-489b-bd69-88ce7df6dbd3.png)

### First fit
![image](https://user-images.githubusercontent.com/67142421/178162569-8906b416-30f6-4fd2-a24b-36a424388021.png)<br>
The partition is allocated to the first sufficiently large space from the top of memory. The OS searches for the first available partition with a sufficient size.
- Fast in processing but can waste a lot of memory.

### Best fit
![image](https://user-images.githubusercontent.com/67142421/178162618-28cc7cab-20f1-4731-b0da-625dfd91d433.png)<br>
The entire list of free partitions is searched through to find the smallest hole that is adequately large.
- By allocating the smallest adequate hole, it minimizes wasted space in memory. This makes it an effective method for saving memory and reducing fragmentation, particularly in scenarios where numerous small allocations are made.
- Slower than First fit.

### Worst fit
![image](https://user-images.githubusercontent.com/67142421/178162994-d644b1ff-6a79-4b3c-a1eb-4b96f1020cf8.png)<br>
The entire list of free partitions is searched and the biggest hole possible is allocated.


# Swapping
Swapping refers to the process of temporarily moving processes that are not currently being executed out of the memory to a secondary storage device. This technique is used to free up space in the limited memory. By using swapping, the effectively available memory space can be increased.
- Swap Space: This is the area on a secondary storage device where processes are temporarily stored. Swap space acts as an extension of the system's physical memory, allowing for more processes to be loaded than would otherwise fit into the physical RAM.
- Swap-Out: This process involves moving a process from the main memory to the swap space. Swap-out is typically performed when the system needs to free up RAM for other processes or when the system determines that a process is idle or less critical.
- Swap-In: Conversely, swap-in is the process of moving a process back from the swap space into the main memory. This occurs when the process is needed for execution. The system will then allocate space in the physical memory for the process and reload it from the swap space.

# Non-contiguous memory allocation
Non-contiguous memory allocation is a method of storing data in multiple memory locations rather than in a single contiguous block.
### Techniques
- Paging(majority): Divides a process's memory space into fixed-size blocks called pages. Each process is divided into pages of the same size, which can be stored anywhere in the physical memory.
- Segmentation(unusual): Divides a process's memory space into different segments, where each segment represents a specific type of data or code (e.g., code segment, data segment, stack segment). They can be non-contiguously allocated.
### Advantages
- Helps reduce fragmentation since it minimizes wasted space in memory by effectively utilizing small pockets of available memory.
### Challenges
- More complex memory management.
- Overhead of maintaining page tables or segment tables.
- 
## Paging
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/c8375793-7802-4df8-bdd2-dbeee33c29e5)

### Internal fragmentation
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/a9694841-3cd6-4fff-951f-b6a445b0d724)<br>
When a piece of allocated memory leaves some unused space.<br>
For example, when a piece memory whose size is 10bytes has 8bytes of data, leaving 2 bytes unused

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

# Page replacement (swapping in the paging system)
Page replacement refers to a scenario in which a page from the main memory should be replaced by a page from the secondary memory. Page replacement occurs due to page faults.<br>
A Page Fault occurs when a requested page is currently not loaded into the main physical memory.

### page-replacement algorithmss
* **First-In First-Out** : This is the simplest. the oldest page is moved out.
* **Optimal page replacement** : a page that will be used the least is moved out. This reduces page-faults the most theoretically
but it is the problem that such a page is hard to predict.
* **Least-Recently-Used** : exploits the fact that pages that were not used recently have a high probability not to be used constantly.
It reduces page-faults less than the optimal page replacement but is one of the practically best algorithms.
