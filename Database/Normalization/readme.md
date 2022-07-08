## Anomalies
* **Insertion anomaly** : when the primary key is NULL so an unnecessary primary key has to be created
* **Update anomaly** : a data inconsistency that results from data redundancy and a partial update
* **Deletion anomaly** : occurs when a record that contains a tuple is deleted where attributes that shouldn't be deleted may be deleted.

## Data normalization
Database normalization is the process of organizing data into tables in such a way that data redundancy and data integrity is retained.

## Initial table
|name|age|hobby|country|
|---|---|---|
|John|25|soccer, basketball|USA|
|Paul|26|swimming|UK|
|John|25|reading|Korea|
|Maria|25|reading|Japan|

## 1st normal form
An attribute of a table in each row can only have one value.

|name|age|hobby|country|
|---|---|---|---|
|John|25|soccer|USA|
|John|25|basketball|USA|
|Paul|26|swimming|UK|
|John|26|reading|Korea|
|Maria|25|reading|Japan|

## 2nd normal form
A column should not be able to be decided by only one element of a tuple primary key.<br>
In the 1st normal form, the **hobby** can be found with the **name** and **age**(primary key)<br>
But the **name** alone can decide the **country*. (called functional dependency)<br>

To solve this problem, the table should be split into 2 tables..<br>

|name|age|hobby
|---|---|---|
|John|25|soccer|
|John|25|basketball|
|Paul|26|swimming|
|John|26|reading|
|Maria|25|reading|

|name|country|
|---|---|
|John|USA|
|John|USA|
|Paul|UK|
|John|Korea|
|Maria|Japan|

## 3rd normal form
When A->B, B->C then it is called transitive dependency. The table needs to be split to get rid of the problem.

### Initial table
|name|country|native language|
|---|---|---|
|John|USA|english|
|Paul|UK|english|
|Ana|Korea|korean|
|Maria|Japan|japanese|

### 3rd normal form table
|name|country|
|---|---|
|John|USA|
|Paul|UK|
|Ana|Korea|
|Maria|Japan|

|name|native language|
|---|---|
|USA|english|
|UK|english|
|Korea|korean|
|Japan|japanese|

