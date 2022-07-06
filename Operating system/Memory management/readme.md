* **Internal fragmentation** : Ex) when a partition of memory whose size is 10bytes has 8bytes of data
* **External framentation** :  When memory space outside partitions is unavailable.

## Contiguous memory allocation (obsolete)
In **contiguous memory allocation**, the WHOLE process is allocated to a contiguous partition of memory.
* **Fixed(or static) partitioning** : This is the oldest and simplest. The size of a partition is fixed in RAM when allocated, which can cause big internal fragmentation.
* **Variable(or dynamic) partitioning** : The partition size varies according to the need of the process, which can cause big external fragmentation.

## Non-contiguous memory allocation
In **Non-contiguous memory allocation**, parts of a process can be allocated to different locations.<br>
* In **paging** : a process is broken into fixed sized blocks called pages, which can cause internal fragmentation.
* In **segmentation** : a process is broken in varying sized blocks called sections, which can cause external fragmentation.

## Virtual memory
Usually used with the non-contiguous memory allocation<br>
Main memory is expensive and not big, so a process needs to be able to be executed even if the whole process is not on the main memory.<br>
Virtual memory allows secondary memory to be able to be addressesd as though it were main memory.<br>

## Page replacement
**Demanding page** : to bring pages in the main memory only when they are required<br>
Even if only required pages are moved onto main memory, main memory becomes full eventually. So, which page to remove for a new page to come in needs to be decided.

### page-replacement algorithmss
* **First-In First-Out** : This is the simplest. the oldest page is moved out.
* **Optimal page replacement** : a page that will be used the least is moved out. This reduces page-faults the most theoretically
but it is the problem that such a page is hard to predict.
* **Least-Recently-Used** : exploits the fact that pages that were not used recently have a high probability not to be used constantly.
It reduces page-faults less than the optimal page replacement but is one of the practically best algorithms.
