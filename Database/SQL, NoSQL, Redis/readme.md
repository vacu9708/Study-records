# SQL
![image](https://user-images.githubusercontent.com/67142421/177896991-3d9ef63a-30d7-4c7a-9695-cc48baa8b120.png)<br>
- **Pre-defined schemas** are required to store data, which is hard to modify after.
- **Normalized tables** are combined by JOIN clauses, which eliminates risks when updating duplicate data (e.g. updating data in table1 and forgetting the duplicate data in table2, e.g. Overhead when updating duplicate data in a table).

# NoSQL
![image](https://user-images.githubusercontent.com/67142421/177898003-73e84048-afd7-4979-91f3-798c07ab27fa.png)<br>
NoSQL prioritizes flexibility, scalability, and performance over strict constraints.<br>
**document** of NoSQL correspondes to **row** of SQL and **collection** of NoSQL correspondes to **table** of SQL.<br>
- Data is stored in **flexible documents** that can have a different structure, which is simpler and improves productivity.
- **JOIN clauses are not used**, therefore read operations are faster than SQL but there are risks when updating duplicate data.

![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/f20345ca-ba70-4e49-915d-ef4ae77c978b)
# Why use Redis database
The primary reason for using Redis is its **exceptional speed**.<br>
- **In-Memory Data Storage**: Redis stores data in RAM instead of on disk. This allows Redis to deliver exceptionally fast performance.
- **High Scalability**: Redis is designed to be highly scalable and can handle large amounts of data and concurrent connections. It supports replication and clustering, allowing data to be distributed across multiple Redis instances. This enables horizontal scaling to handle growing workloads and ensures high availability.
- **Key-Value Data Model**: Redis follows a simple key-value data model.

### How to achieve data persistence in Redis
Main memory cannot maintain the data, so Redis has backup methods.<br>
1. By default Redis regularly saves **snapshots**(Redis Backup file, RDB) of the dataset on disk. This has a problem that data between back points disappears.
2. **AOF**(Append Only File) : a persistence mechanism that allows the Redis server to keep track and log every command executed on the server.
