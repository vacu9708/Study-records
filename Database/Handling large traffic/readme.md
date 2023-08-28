# Read operations
### Read replicas
### Denormalization
Especially for distributed JOINs
### Indexing

# Write operations
Keep in mind the concurrency issues!!
### Asynchronous writes
Write to a queue (like Kafka) to update the database asynchronously.

### Batching 

# Common
### Redis
Write to Redis instead of the DB
### Request rate limiting
### Sharding
Distribute rows across multiple databases, so each "shard" handles a subset of the write load. This can be complex to manage but is effective in distributing writes.
### Query tuning
Query tuning for example LIMIT command
