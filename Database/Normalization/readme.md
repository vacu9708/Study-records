# Update anomalies
## All the anomalies occur because of duplicates!(redundancy)
- ### Modification anomalies
Partial modification
- ### Insertion anomalies
Entering information of an entity requires the information of other entities<br>
Ex) When inserting the information of an employee whose department hasn't been decided
- ### Deletion anomalies
Deleting information of an entity causes other entities' information to be deleted
Ex) Firing an employee might cause their headquarter to be deleted

# Data normalization
the process of organizing tables to get rid of data redundancy and retain data integrity. It also makes it easier to add a new table
because normalized tables are minimized.<br>
**drawbacks** : Spliting a table makes more tables to JOIN, which leads to a slower speed.

# Why is normalization needed?
![image](https://user-images.githubusercontent.com/67142421/203905904-0b691b1f-2798-4b12-85f0-45daf6e2d466.png)<br>
This table above looks great because every piece of information is displayed in one table. But actually, there are problems in this big table.
- First, the same data appear several times(data redundancy problem)
- Second, when a piece of data is updated, other tables that have that data also have to be updated(data integrity problem)

![image](https://user-images.githubusercontent.com/67142421/205222225-f131a5ca-c18a-4478-b72b-a8372c63afa9.png)

## Initial table
Primary key: [ID, college_name]
|*ID*|name|hobby|highschool|school_size|*college*|accepted|
|---|---|---|---|---|---|---|
|1|John|soccer, basketball|A school|500|MIT|Y|
|2|Paul|swimming|stanford|B school|500|Y|
|3|John|reading|berkeley|C school|600|N|

## 1st normal form
- An attribute can only have one value
- It has the problem that there might be duplicate primary keys

|*ID*|name|hobby|highschool|school_size|*college*|accepted|
|---|---|---|---|---|---|---|
|1|John|soccer|A school|500|MIT|Y|
|1|John|basketball|A school|500|MIT|Y|
|2|Paul|swimming|B school|500|stanford|Y|
|3|John|reading|C school|600|berkeley|N|

## Multi-valued attribute is mapped into a new table like this
Primary key: [name, hobby]

|*name*|*hobby*|
|---|---|
|John|soccer|
|John|basketball|

### Table A
|*ID*|name|highschool|school_size|college|accepted|
|---|---|---|---|---|---
|1|John|A school|500|MIT|Y|
|2|Paul|B school|500|stanford|Y|
|3|John|C school|600|berkeley|N|

## 2nd normal form
- The table must be in 1NF form
- In X->Y where X is a primary key, ALL the attributes of X have to be needed for Y<br>
On the table A, only [ID] is needed to distinguish name, and [ID, college_name] is needed to distinguish accepted.<br>
Table A is split into these.<br>
### Table B
|*ID*|name|highschool|school_size|
|---|---|---|---|
|1|John|A school|500|
|2|Paul|B school|500|
|3|John|C school|600|

|*ID*|college|accepted|
|---|---|---|
|1|MIT|Y|
|2|stanford|Y|
|3|berkeley|N|

## 3rd normal form
- The table must be in 2NF form
- When X->Y, Y->Z where X is the primary key then it is called **transitive dependency**.<br>
Set a foreign key [highschool] to solve this problem.<br>
Table B is split into these.<br>
|*ID*|name|highschool|
|---|---|---|
|1|John|A school|
|2|Paul|B school|
|3|John|C school|

|*highschool*|school_size|
|---|---|
|A school|500|
|B school|500|
|C school|600|

## BCNF
- The table must be in 3NF form
- For any dependency X → Y, X must be a candidate key or super key
 
# Denormalization
Denormalization is a database optimization technique in which we add redundant data to one or more tables. This can help us avoid costly JOINs in a relational database. Note that denormalization does not mean ‘reversing normalization’ or ‘not to normalize’. It is an optimization technique that is applied after normalization.

## Advantage
* Retrieving data is faster since fewer joins are done.

## Disadvantave
* Increased possibility of update anomaly.
