# How to handle large traffic
# Non blocking I/O
Let's say the server wants to send a customer an order confirmation email.<br>
Instead of handling the email sending process synchronously within the request-response cycle, non-blocking I/O can be utilized to prevent busy waiting.<br>
1. When a customer places an order, the email sending task is added to a message queue.
2. An asynchronous worker retrieves the task from the queue and handles the process.
3. This decoupling allows the application to quickly respond to the customer's request without waiting for the email to be sent(without busy waiting).

# Algorithm optimization
Optimize the time complexity of algorithms

# DB Optimization
This involves denormalizing data, indexing frequently accessed fields, query optimization, query caching, using in-memory DB cache(e.g. Redis).<br>
Query caching refers to caching the results of frequently executed queries to retrieve the data from memory instead of executing the query.<br>

# Scaling
Ensure that the server architecture is designed to scale as the number of users grows.

### Horizontal VS Vertical scaling
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/72d184d4-a383-40ef-b036-0b7e9357cf51)<br>
### Horizontal scaling
The incoming requests are distributed across more instances of the server.<br>

### Vertical scaling
Upgrading a single server's hardware.
#### Disadvantages
- Installing new hardware requires taking the server offline.
- There are physical limits to adding hardware to a single server.
- Failure in one part of the system can result in the entire system dying.

# Load Balancing
Implement load balancing to evenly distribute incoming requests across horizontally scaled servers. This helps prevent any single server from becoming overwhelmed.

# Performance monitoring
Set up monitoring tools to track server performance to know where to apply optimization.

# Content Delivery Network(CDNs)
Instead of serving static content such as images and videos directly from the origin server,<br>

utilize CDNs to cache them in multiple regions and serve them from the fastest network.
