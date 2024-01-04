# SSD
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/8fa0185b-57ff-48c8-a05f-7f7343c7aa22)<br>
Floating gate transistor

# DRAM(Dynamic RAM)
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/f96a82f1-771e-43b9-b3df-a1fb2f80aaa8)<br>
The stored data dynamically changes (disappears). It is volatile because it requires refreshing the data stored in the capacitor.

# SRAM(Static RAM)
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/60a9114b-c3c4-486c-924d-2f35167325c3)<br>
SRAMs are made up of flip-flops, so the data is maintained without refreshing

| Feature | DRAM    | SRAM    |
|---------|---------|---------|
| Refresh | O       | X       |
| Speed   | Bad     | Good    |
| Price   | Cheap   | Expensive |
| Density | High    | Low     |
| Usage   | RAM     | Cache   |

# ✨Cache memory
In computing, a **cache** is a hardware or software component that stores data so that future requests for that data can be served faster.<br>
It is used to decrease the bottleneck between a fast device and a slow device.<br>

## Types of cache memory
Normally a CPU has 3 pieces of cache memory, which are called L1, L2, L3 each in the order of slower speed.<br>
L1 cache is in the CPU and searched first. L2 is between the CPU and RAM. L3 is in main board and the last to be searched.

## Cache memory works based on these principles
`Locality of reference`
- **Temporal locality** : Memory locations that have been referenced are likely to be referenced shortly again. For example, in a program that outputs multiples of 2, the number 2 is used continuously.
- **Space locality** : Memory locations close to those that have been referenced are likely to be referenced shortly. For example, in the memory space of a program that prints the multiplication table, numbers from 1 to 9 are gathered and stored.

## Cache hit and Cache miss
- On a cache hit : the CPU can quickly retrieve data from the cache.
- A cache miss is an event in which an attempt to retrieve data from a cache, where the CPU has to fetch the data from the main memory to the cache.<br>
- **If cache misses happen too much**, having cache memory is worse than not having it because the time taken to find data in cache memory was wasted.<br>

## Cache placement policies
- **Direct Mapped Cache**

![image](https://user-images.githubusercontent.com/67142421/177051043-23ec7372-938a-4b7c-b317-b7174a99eabd.png)<br>
In this structure multiple addresses of RAM map to a single address in cache memory.<br>
It works the same way as hash table. Therefore, there is a possibility that a collision occurs. (conflict miss)

- **Fully Associative Cache**
A method by which data is stored in any empty location. It is simple when storing, but searching is the problem because the cache has to be searched until sought data is found.

- **Set Associative Cache**
It is a trade-off between direct-mapped cache and fully associative cache. A hybrid cache that combines the associative cache and the direct-mapped cache.<br>
A set-associative cache can be imagined as a (n by m)matrix.<br>
The cache is divided into 'n' rows and each row contains 'm' columns. A memory block in RAM is first mapped onto a row and then placed into any column of a row.

## Cache replacement algorithms:
[It is similar to page replacement algorithms](https://github.com/vacu9708/Fundamental-knowledge/tree/main/Operating%20system/Memory%20management)

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
