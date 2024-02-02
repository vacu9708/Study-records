Open addressing is a collision resolution method used in hash tables when multiple keys hash to the same index.<br>
Unlike chaining, open addressing seeks an alternative empty slot within the hash table array itself for placing the collided key-value pair.

## Key Techniques in Open Addressing
![image](https://github.com/vacu9708/Study-records/assets/67142421/791c1343-03b1-4685-8325-34fb7427f443)<br>
- **Linear Probing**: When a collision occurs, linear probing searches for the next available slot by moving sequentially through the table from the point of collision.
  - While simple, linear probing can lead to clustering, where blocks of consecutive slots get filled, increasing the likelihood of collisions and decreasing performance.
- **Quadratic Probing**: To address the clustering issue seen in linear probing, quadratic probing increases the interval between probes quadratically (1, 4, 9, 16, ...).
  - This spreads out the keys more evenly but can still suffer from a different form of clustering called secondary clustering because of the inherent regularity of the step size like the Linear probing.
- **Double Hashing**: Double hashing uses a second hash function to determine the step size for each probe after a collision. This method is more effective at distributing keys evenly and minimizing clustering, as the step size is unique for each key.

## Process of Open Addressing
- **Insertion**: Compute the hash index for the key. If the slot at the computed index is empty, insert the key-value pair there. If the slot is occupied (collision), use the probing method to find an empty slot and insert the key-value pair there.
- **Search/Lookup**: Compute the hash index for the key. Check the slot at the computed index; if it matches the key, return the value. If it does not match, use the probing method to find the next slot until the key is found or an empty slot is encountered, which indicates that the key is not in the table.
- **Deletion**: Mark deleted slots with a special flag ("deleted" or "tombstone") rather than leaving them empty, indicating that probing should continue past these slots.

## Advantages of Open Addressing
- **Space Efficiency**: Open addressing does not require additional data structures for storing key-value pairs outside the array, making it more space-efficient, especially when the load factor(ratio of number of elements to table size) is low to moderate.
- **Cache Efficiency**: Because all elements are stored in a contiguous block of memory, open addressing can exhibit better cache performance, leading to faster access times in some scenarios.
## Disadvantages of Open Addressing
- **Load Factor Limitations**: As the table fills up, performance can degrade significantly due to an increase in collisions and probing lengths. To maintain performance, open addressing requires keeping the load factor low, which can lead to underutilized memory.
