Hash table, which takes O(1) time might seem the best for searching data, but hash table works only for equal sign operations and 
DB operations include other operations too. We need another method.

**Database index** : is a tree data structure to improve the speed of data retrieval operations on a database table at the cost of 
additional writes and storage space to maintain the index data structure.<br>
**Summary** : a method to increase the reading speed by sacrificing the writing speed.<br>
The indexed B+ tree makes it possible to avoid scanning all the table, which leads to faster lookups in **WHERE** clause.

## How it works (INDEX here is an indexed B+ tree)
![image](https://user-images.githubusercontent.com/67142421/177963648-acce3807-a7ab-49b9-979a-d282bb05c414.png)

![image](https://user-images.githubusercontent.com/67142421/177964732-7c42ca86-d32a-4639-9d26-ead095245e0f.png)

### Animation
### Without index (takes *O(n)*)
<img src="https://dataschool.com/assets/images/sql-optimization/how_to_index/BasicSearchGif.gif">

### With index (takes *O(logn)*)
~~~sql
CREATE INDEX friends_name_asc ON friends(name ASC);
~~~

<img src="https://dataschool.com/assets/images/sql-optimization/how_to_index/BinarySearchGif.gif">

1. Look for the data on the indexed B+ tree
2. Once the data was found, get the data that it points to

## Trade off(overheads)
- B+ tree takes up more storage space.
Database index increases the reading speed largely, but decreases the speed of all other operations(data manimulation) after a data manipulation.
* **Insert** : the index for new data has to be added and the table has to be sorted.
* **Delete** : the index of deleted data has to be deleted.
* **Update** : the index of previous data has to be deleted, the index of updated data has to be added and the table has to be sorted.

# Cardinality, Selectivity
## Cardinality
- the number of elements of a set, that is, the number of unique elements.
- The higher, the better for indexing because low cardinality means full or near full scans are performed in "WHERE" clauses in which indexing is meaningless.
### Calculation of cardinality
- Ex) "phone number": number of rows
- Ex) "SEX": 2
## Selectivity
- the number of rows with a specific value, divided by the total number of rows.
- The lower, the better for indexing
### Calculation of selectivity
- Ex) "SEX" column = 0.5
- Ex) "phone number = 0.1
