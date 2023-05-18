# SQL
![image](https://user-images.githubusercontent.com/67142421/177896991-3d9ef63a-30d7-4c7a-9695-cc48baa8b120.png)<br>
- SQL databases require pre-defined schemas on which data is stored, which is hard to modify after.
- Schemas are normalized and connected by JOIN clauses, which maintains data integrity when updating duplicate data.
- Horizontal scaling is challenging or impossible.
### When to use SQL
When data integrity is crucial such as in banks

# NoSQL
![image](https://user-images.githubusercontent.com/67142421/177898003-73e84048-afd7-4979-91f3-798c07ab27fa.png)<br>
- **document** of NoSQL correspondes to **row** of SQL and **collection** of NoSQL correspondes to **table** of SQL
- Data is stored in flexible documents that can have a different structure.
- JOIN clauses are not used to combine normalized tables, so it is faster than SQL but data integrity is not guaranteed when updating duplicate data.
- For horizontal scaling, all that needs to be done is just split collections.

### When to use NoSQL
- When horizontal scaling is important

# Horizontal VS Vertical scaling
![image](https://user-images.githubusercontent.com/67142421/177931196-ed491a87-8be9-4cf5-b9f4-a39e2a945974.png)

In SQL the horizontal scaling is difficult because spliting related tables takes a big cost

# Redis
Normal database stores data in secondary memory.<br>
On the other hand, Redis, which stands for Remote Dictionary Server, is a fast, open source, key-value database whose data is stored in main memory.<br>

# How to maintain database persistence
Main memory cannot maintain the data, so Redis has backup methods.<br>
1. By default Redis regularly saves **snapshots**(Redis Backup file, RDB) of the dataset on disk. This has a problem that data between back points disappears.
2. **AOF**(Append Only File) : a persistence mechanism that allows the Redis server to keep track and log every command executed on the server.
