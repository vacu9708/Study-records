# How to handle large traffic
### Non blocking I/O
Instead of handling the email sending process synchronously within the request-response cycle, non-blocking I/O can be utilized to prevent busy waiting.
1. When a customer places an order, the email sending task is added to a message queue.
2. An asynchronous worker retrieves the task from the queue and handles the process.
3. This decoupling allows the application to quickly respond to the customer's request without waiting for the email to be sent(without busy waiting).

### Algorithm optimization
Optimize the time complexity of algorithms

### DB Optimization
This involves denormalizing data, indexing frequently accessed fields, query optimization, query caching, using in-memory DB cache(e.g. Redis).<br>
Query caching refers to caching the results of frequently executed queries to retrieve the data from memory instead of executing the query.<br>

### Content Delivery Network(CDNs)
Instead of serving static content such as images, videos directly from the origin server,<br>
utilize CDNs to store static content like images and videos in multiple regions and serve them from the fastest network.

### Scaling
Ensure that the server architecture is designed to scale as the number of users grows.

### Load Balancing
Implement load balancing techniques to evenly distribute incoming requests across multiple servers. This helps prevent any single server from becoming overwhelmed.

### Performance monitoring
Set up monitoring tools to track server performance to know where to apply optimization.
