![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/6b101735-9618-4a29-af7c-f3dbf6f2473a)<br>
Redis can be thought of as a persistent hashmap.<br>
What sets Redis apart from a normal hashmap is that it can persist data to disk, allowing it to be used as a fault-tolerant, durable datastore.
# Why use Redis cache
- **Exceptional speed**: Redis stores data in RAM instead of secondary memory. This allows Redis to deliver exceptionally fast performance.
- **Persistent data**
- **High Scalability**: Redis is designed to be highly scalable and can handle large amounts of data and concurrent connections. It supports replication and clustering, allowing data to be distributed across multiple Redis instances.
- **Simple key-value data model**

## Usage example
Redis provides an exceptional speed. However, RAM has a limited size, therefore strategies to save the cache space are important.<br>
- Temporary data that is not going to hold the space for long
- Data that requires a faster speed

### `Login session`
**Data structure**: VALUE<session ID, json{session object}>

### `Wishlist`
**Data structure**: VALUE<user ID, product ID>

### `Shopping cart`
It used to be stored as a cookie. However, cookies are only available on web browsers. For broader accessibility, It should be available on any device.<br>
**Data structure**: HASH<user ID, product ID, quantity>
|User ID|Product ID|Quantity|
|---|---|---|
|user1|123|2|
|user1|124|3|
|user2|321|1|

### `Like`
The Like feature requires a fast speed.<br>
Redis stores the user as key so that only one Like per user is allowed for a comment.<br>
**Data structure**: SET<comment ID, users that liked>

### `Tweeter timeline`
This complex query to retrieve tweets that a follower follows can be slow.
~~~sql
SELECT * FROM tweets WHERE user_id IN (SELECT followed_id FROM follows WHERE follower_id = "abc123");
~~~
The result of the query can be cached to enhance the retrieval speed.
~~~python
def get_tweets_for_follower(follower_id):
    # Check if cached data exists for the follower ID
    cached_data = redis.lrange('tweets', 0, -1)

    if cached_data:
        # Retrieve tweets from Redis
        return cached_data
    else:
        # Retrieve tweets of a user that a follower follows
        query = 'SELECT * FROM tweets WHERE user_id IN (SELECT followed_id FROM follows WHERE follower_id = %s)'
        tweets =  DB.execute(query, follower_id)
        # Store tweets in a Redis list
        for tweet in tweets:
            redis.lpush('tweets', tweet)

        return tweets
~~~

#### `Counting unique visitors`
The number of visitors without duplicate records can be counted by storing visitors' ID and counting them.<br>
**Data structure**: LIST<Day, Visitors' ID>

# How to achieve data persistence in Redis
Redis has backup methods because RAM cannot maintain data after being turned off.<br>

- **RDB (Redis Database) Snapshotting**: Snapshots of the dataset at a specific point in time are taken and saved to disk in an RDB file at regular intervals or manually.<br>
This file contains the dataset in a compact manner, resulting in faster disk I/O operations than the AOF method. However, if a system failure happens between two snapshot intervals, there is a possibility of losing the data changes made during that time.
- **AOF (Append-Only File)**: The AOF persistence mode logs every write operation received by Redis, appending it to the end of an AOF file. By replaying these write operations, Redis can reconstruct the dataset from scratch.
- **Hybrid Persistence**: By using both RDB and AOF persistence methods simultaneously, Redis periodically creates RDB snapshots for faster recovery and uses the AOF in case of failures. Hybrid persistence provides a balance between recovery time and data durability.

# Redis data structures in Spring
|Function|Data structure|
|---|---|
|opsForValue(key, value)|String|
|opsForList(key, a,b,c,,,)|List|
|opsForSet(key, a,b,c,,,)|Set|
|opsForZSet(key, a:1, b:2, c:3,,,)|Sorted Set|
|opsForHash(key, key, value)|Hash|

# Redis cluster
Redis cannot have multiple databases in the same way that MySQL does. Use redis instances on multiple ports.

## How to install and run Redis
#### 1. Install redis on Docker:<br>
~~~
docker pull redis
~~~
#### 2. Run Redis:
~~~
docker run -d -p 6379:6379 -v /redis_data:/redis_data --name redis redis redis-server --appendonly yes
~~~
