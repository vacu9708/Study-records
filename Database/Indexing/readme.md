# Indexing
**Database index** is a data structure that improves the speed of data retrieval operations at the cost of additional writes(slower write) and space complexity to maintain the index data structure.<br>
The data retrieval speed O(logN) of the B+ tree allows avoiding scanning the entire column in **WHERE** clauses.<br>
Indexing is commonly used for primary keys(unique keys).

>Hashmap, which takes O(1) time, might seem the fastest for searching data, but hashmap works only for equal sign operations and DB operations include other operations too. That is why the B+ tree is used not hashmap.<br>

## Indexing process (INDEX here is a B+ tree)
1. **Determination of where to apply indexing**: Determine the columns that will be indexed based on the query patterns and workload of the database table. Typically, columns involved in frequent search are good candidates for indexing.
2. **Index creation**: The DBMS builds the B+ tree by scanning the target column. The B+ tree stores references to the corresponding data.
3. **Data retrieval** Look for the target data in the B+ tree and get the row the reference points to. 

![image](https://user-images.githubusercontent.com/67142421/177964732-7c42ca86-d32a-4639-9d26-ead095245e0f.png)

### With index (***O(logn)***)
~~~sql
CREATE INDEX friends_name_asc ON friends(name ASC);
~~~
<img src="https://github.com/vacu9708/Fundamental-knowledge/blob/main/Database/Indexing/With%20index.gif">

### Without index (***O(n)***)
<img src="https://github.com/vacu9708/Fundamental-knowledge/blob/main/Database/Indexing/Without%20index.gif">

## Trade off(overheads)
- **Increased Storage Overhead**: The B+ tree requires additional storage space.
* **Slow modifications(inserts, updates, and deletes),**: Changes to indexed columns require updating not only the actual table but also the B+ tree associated with the indexed columns.

## Efficient indexing
It's essential to design and manage indexes carefully to ensure optimal performance.<br>
Over-indexing, where too many indexes are created, can slow down data modifications and consume excessive storage.<br>
Under-indexing, on the other hand, may result in slower query execution.<br>
Therefore, it's crucial to analyze the workload and query patterns to determine which columns would benefit from indexing, considering factors such as selectivity, the types of queries performed on the database table.

## Cardinality, Selectivity
### Cardinality
- Cardinality = the number of unique elements in a column
- The higher cardinality, the better for indexing because low cardinality means that a column has less distinct values, therefore **WHERE** clauses takes full or near full scans in which indexing is meaningless.
#### Example:
- Ex) The cardinality of **phone number** = the number of rows because each phone number is unique.
- Ex) The cardinality of **sex** = 2 because sex only has 2 dinstinct values(male and female).
### Selectivity
Selectivity measures the proportion of rows in a table that have a specific value in a particular column.<br>
In other words, it is a normalized form of cardinality.<br>
- Selectivity = Cardinality divided by the total number of rows
- The higher selectivity, the better for indexing due to the same reason as cardinality
#### Example:
- Ex) **phone number** column: 1
- Ex) **sex** column: 0.5
