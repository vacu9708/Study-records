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
# Why use Redis cache
The primary reason for using Redis is its **exceptional speed**.<br>
- **Exceptional speed**: Redis stores data in RAM instead of secondary memory. This allows Redis to deliver exceptionally fast performance.
- **Persistent data**
- **High Scalability**: Redis is designed to be highly scalable and can handle large amounts of data and concurrent connections. It supports replication and clustering, allowing data to be distributed across multiple Redis instances.
- **Simple key-value data model**

Redis provides much faster speed than normal databases. However, RAM has a limited size, therefore strategies to save the storage such LRU and storing only necessary data are necessary.

### Usage example
- Allowing only one Like per user -> key: comment ID, value: set[users who liked]
- Unique visitors without duplicate records -> Switch visitors' ID to bit 1 and BITCOUNT() to count the number of visitors
- shopping cart of a user, refresh tokens
- #### Query caching:
This nested query to retrieve tweets of a user that a follower follows can be slow.
~~~sql
SELECT * FROM tweets WHERE user_id IN (SELECT followed_id FROM follows WHERE follower_id = "abc123");
~~~
A follower's timeline can be cached in Redis
~~~python
def get_tweets_for_follower(follower_id):
    # Check if cached data exists for the follower ID
    cache_key = f"tweets:{follower_id}"
    cached_data = redis.get(cache_key)

    if cached_data:
        return json.loads(cached_data)
    else:
        # Retrieve tweets of a user that a follower follows
        query = 'SELECT * FROM tweets WHERE user_id IN (SELECT followed_id FROM follows WHERE follower_id = %s)'
        tweets =  DB.execute(query, follower_id)
        # Store the tweets in Redis cache
        redis.set(cache_key, json.dumps(tweet_data))
        # Return the tweet data
        return tweet_data
~~~


### How to achieve data persistence in Redis
RAM cannot maintain data after being turned off, so Redis has backup methods.<br>

- **RDB (Redis Database) Snapshotting**: Snapshots of the dataset at a specific point in time are taken and saved to disk in an RDB file at regular intervals or manually.<br>
This file contains the dataset in a compact manner, resulting in faster disk I/O operations than the AOF method. However, if a system failure happens between two snapshot intervals, there is a possibility of losing the data changes made during that time.
- **AOF (Append-Only File)**: The AOF persistence mode logs every write operation received by Redis, appending it to the end of an AOF file. By replaying these write operations, Redis can reconstruct the dataset from scratch.
- **Hybrid Persistence**: By using both RDB and AOF persistence methods simultaneously, Redis periodically creates RDB snapshots for faster recovery and uses the AOF in case of failures. Hybrid persistence provides a balance between recovery time and data durability.
