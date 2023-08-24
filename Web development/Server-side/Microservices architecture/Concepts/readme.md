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
![image](https://user-images.githubusercontent.com/67142421/235345619-b29d9116-d1aa-4ef3-bd1c-8ebe126c01f0.png)
![image](https://user-images.githubusercontent.com/67142421/235345623-c4b76fa3-1ab6-4625-ab6f-1f9c3f7bfbfa.png)

The circuit breaker is used to prevent a failure(timeout) in one area from causing cascading failures throughout the entire system.<br>
A circuit breaker object monitors its microservices and if it detects a failure, it blocks any further requests to the microservice.<br>
Instead, it returns a pre-configured fallback response or exception.<br>
