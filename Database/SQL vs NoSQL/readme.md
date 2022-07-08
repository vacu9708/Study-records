**collection** of NoSQL correspondes to **table** of SQL.<br>
**document** of NoSQL correspondes to **row** of SQL.<br>

A table of an SQL database has a pre-defined **schema** on which data is stored.<br>
On the other hand, a NoSQL database allows new data to be stored on a document because it does not have a schema.<br>

## The difference in the data storage way between SQL and NoSQL
### SQL
![image](https://user-images.githubusercontent.com/67142421/177896991-3d9ef63a-30d7-4c7a-9695-cc48baa8b120.png)

### Features of SQL
1. In an SQL database, data is stored in different tables and connected by the JOIN clause, which decreases the risk of updating duplicate data.
Ex) Updating duplicate data in table1 and forgetting the duplicate data in table2.
2. Thoroughly pre-set schema, which leads to data integrity.
3. The JOIN clause is slow.
4. A definite schema has to be planned in advance and is hard to modify afterwards.

### NoSQSL
![image](https://user-images.githubusercontent.com/67142421/177898003-73e84048-afd7-4979-91f3-798c07ab27fa.png)
### Features of NoSQL
1. NoSQL, where the complicated JOIN clause is not used, is faster than SQL.
2. It does not have a schema, so different types of documents can be stored in a collection (flexible). 
3. A NoSQL database does not have a JOIN clause. Instead, all needed data is stored on a document, which increases the risk of updating duplicate data.

### Horizontal VS Vertical scaling
![image](https://user-images.githubusercontent.com/67142421/177931196-ed491a87-8be9-4cf5-b9f4-a39e2a945974.png)

SQL does not support the horizontal scaling because it requires predefined tables and schemas.

## When to use SQL and NoSQL?
### SQL
* When data is changed often (because in NoSQL updating duplicate data has to be done in all collections)
* When definite schemas are needed

### NoSQL
* When updating duplicate data in multiple collections does not happen often
* When flexible schemas are needed.
* When horizontal scaling is needed (tremendous amount of data)
