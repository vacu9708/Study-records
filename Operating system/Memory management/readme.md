# Types of memory fragmentation
* **Internal fragmentation** : Ex) when a partition of memory whose size is 10bytes has 8bytes of data
* **External framentation** :  When memory space outside partitions is unavailable.

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
In **Non-contiguous memory allocation**, parts of a process can be allocated to different locations.<br>
* **Paging** : a process is broken into fixed sized blocks called pages, which can cause internal fragmentation.
* **Segmentation** : a process is broken in varying sized blocks called sections, which can cause external fragmentation.

# Virtual memory
Usually used with the non-contiguous memory allocation<br>
Main memory is expensive and has limited space, so a process should be able to be executed even if the whole process is not on the main memory.<br>
Virtual memory allows secondary memory to be able to be addressesd as though it were main memory.<br>

# Page replacement
**Demanding page** : to bring pages in the main memory only when they are required<br>
Even if only required pages are moved onto main memory, main memory becomes full eventually. So, which page to remove for a new page to come in needs to be decided.

### page-replacement algorithmss
* **First-In First-Out** : This is the simplest. the oldest page is moved out.
* **Optimal page replacement** : a page that will be used the least is moved out. This reduces page-faults the most theoretically
but it is the problem that such a page is hard to predict.
* **Least-Recently-Used** : exploits the fact that pages that were not used recently have a high probability not to be used constantly.
It reduces page-faults less than the optimal page replacement but is one of the practically best algorithms.

# Memory Management Unit
A memory management unit is hardware that manages all operations in the memory system such address.<br>
Some of its role are :
* Converting a virtual memory address to a physical address.
* Memory protection in which each process can only access its own memory section.
