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

## External fragmentation
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/e9e23404-8cb5-4cd3-b53e-3fd579f5489e)<br>
Contiguous memory allocation results in External fragmentation because deallocating a process may leave its memory space unavailable for bigger processes.<br>
This can be resolved by rearranging the processes so that there are no empty spaces, which is known as memory compaction.<br>
However, moving the information loaded in memory can result in significant overhead.<br>

## Swapping in contiguous memory allocation
Swapping refers to the process of temporarily moving processes that are not currently being executed out of the memory to a secondary storage device. This technique is used to free up space in the limited memory. By using swapping, the effectively available memory space can be increased.
- Swap Space: This is the area on a secondary storage device where processes are temporarily stored. Swap space acts as an extension of the system's physical memory, allowing for more processes to be loaded than would otherwise fit into the physical RAM.
- Swap-Out: This process involves moving a process from the main memory to the swap space. Swap-out is typically performed when the system needs to free up RAM for other processes or when the system determines that a process is idle or less critical.
- Swap-In: Conversely, swap-in is the process of moving a process back from the swap space into the main memory. This occurs when the process is needed for execution. The system will then allocate space in the physical memory for the process and reload it from the swap space.

# Non-contiguous memory allocation
Non-contiguous memory allocation is a method of storing data in multiple memory locations rather than in a single contiguous block.
### Techniques
- Paging(majority): Divides a process's memory space into fixed-size blocks called pages. Each process is divided into pages of the same size, which can be stored anywhere in the physical memory.
- Segmentation(unusual): Divides a process's memory space into different segments, where each segment represents a specific type of data or code (e.g., code segment, data segment, stack segment). They can be non-contiguously allocated.
### Challenges
- More complex memory management.
- Overhead of maintaining page tables or segment tables.

## Virtual memory
Virtual memory is a memory management technique that creates an illusion of a very large memory space by using both physical memory (RAM) and a part of secondary storage (like a hard disk).<br>
Virtual memory inherently relies on non-contiguous memory allocation.
### Benefits
- Provides a large address space to processes, irrespective of the actual physical memory available.
### Considerations
- Overhead of page table management.
- Performance can be affected by the paging process, especially if the system frequently accesses data that is not in the main memory (page faults).

## Paging
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/c8375793-7802-4df8-bdd2-dbeee33c29e5)<br>
- External fragmentation occurs when processes of various sizes are allocated memory space contiguously.<br>
This issue can be resolved by dividing processes into uniform units called "pages" and slicing the memory space into equally sized units known as "frames", which are the same size as pages. Then, pages are allocated to frames.<br>
- Paging is typically used in conjunction with virtual memory.

### Page swapping
Page swapping refers to a scenario in which a page from the main memory is replaced by a page from the secondary memory. Page replacement occurs due to page faults.<br>
**page fault** occurs when a requested page is currently not loaded into the main physical memory.(This is checked using the "valid bit" in the page table entry)<br>
- **Page-out**: Moving a page from the main memory to the secondary memory.
- **Page-in**: If the data is not in RAM, a page fault occurs, and the OS loads the required data from the secondary storage to the main memory.

### Page table
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/10b1de02-1f68-431f-b03f-f869be8cffb2)<br>
The OS maintains a page table to track which virtual pages are mapped to which physical frames of memory.<br>
The virtual memory address is translated to a physical address using the page table.<br>
For fast page access, the page table is stored in a cache called **TLB**.(Translation Lookaside Buffer)<br>

### Page Table Entry
Each row in a page table is referred to as a page table entry, which stores data beyond just the page number and frame number. This includes:
- `Valid Bit`: Indicates whether the corresponding page is accessible. Essentially, it informs if a page fault has occurred, necessitating a page swap.
- `Protection Bit`: Specifies whether the page is read-only or if write operations are also permitted.
- `Reference Bit`: Shows whether the page has been accessed since it was loaded into RAM.
- `Modified Bit`: Indicates whether data has been written to the page, informing about any modifications.<br>
When a page is swapped in, the corresponding page on the secondary storage does not disappear. Therefore, if the data has not been modified after being swapped in, there is no need to write it back to the secondary storage during a swap-out, saving resources. The modified bit is used for this purpose.

### Page-replacement
Demand paging is a method where only the necessary pages are loaded into RAM. Eventually, while employing demand paging, RAM becomes full. To free up space, a page-out is required, and this process is known as Page Replacement

### Page-replacement algorithms
The fewer the number of page faults, the better the algorithm.
- **First-In First-Out** : The oldest page is moved out. This is the simplest but might be bad. Because even if a page is used throughout the program, it can be paged-out just because it was loaded first.<br>
`Second chance page replacement`: To solve the problem of FIFO, there is a method where, before a page-out, the reference bit is checked, and if the page has been accessed, it is moved to the position of a recently loaded page
- **Optimal page replacement** : The page that will be used the least in the future is the one that gets moved out. Theoretically, it guarantees the lowest rate of page faults, but predicting such pages is difficult, making it impractical.
- **Least-Recently-Used** : The page that was used the least recently gets paged out as it is likely not to be used constantly. In other words, the page that has not been used for the longest time is replaced.
This is one of the practically best algorithms.

### Thrashing and frame allocation
#### `Thrashing`
In fact, the most significant cause of increased page fault frequency is often not the page replacement algorithm, but rather the small number of frames allocated to a process.<br>
If there were an infinite number of frames, page replacement would not be necessary at all.<br>
While it may seem that increasing parallel processing can enhance speed, it inevitably reduces the number of frames available for each process, leading to frequent page faults and significant time spent on page replacement.<br>
This phenomenon is known as **thrashing**, and to prevent it, frames must be allocated appropriately.<br>
#### `Frame Allocation Methods`
- Equal Allocation: This method involves providing an equal number of frames to each process. It is inefficient because the size of each process can vary significantly, leading to underutilization or overutilization of memory resources for individual processes.
- Proportional Allocation: Frames are allocated in proportion to the size of the processes. One drawback of this method is that larger processes might end up with fewer frames than they actually need.
- Page-Fault Frequency: This approach allocates more frames to processes with higher page fault frequencies. It operates under the assumption that a high rate of page faults indicates a need for more frames to reduce these faults.
- Working Set Model: Frames are allocated based on the size of the process's working set, which is the set of pages the process has referenced over a specific recent period. This method tries to tailor frame allocation to the actual working memory needs of each process.
