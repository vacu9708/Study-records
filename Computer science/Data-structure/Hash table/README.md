# Hash table
![image](https://github.com/vacu9708/Study-records/assets/67142421/18d449db-794e-41d5-b3a4-89d2e7d3ba4a)<br>
A hashmap, also known as a hash table or a dictionary, is an associative array that can map keys to values. A hashmap uses a hash function to compute an index, also known as a hash code, into an array of buckets or slots, from which the desired value can be found.

## Key components
- **Keys**: The unique identifiers used to access corresponding values in the map. Each key is unique within a hashmap.
- **Values**: The data or information that is associated with a key.
- **Hash function**: A function that converts keys into array indices. A good hash function is essential for distributing entries across the hashmap's buckets evenly.
- **Buckets or Slots**: The positions in the array where the key-value pairs are stored. The size of the array defines the capacity of the hashmap.

## Characteristics
- **Efficiency**: In the best case, the complexity of search, insert, and delete operations are `O(1)`, thanks to the direct index access. However, in the worst case (e.g., when many keys collide), these operations can degrade to O(n), where n is the number of keys.
- **Unordered**: Hashmaps do not maintain the order of their elements, so they are not suitable for applications where the order of elements is important.
- **Dynamic Resizing**: Many hashmaps automatically resize themselves when their load factor (a measure of how full the hashmap is) exceeds a certain threshold, to reduce hash collisions.

## Functionalities
- **Insertion (Put)**: Adds a new key-value pair to the hashmap. If the key already exists, its value is updated.
- **Deletion (Remove)**: Removes the key-value pair from the hashmap, if present.
- **Lookup (Get)**: Returns the value associated with a key. If the key is not found, it may return a special value indicating absence (e.g., null or undefined).
- **Size**: Returns the number of key-value pairs stored in the hashmap.

## Hash collision
![hashtable2](https://user-images.githubusercontent.com/67142421/148845229-92e74e37-9e50-42db-91cb-c1f49d493891.png)<br>
A hash collision occurs when two distinct keys (inputs) to a hash function produce the same output (hash value).<br>
### Why hash collisions occur
Hash collisions are inherent to the nature of hash functions because the set of possible keys is typically much larger than the set of possible hash values.<br>
- For example, if a hash function produces a 32-bit output, there can be at most 2 32 2 32 unique hash values. some keys must produce the same hash value, leading to collisions.

## Handling Hash Collisions
There are several strategies for dealing with collisions:
- **Chaining**: Each bucket in the hash table points to a list (or a chain) of entries. If a collision occurs, the new key-value pair is added to the list corresponding to that bucket. Lookup operations may require a linear search through the list in the worst case.
- **Open Addressing**: All elements are stored within the array itself, and the collision resolution scheme probes the array for empty slots. Several probing techniques exist, such as:
  - **linear probing** (where the table is searched sequentially)
  - **quadratic probing** (where the interval between probes increases quadratically)
  - **double hashing** (where a second hash function determines the probe sequence).
- When a collision occurs, the hash table looks for the next available slot according to the probing sequence and stores the key-value pair there.

## Rehashing
### Why Rehashing is Necessary
- **Performance Maintenance**: As more elements are added to a hash table, collisions become more likely, and the efficiency of hash table operations can degrade. Rehashing reduces the load factor and collision frequency, maintaining operation efficiency.
- **Dynamic Scaling**: Rehashing allows hash tables to adjust their size dynamically based on the number of elements stored, accommodating both growth and, in some implementations, shrinking to save memory when many elements are removed.
### Process of Rehashing
- **Create a New Hash Table**: A new, larger hash table is created, often doubling the size of the old table to ensure that the load factor is significantly reduced after rehashing. The size is usually chosen to be a prime number or a power of two, depending on the hash function being used, to help reduce the likelihood of collisions.
- **Recompute Hashes**: Each key in the original hash table is rehashed according to the new table's size. Because the hash function often depends on the size of the table, changing the table size means that the index at which a key-value pair is stored will likely change.
- **Reinsert Elements**: Each key-value pair from the original table is inserted into the new table based on its newly computed hash. This step effectively redistributes the elements across the new table, potentially in a more evenly spaced manner, which helps in reducing collision-related issues.
- **Dispose of the Old Table**: Once all elements have been moved to the new table, the old table is disposed of.
