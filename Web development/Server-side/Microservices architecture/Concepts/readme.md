# Monolithic service
If all the functionalities of a project exist in a single codebase, then that application is called a **monolithic**.
### Advantange
Simple to develop and deploy
### Disadvantages
**Tight coupling**: All the problems of the monolith comes from the tight coupling.<br>

# Microservices
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/e4b033c0-4744-4488-bbf2-9bafad8dcde2)

Microservices are made up of a colletction of autonomous services to solve the disadvantages of Monolithic.<br>
Messaging middlewares like Kafka are used to communicate between microservices.<br>
### Advantages
All the advantages come from the decoupling between microservices. The disadvantages of the monolithic are solved.<br>
- **Decoupling**: Changes to one microservice do not impact other microservices
- **Easier to understand**: Understanding each microservice is easier than understanding the logic of a large monolithic application
- **Technology diversity**: The decoupling between microservices allows the use of different technologies for each service
- **Fault isolation and resilience:**: Thanks to the decoupling, failures in one service do not necessarily affect others
- **Scalability**: The decoupling enables individual services to be scaled independently based on demand. Services experiencing high traffic can be scaled horizontally without affecting others
- **Team specialization**: Microservices facilitate team specialization by assigning separate teams to develop and maintain individual services.

# API gateway
API Gateway is a crucial component in a microservices architecture that provides a layer of abstraction between clients and the underlying microservices.<br>
While it is technically possible for clients to send direct requests to microservices, using an API Gateway offers several important benefits:
- `Simplified client interaction`: An API Gateway serves as a single entry point for clients to access multiple microservices. Instead of clients having to interact with individual microservices, they can communicate with the API Gateway. This simplifies the client-side code and reduces the complexity of managing multiple service endpoints.
- `Monitoring and Analytics`: By routing all client requests through the API Gateway, it becomes a centralized point for collecting metrics, monitoring service health, and gathering analytics data. This allows for better visibility into the system.

# Circuit breaker pattern
![image](https://user-images.githubusercontent.com/67142421/235345619-b29d9116-d1aa-4ef3-bd1c-8ebe126c01f0.png)<br>
![image](https://user-images.githubusercontent.com/67142421/235345623-c4b76fa3-1ab6-4625-ab6f-1f9c3f7bfbfa.png)<br>
The circuit breaker is used to prevent a failure(timeout) in one area from causing cascading failures throughout the entire system.<br>
It prevents resources from being unnecessarily wasted both in the calling service and the remote service, which leads to preventing the propagation of the failures.<br>
Without the circuit breaker, if one service starts failing, it can put strain on the calling services as they repeatedly attempt to call the failing service for responses that never come. This can lead to resource exhaustion.
A circuit breaker object monitors its microservices and if it detects a failure, it 
### Process
A circuit breaker keeps track of the responses by wrapping the call to the remote service.
#### `Closed`
During normal operation, when the remote service is responding successfully, the circuit breaker is in a `closed` state.<br>
When in the closed state, the circuit breaker passes the request through to the remote service normally.
#### `Open`
When a remote service returns an error or times out, the circuit breaker increments an internal counter.<br>
If the count of errors exceeds a configured threshold, the circuit breaker switches to an `open` state.<br>
When in the open state, the circuit breaker blocks any further requests to the remote service.
#### `Half-open`
After some configured time, the circuit breaker switches from open to a `half-open` state.<br>
In this state, it lets a few requests pass through to the remote service to check if it’s still unavailable or slow.
- If the error rate or slow call rate is above the configured threshold, it switches back to the open state.
### Sliding window
#### `Use two counters:`
- `successCount:` Maintains the number of successful requests in the current window.
- `failureCount:` Maintains the number of failed requests in the current window.
#### `On each request:`
- If a new result is success, increment the successCount and enqueue the result.
- If a new result is failure, increment the failureCount and enqueue the result.
#### `Snapshot retrieval in O(1):`
If the queue's length exceeds N (window size):
- Dequeue the oldest result.
- If the dequeued result is success, decrement the successCount.
- If the dequeued result is failure, decrement the failureCount.
