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

# Saga pattern
Using the Saga pattern, each local transaction at a microservice is performed as a separate step in a saga.<br>
If a local transaction fails, the saga coordinator triggers a compensation for already executed local transactions to undo their effects.<br>
This helps to ensure that the transactions across microservices are either successfully completed or compensated even if there are failures.<br>

### Distributed transaction
The term "saga" in the saga pattern refers to a sequence of local transactions or steps.
1. `Start`: A distributed transaction is triggered.
2. `Local transactions`: The saga includes local transactions such as payment, setting the stock, placing the order.
3. `Compensation`: If a step failed, compensation actions that undo the previously succeded steps are invoked, ensuring data consistency.
4. `Completion`: The saga concludes when all the steps are either successfully completed or compensated.

### Compensation after distributed transactions failed because of system failures (like unexpected shutdowns)
Keep logging of the start and end of each local transaction and automate the compensation of local transactions that did not end after system failures.

# Circuit breaker pattern
![image](https://user-images.githubusercontent.com/67142421/235345619-b29d9116-d1aa-4ef3-bd1c-8ebe126c01f0.png)
![image](https://user-images.githubusercontent.com/67142421/235345623-c4b76fa3-1ab6-4625-ab6f-1f9c3f7bfbfa.png)

It is used to handle failures in microservices and prevent them from causing cascading failures throughout the system.<br>
A circuit breaker object monitors its microservice and if it detects a faulure, it blocks any further requests to the microservice.<br>
Instead, it returns a pre-configured fallback response or exception.<br>
