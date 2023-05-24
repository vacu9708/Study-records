# Indexing
Hash table, which takes O(1) time, might seem the fastest for searching data, but hash table works only for equal sign operations and 
DB operations include other operations too. We need another method.

**Database index** is a data structure that improves the speed of data retrieval operations on a database table at the cost of additional writes(slower write) and space complexity to maintain the index data structure.<br>
The indexed B+ tree makes it possible to avoid scanning the entire table, which leads to faster lookups in **WHERE** clause.<br>
Indexing is commonly used for primary keys.

## How indexing works (INDEX here is an indexed B+ tree)

## Animation
### Without index (takes ***O(n)***)
<img src="https://github.com/vacu9708/Fundamental-knowledge/blob/main/Database/Indexing/Without%20index.gif">

### With index (takes ***O(logn)***)
~~~sql
CREATE INDEX friends_name_asc ON friends(name ASC);
~~~
<img src="https://github.com/vacu9708/Fundamental-knowledge/blob/main/Database/Indexing/With%20index.gif">

![image](https://user-images.githubusercontent.com/67142421/177964732-7c42ca86-d32a-4639-9d26-ead095245e0f.png)

1. Look for the data on the indexed B+ tree
2. Once the data was found, get the data that it points to

## Trade off(overheads)
Database index increases the reading speed largely, but decreases the speed of all other operations related to data manimulation and takes up more storage.
* **Insert** : the index for new data has to be added and the table has to be sorted.
* **Delete** : the index of deleted data has to be deleted.
* **Update** : the index of previous data has to be deleted, the index of updated data has to be added and the table has to be sorted.

## Efficient indexing
It's essential to design and manage indexes carefully to ensure optimal performance.<br>
Over-indexing, where too many indexes are created, can slow down data modifications and consume excessive storage.<br>
Under-indexing, on the other hand, may result in slower query execution.<br>
Therefore, it's crucial to analyze the workload and query patterns to determine which columns would benefit from indexing, considering factors such as selectivity, cardinality, and the types of queries performed on the database table.

## Cardinality, Selectivity
### Cardinality
- Cardinality = the number of unique elements in a column.
- The higher, the better for indexing because low cardinality means that a column has less distinct values, therefore **WHERE** clauses takes full or near full scans in which indexing is meaningless.
#### Example:
- Ex) The cardinality of **phone number** = the number of rows because each phone number is unique.
- Ex) The cardinality of **sex** = 2 because sex only has 2 dinstinct values(male and female).
### Selectivity
Selectivity measures the proportion of rows in a table that have a specific value in a particular column.<br>
In other words, it is a normalized form of cardinality.<br>
- Selectivity = Cardinality divided by the total number of rows.
- The higher, the better for indexing
#### Example:
- Ex) **phone number**: 1
- Ex) **SEX** column: 0.5
