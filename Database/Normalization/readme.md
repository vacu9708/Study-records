# Update anomalies
All the anomalies occur due to duplicate data (redundancy) in the database:
### Modification anomalies
Modifying a piece of data may require updating multiple occurrences of the same data, leading to inconsistencies.<br>
For example, when updating the school name for one student, it may need to be updated for all other students with the same school name.
### Insertion anomalies
Inserting information for an entity may become problematic if it depends on the presence of other related entities.<br>
For example, when trying to insert a new student without a specified college, it may not be possible because the database requires the college information.<br>
### Deletion anomalies
Removing information for an entity may inadvertently delete data of other related entities.<br>
For example, when deleting a student, it may unintentionally delete the college information for other students with the same college.

# Data normalization
A process of organizing(minimizing) tables to get rid of data redundancy and retain data integrity.
### Drawbacks
It introduces the need for JOIN operations when retrieving data from multiple tables. JOINs have some overhead and potentially affect performance.<br>

## Why is normalization needed?
Modern database systems are optimized to handle JOINs efficiently, and the benefits of data integrity often outweigh the performance impact of JOIN operations.<br>
![image](https://user-images.githubusercontent.com/67142421/203905904-0b691b1f-2798-4b12-85f0-45daf6e2d466.png)<br>
This table above looks great because every piece of information is displayed in one table. But actually, this big table has problems.
- First, the same data appears multiple times(data redundancy problem)
- Second, when a piece of data is updated, others that have that data also require update(data integrity problem)

![image](https://user-images.githubusercontent.com/67142421/205222225-f131a5ca-c18a-4478-b72b-a8372c63afa9.png)

## Initial table
Primary key: [ID], [college]
|[ID]|name|highschool|school_size|[college]|accepted|
|---|---|---|---|---|---|
|1|John|A school|500|MIT, stanford|Y|
|2|sheila|B school|600|harvard|Y|
|3|maria|C school|700|prinston|N|

## 1st normal form (No multi value attributes)
- An attribute can only have one value
#### Table A:
Primary key: [ID], [college]
|[ID]|name|highschool|school_size|[college]|accepted|
|---|---|---|---|---|---|
|1|John|A school|500|MIT|Y|
|1|John|A school|500|stanford|Y|
|2|sheila|B school|600|harvard|Y|
|3|maria|C school|700|prinston|N|

## 2nd normal form (Only essential keys)
- The table must be in 1NF form
- In X->Y where X is primary keys, EVERY key of X is essential to distinguish Y<br>
On table A, [college] is used only to distinguish [accepted]br>
Table A is split into these.<br>
#### Table B:
Primary key: [ID]<br>
|[ID]|name|highschool|school_size|
|---|---|---|---|
|1|John|A school|500|
|2|sheila|B school|600|
|3|maria|C school|700|
#### table C:
Primary key: [ID], [college]
|[ID]|[college]|accepted|
|---|---|---|
|1|MIT|Y||
|1|stanford|Y|
|2|harvard|Y|
|3|princeton|N|

## 3rd normal form (Set foreign key)
- The table must be in 2NF form
- When X->Y, Y->Z, then it is called **transitive dependency**.
In table B, [ID] identifies [highschool] and [highschool] identifies [school_size], which makes a transitive dependency.<br>
Set a foreign key [highschool] to solve this problem.<br>
Table B is split into these.
#### table D:
Primary key: [ID]
|[ID]|name|highschool|
|---|---|---|
|1|John|A school|
|2|sheila|B school|
|3|maria|C school|
#### table E:
Primary key: [highschool]
|[highschool]|school_size|
|---|---|
|A school|500|
|B school|600|
|C school|700|

## BCNF
- The table must be in 3NF form
- For any dependency X → Y, X must be a candidate key or super key
 
# Denormalization
Denormalization is a database optimization technique in which we add redundant data to one or more tables. This can help us avoid costly JOINs in a relational database. Note that denormalization does not mean ‘reversing normalization’ or ‘not to normalize’. It is an optimization technique that is applied after normalization.

### Advantage
- Retrieving data is faster due to fewer JOINs to be done.

### Disadvantave
- Increased possibility of update anomalies.
