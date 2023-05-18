# SQL
![image](https://user-images.githubusercontent.com/67142421/177896991-3d9ef63a-30d7-4c7a-9695-cc48baa8b120.png)<br>
- Pre-defined schemas are required to store data, which is hard to modify after.
- Data integrity is guaranteed as a result of ACID transactions, data constraints, etc.
- Normalized tables are combined by JOIN clauses, which guarantees data integrity by eliminating the risk of updating duplicate data (e.g. updating data in table1 and forgetting the duplicate data in table2).
- Horizontal scaling is challenging because guaranteeing data integrity on queries across multiple servers is difficult.
### When to use SQL
When data integrity is crucial such as in banks

# NoSQL
![image](https://user-images.githubusercontent.com/67142421/177898003-73e84048-afd7-4979-91f3-798c07ab27fa.png)<br>
NoSQL prioritizes flexibility, scalability, and performance over strict constraints.<br>
**document** of NoSQL correspondes to **row** of SQL and **collection** of NoSQL correspondes to **table** of SQL.<br>
- Data is stored in flexible documents that can have a different structure.
- Data integrity is not guaranteed. (Instead of relying solely on database consistency, application-level compensation can be used)
- JOIN clauses are not used, so it is faster than SQL but data integrity is not guaranteed because of the risk when updating duplicate data.
- Horizontal scaling just requires spliting collections.
### When to use NoSQL
- When horizontal scaling is in mind

# Horizontal VS Vertical scaling
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/72d184d4-a383-40ef-b036-0b7e9357cf51)<br>
### Horizontal scaling
Data is partitioned across multiple servers.<br>

### Vertical scaling
Upgrading a single server's hardware.
#### Disadvantages
- Installing new hardware requires taking the server offline.
- There are physical limits to adding hardware to a single server.
- Failure in one part of the system can result in the entire system dying.

# Redis
Normal database stores data in secondary memory.<br>
On the other hand, Redis, which stands for Remote Dictionary Server, is a fast, open source, key-value database whose data is stored in main memory.<br>

# How to maintain database persistence
Main memory cannot maintain the data, so Redis has backup methods.<br>
1. By default Redis regularly saves **snapshots**(Redis Backup file, RDB) of the dataset on disk. This has a problem that data between back points disappears.
2. **AOF**(Append Only File) : a persistence mechanism that allows the Redis server to keep track and log every command executed on the server.
