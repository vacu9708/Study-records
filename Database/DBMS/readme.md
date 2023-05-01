Database Management Systems (DBMS) are software systems used to store, retrieve, and run queries on data.

# The language of DBMS
- ## DDL: Data Definition Language
is used to create and modify objects in a database using predefined commands and a specific syntax.
Ex) CREATE, ALTER, DROP, RENAME
- ## DML: Data Manipulation Language 
is used for manipulating data in a database.
Ex) SELECT, INSERT, UPDATE, DELETE
- ## DCL: Data Control Language
is used to control access to data stored in a database (authorization).
Ex) GRANT, REVOKE

# Data integrity
When designing a database, ***maintaining data integrity*** is the most important, which can be achieved through methods such as data backup, data validation, integrity constraints, etc.<br>
It is one of the roles of DBMS to ensure that the data constraints are satisfied.

# Constraints for Data Integrity
## Entity integrity constraints
The Entity Integrity Constraint ensures that the primary key cannot be null so that it can be used to identify tuples in a table.
## Referential Integrity Constraints
Referential integrity states that all references are valid by requiring that the referenced value exist.
- Cascading deletion
- Set null
- Preventing the deletion
## Domain constraint
is a limit on the values that a certain variable can take
## Key constraint
Any tuple cannot be the same
## Constraints on nulls
By default, a column can hold NULL values. The NOT NULL constraint enforces a column to NOT accept NULL values.

# Connection pooling
When an application makes a request to a database, it needs to establish a connection to the database server. Establishing a new connection can be a time-consuming process.<br>
Connection pooling helps to address these issues by creating a pool of reusable connections.

![image](https://user-images.githubusercontent.com/67142421/224173321-b0e04d35-7562-4773-8d18-4ba81a861426.png)

