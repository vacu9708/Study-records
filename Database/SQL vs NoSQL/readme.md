# SQL
![image](https://user-images.githubusercontent.com/67142421/177896991-3d9ef63a-30d7-4c7a-9695-cc48baa8b120.png)<br>
More reliable database type than NoSQL
- **Pre-defined schemas** are required to store data, which is hard to modify after.
- **Normalized tables** are combined by JOIN clauses, which eliminates the data redundancy problem.

# NoSQL
![image](https://user-images.githubusercontent.com/67142421/177898003-73e84048-afd7-4979-91f3-798c07ab27fa.png)<br>
NoSQL prioritizes flexibility, scalability, and performance over strict constraints.<br>
**document** of NoSQL corresponds to **row** of SQL and **collection** of NoSQL corresponds to **table** of SQL.<br>
- Data is stored in **flexible** documents that can have a different structure, which is simpler and improves productivity.
- **Denormalization** is preferred. Therefore there are strengths and weaknesses related to it.

# Why use NoSQL which is less reliable than SQL?
NoSQL is great for distributed systems(microservices).
### Reduced Join Operations
In a normalized database, data is often spread across multiple tables, and retrieving a complete record might require joining several tables together. In a distributed system, these tables might be located on different nodes, making join operations expensive and slow.<br>
Denormalization, by storing related data together in a single record, eliminates or reduces the need for these join operations, making distributed queries faster and more efficient.
