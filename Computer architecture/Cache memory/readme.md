# ✨Cache memory
In computing, a **cache** is a hardware or software component that stores data so that future requests for that data can be served faster.<br>
It is used to decrease the bottleneck between a fast device and a slow device.<br>

## Types of cache memory
Normally a CPU has 3 pieces of cache memory, which are called L1, L2, L3 each in the order of slower speed.<br>
L1 cache is in the CPU and searched first. L2 is between the CPU and RAM. L3 is in main board and the last to be searched.

## Cache memory works based on these principles
`Locality of reference`
- **Temporal locality** : Memory locations that have been referenced are likely to be referenced shortly again.
- **Space locality** : Memory locations close to those that have been referenced are likely to be referenced shortly.

## Cache hit and Cache miss
- On a cache hit : the CPU can quickly retrieve data from the cache.
- A cache miss is an event in which an attempt to retrieve data from a cache, where the CPU has to fetch the data from the main memory to the cache.<br>
- **If cache misses happen too much**, having cache memory is worse than not having it because the time taken to find data in cache memory was wasted.<br>

## Cache placement policies
- **Direct Mapped Cache**

![image](https://user-images.githubusercontent.com/67142421/177051043-23ec7372-938a-4b7c-b317-b7174a99eabd.png)<br>
In this structure multiple addresses of RAM map to a single address in cache memory.<br>
It works the same way as hash table. Therefore, there is a possibility that a collision occurs. (conflict miss)

* **Fully Associative Cache**
A method by which data is stored in any empty location. It is simple when storing, but searching is the problem because the cache has to be searched until sought data is found.

* **Set Associative Cache**
It is a trade-off between direct-mapped cache and fully associative cache. A hybrid cache that combines the associative cache and the direct-mapped cache.<br>
A set-associative cache can be imagined as a (n by m)matrix.<br>
The cache is divided into 'n' rows and each row contains 'm' columns. A memory block in RAM is first mapped onto a row and then placed into any column of a row.

## Cache replacement algorithms:
[It is similar to page replacement algorithms](https://github.com/vacu9708/Fundamental-knowledge/tree/main/Operating%20system/Memory%20management)
