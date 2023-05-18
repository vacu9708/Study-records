# Monolithic service
If all the functionalities of a project exist in a single codebase, then that application is called a **monolithic**.
### Advantange
- Simple to develop and deploy
### Disadvantages
- Even a small change makes the whole application have to be redeployed.
- It is very difficult to understand the logic of a large Monolithic application even if their responsibility is related to a single functionality, which leads to ***difficult to maintain***
- Load balancing is difficult because the whole code is in one server.
- The application is ***tightly coupled*** and hard to modify, so it easily becomes deprecated code.

# Microservices
Microservices are made up of a colletction of autonomous services. Various tech stacks are needed to develop microservices.<br>
- Advantages and disadvantages: the opposite to those of Monolithic.<br>
- Messaging middlewares are used to communicate between microservices.<br>

# Circuit breaker pattern
![image](https://user-images.githubusercontent.com/67142421/235345619-b29d9116-d1aa-4ef3-bd1c-8ebe126c01f0.png)
![image](https://user-images.githubusercontent.com/67142421/235345623-c4b76fa3-1ab6-4625-ab6f-1f9c3f7bfbfa.png)

It is used to handle failures in microservices and prevent them from causing cascading failures throughout the system.<br>
A circuit breaker object monitors its microservice and if it detects a faulure, it blocks any further requests to the microservice.<br>
Instead, it returns a pre-configured fallback response or exception.<br>

# Sagas pattern
Using the Sagas pattern, each local transaction is implemented as a separate step in a saga.<br>
If a local transaction fails, the saga coordinator triggers a compensation for each already executed local transaction to undo their effects.<br>
This helps to ensure that the transaction across microservices is completed successfully, even if there are failures.<br>

# Distributed tracing
Distributed tracing is a technique for monitoring and debugging microservices that allows for tracing a request as it travels through multiple services.
Distributed tracing is used for two asepcts across microservices:
- Performance monitoring
- Troubleshooting
