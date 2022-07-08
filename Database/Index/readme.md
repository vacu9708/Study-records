Hash table, which takes O(1) time might seem the best for searching data, but hash table works only for equal sign operations and 
DB operations include other operations too. We need another method.

**Database index** : is a tree data structure to improve the speed of data retrieval operations on a database table at the cost of 
additional writes and storage space to maintain the index data structure.<br>
**Summary** : a method to increase the reading speed by sacrificing the writing speed.<br>
The indexed B+ tree makes it possible to avoid scanning all the table, which leads to faster lookups.

## How it works (INDEX here is an indexed B+ tree)
![image](https://user-images.githubusercontent.com/67142421/177963648-acce3807-a7ab-49b9-979a-d282bb05c414.png)

![image](https://user-images.githubusercontent.com/67142421/177964732-7c42ca86-d32a-4639-9d26-ead095245e0f.png)

### Without index
![image](https://user-images.githubusercontent.com/67142421/177971457-03326384-4f83-4604-95b8-6d6ab697e521.png)

### With index
![image](https://user-images.githubusercontent.com/67142421/177971339-d00e0dd6-787a-4ff2-b502-88fc660e9443.png)


1. Sort the table in the order of the location
2. Sort the indexed B+ tree (in an alphabetical order)
3. Look for the data on the indexed B+ tree
4. Once the data was found, get the pointer and move to the target data

## Trade off(overheads)
Database index increases reading speed largely, but decreases the speed of all other operations(data manimulation) because the indexed B+ tree has to be updated
and in Delete and Update operation, the table has to be sorted too.<br>
* **Insert** : the index for new data has to be added and the table has to be sorted.
* **Delete** : the index of deleted data has to be deleted.
* **Update** : the index of previous data has to be deleted, the index of updated data has to be added and the table has to be sorted.
