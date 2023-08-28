# Read operations
### Read replicas
Read replicas are duplicate copies of a primary database, primarily used to offload read queries from the primary database. This helps to improve performance by distributing the read load across multiple instances. Read replicas are kept in sync with the primary database, but are not used for write operations due to the race condition to maintain data consistency and integrity.
### Denormalization
(Refer to the normalization explanation in this directory) Good especially for distributed JOINs
### Indexing
(Refer to the indexing explanation in this directory)

# Write operations
Keep in mind the concurrency issues!!
### Asynchronous writes
Send write operations to a kafka topic.<br>
A separate service or consumer then reads from this topic and performs the actual write operations to the database. This decouples the rate of incoming write requests from the rate at which the database is updated

### Batching 
Group multiple write operations into a single batch, reducing the number of transactions per second.

# Common
### Redis
Read and write on Redis instead of the DB
### [Request rate limiting](https://github.com/vacu9708/Fundamental-knowledge/tree/main/Web%20development/Server-side/Rate%20limiting)
### Sharding
Distribute rows across multiple databases, so each "shard" handles a subset of the write load. This can be complex to manage but is effective in distributing writes.
### Query tuning
Query tuning such as LIMIT command
