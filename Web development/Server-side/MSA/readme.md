# Monolithic service
If all the functionalities of a project exist in a single codebase, then that application is called a **monolithic**.
### Advantange
Simple to develop and deploy
### Disadvantages
**Tight coupling**: All the problems of the monolith comes from the tight coupling.<br>

# Microservices
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

# Circuit breaker pattern
![image](https://user-images.githubusercontent.com/67142421/235345619-b29d9116-d1aa-4ef3-bd1c-8ebe126c01f0.png)
![image](https://user-images.githubusercontent.com/67142421/235345623-c4b76fa3-1ab6-4625-ab6f-1f9c3f7bfbfa.png)

It is used to handle failures in microservices and prevent them from causing cascading failures throughout the system.<br>
A circuit breaker object monitors its microservice and if it detects a faulure, it blocks any further requests to the microservice.<br>
Instead, it returns a pre-configured fallback response or exception.<br>

# Sagas pattern
Using the Sagas pattern, each local transaction at a microservice is performed as a separate step in a saga.<br>
If a local transaction fails, the saga coordinator triggers a compensation for each already executed local transaction to undo their effects.<br>
This helps to ensure that the transaction across microservices is completed successfully, even if there are failures.<br>

# Distributed tracing
Distributed tracing is a technique for monitoring and debugging microservices, allowing for tracing a request as it travels through multiple services.
Distributed tracing is used for two asepcts across microservices:
- Performance monitoring
- Troubleshooting
