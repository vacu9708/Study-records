# Hash table
>A hash table is an associative array, whose indices are normally arbitrary strings or other complicated objects, which maps keys to values used for searching for elements.<br>
>A hash table uses a hash function to compute an index, also called a hash code, into an array, from which the desired value can be found very fast irrespective of the number of the elements.

## The characteristic of Hash table
Each key is mapped to a specific index by a *hash function* in the array and its value stored in that location unless a *hash collision* occurs. Because of this, insertion, search and delete operations are performed in constant time **O(1)**.<br>
![image](https://github.com/vacu9708/Study-records/assets/67142421/18d449db-794e-41d5-b3a4-89d2e7d3ba4a)

## Hash collision
> There is a possibility that two keys result in the same value. The situation where a newly inserted key maps to an already occupied slot in the hash table is called *collision* and must be handled using some collision handling technique. 
![hashtable2](https://user-images.githubusercontent.com/67142421/148845229-92e74e37-9e50-42db-91cb-c1f49d493891.png)
