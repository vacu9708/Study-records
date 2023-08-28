# Read operations
### Indexing
([Refer to this](https://github.com/vacu9708/Fundamental-knowledge/tree/main/Database/Indexing)) The most basic and effective
### Denormalization
([Refer to this](https://github.com/vacu9708/Fundamental-knowledge/tree/main/Database/Normalization))Good especially for distributed JOINs
### Read replicas
Read replicas are duplicate copies of a primary database, primarily used to offload read queries from the primary database. This helps to improve performance by distributing the read load across multiple instances. Read replicas are kept in sync with the primary database, but are not used for write operations due to the race condition to maintain data consistency and integrity.

# Write operations
Replicas are challenging due to the concurrency issues!
### Asynchronous writes
Send write operations to a kafka topic.<br>
A separate service or consumer then reads from this topic and performs the actual write operations to the database. This decouples the rate of incoming write requests from the rate at which the database is updated

### Batching 
Group multiple write operations into a single batch, reducing the number of transactions per second.

# Common
### Redis
([Refer to this](https://github.com/vacu9708/Fundamental-knowledge/tree/main/Database/Redis))
Read and write using Redis instead of DB.<br>
Use Redis without DB for temporary data, use Redis in conjunction with DB for caching
### Request rate limiting
([Refer to this](https://github.com/vacu9708/Fundamental-knowledge/tree/main/Web%20development/Server-side/Rate%20limiting))
### Query tuning
Query tuning such as LIMIT command
### Sharding
Distribute rows across multiple databases, so each "shard" handles a subset of the write load. This can be complex to manage but is effective in distributing writes.
