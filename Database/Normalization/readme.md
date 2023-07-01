# Update anomalies
All the anomalies occur due to redundanc data in the database:
### Modification anomalies
Modifying a piece of data may require updating multiple occurrences of the same data, leading to data inconsistency problem.<br>
For example, when updating the school name for one student, it may need to be updated for all other students with the same school name across multiple tables.
### Insertion anomalies
Inserting information for an entity may become problematic if it depends on the presence of other related entities.<br>
For example, when trying to insert a new student without a specified college, it may not be possible because the database requires the college information.<br>
### Deletion anomalies
Removing information for an entity may inadvertently delete data of other related entities.<br>
For example, when deleting a student, it may unintentionally delete the college information for other students with the same college.

# Data normalization
A process of organizing(minimizing) tables to get rid of data redundancy and retain data inconsistency.
### Drawbacks
It introduces the need for JOIN operations when retrieving data from multiple tables. JOINs have some overhead and potentially affect performance.<br>

## Is a big table good?
![image](https://user-images.githubusercontent.com/67142421/203905904-0b691b1f-2798-4b12-85f0-45daf6e2d466.png)<br>
This table above looks great because every piece of information is displayed in a single table. However, actually this big table is problematic.<br>
The reason is written below in the denormalization section.<br>

![image](https://user-images.githubusercontent.com/67142421/205222225-f131a5ca-c18a-4478-b72b-a8372c63afa9.png)

## Initial table
Primary key: [stduent_ID], [college]
|[stduent_ID]|name|highschool|school_size|[college]|accepted|
|---|---|---|---|---|---|
|1|John|A school|500|MIT, stanford|Y|
|2|sheila|B school|600|harvard|Y|
|3|maria|C school|700|prinston|N|

## 1st normal form (No multi value attributes)
- An attribute can only have one value

The initial table is converted into
#### Table A:
Primary key: [stduent_ID], [college]
|[stduent_ID]|name|highschool|school_size|[college]|accepted|
|---|---|---|---|---|---|
|1|John|A school|500|MIT|Y|
|1|John|A school|500|stanford|Y|
|2|sheila|B school|600|harvard|Y|
|3|maria|C school|700|prinston|N|

## 2nd normal form (Partial dependency not allowed)
- The table must be in 1NF form
- In X->Y where X is the primary key, All of X are essential to distinguish Y. i.e. All non-key attributes are dependent on the primary key.)

On table A, [college] is used only to distinguish [accepted]<br>
Table A is split into
#### Table B:
Primary key: [stduent_ID]<br>
|[stduent_ID]|name|highschool|school_size|
|---|---|---|---|
|1|John|A school|500|
|2|sheila|B school|600|
|3|maria|C school|700|
#### table C:
Primary key: [ID], [college]
|[stduent_ID]|[college]|accepted|
|---|---|---|
|1|MIT|Y||
|1|stanford|Y|
|2|harvard|Y|
|3|princeton|N|

## 3rd normal form (Transitive dependency not allowed. Set foreign key.)
- The table must be in 2NF form
- When X->Y, Y->Z, then it is called **transitive dependency**. In other words, transitive dependency refers to a situation where a non-key attribute depends on another non-key attribute.<br>

In table B, [stduent_ID] identifies [highschool] and [highschool] identifies [school_size], which makes a transitive dependency.<br>
Set a foreign key [highschool] to solve this problem.<br>
Table B is split into
#### table D:
Primary key: [stduent_ID]
|[stduent_ID]|name|highschool|
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
Denormalization is a database optimization technique in which redundant data is added to one or more tables. This can help avoid costly JOINs.<br>
Note that denormalization does not mean ‘reversing normalization’ or ‘not to normalize’. It is an optimization technique that is applied after normalization.

### When to denormalize
**Performance optimization on reads**: In systems where read operations significantly outweigh write operations, denormalization can be employed to enhance query performance.<br>
By consolidating related data into a single table or duplicating data across multiple tables, the need for complex JOINs and lookups can be reduced, resulting in faster query execution.<br>
Writing to denormalized has overhead
### Caution!
Denormalization introduces data redundancy, so it is crucial to assess the impact of denormalization on data inconsistency and ensure appropriate mechanisms are in place to maintain consistency.<br>
Also, the benefits of data inconsistency often outweigh the performance impact of JOIN operations.<br>
- Duplicated data across multiple tables raises the possibility of overlooking some modifications during updates, leading to data inconsistencies.
- Speed when updating redundant data is slowed down.
#### Why update speed is slowed down:
- **Overhead on index and constraint updates**: Indexes and constraints are often defined on tables to improve query performance and enforce data inconsistency. When duplicated data is modified, these indexes and constraints may need to be updated for each occurrence of the duplicated data.
- **Synchronization overhead**: Modifying a piece of duplicated data may require updating all other duplicate data to maintain inconsistency.
