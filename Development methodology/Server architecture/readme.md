# Load balancing
![image](https://user-images.githubusercontent.com/67142421/178641574-83f7e9d2-98e5-4996-a2ff-150741741bbe.png)<br>
It refers to distributing computational load over a set of servers, with the aim of making the processing more efficient.<br>
## Load balancing algorithms
1. **Round Robin** : one of the simplest and most used load balancing algorithms where a client request is forwarded to each server in turn
2. **Least Connection** : distributing client requests to the server with the least number of active connections at the time the client request is received.
3. **Source** : Distribtuing client requests by hashing clients' IP, which ensures a specific client is connected to the same server. 

## Monolithic service
If all the functionalities of a project exist in a single codebase, then that application is called a **monolithic**.
### Advantange
- Simple to develop and deploy
### Disadvantages
- Even a small change makes the whole application have to be redeployed.
- It is very difficult to understand the logic of a large Monolithic application even if their responsibility is related to a single functionality, which leads to ***difficult to maintain***
- Load balancing is difficult because the whole code is in one server.
- Tech stacks and the application are tightly coupled, so it becomes deprecated code.

## Microservices
Microservices are made up of a colletction of autonomous services.<br>
The advantages and disadvantages are the opposite to those of Monolithic.
