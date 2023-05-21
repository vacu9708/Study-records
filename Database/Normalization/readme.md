# Update anomalies
## All the anomalies occur because of duplicate data!(redundancy)
- ### Modification anomalies
Partial modification
- ### Insertion anomalies
When entering information of an entity requires the information of other entities<br>
Ex) When inserting the information of an employee whose department hasn't been decided
- ### Deletion anomalies
When deleting information of an entity causes other entities' information to be deleted<br>
Ex) When firing an employee might cause their department to be deleted

# Data normalization
A process of minimizing tables to get rid of data redundancy and retain data integrity.
**drawbacks** : Split tables require JOIN, which leads to a slower speed.

# Why is normalization needed?
![image](https://user-images.githubusercontent.com/67142421/203905904-0b691b1f-2798-4b12-85f0-45daf6e2d466.png)<br>
This table above looks great because every piece of information is displayed in one table. But actually, there are problems in this big table.
- First, the same data appear several times(data redundancy problem)
- Second, when a piece of data is updated, other tables that have that data also have to be updated(data integrity problem)

![image](https://user-images.githubusercontent.com/67142421/205222225-f131a5ca-c18a-4478-b72b-a8372c63afa9.png)

## Initial table
Primary key: [ID], [college]
|[ID]|name|highschool|school_size|[college]|accepted|
|---|---|---|---|---|---|
|1|John|A school|500|MIT, stanford|Y|
|2|sheila|B school|600||Y|
|3|maria|C school|700|prinston|N|

## 1st normal form (No multi value attributes)
- An attribute can only have one value
#### Table A:
Primary key: [ID], [college]
|[ID]|name|highschool|school_size|[college]|accepted|
|---|---|---|---|---|---|---|
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
- Retrieving data is faster since fewer joins are done.

### Disadvantave
- Increased possibility of update anomaly.
