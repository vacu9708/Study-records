# Load balancing
![image](https://user-images.githubusercontent.com/67142421/178641574-83f7e9d2-98e5-4996-a2ff-150741741bbe.png)<br>
It refers to distributing computational load over a set of servers, with the aim of making the processing more efficient.<br>
## Load balancing algorithms
1. **Round Robin** : one of the simplest and most used load balancing algorithms where a client request is forwarded to each server in turn
2. **Least Connection** : distributing client requests to the server with the least number of active connections at the time the client request is received.
3. **Source** : Distribtuing client requests by hashing clients' IP, which ensures a specific client is connected to the same server. 

## Monolithic service
If all the functionalities of a project exist in a single codebase, then that application is called a *monolithic*.
### Disadvantages
* Even a small change makes the whole application need to be redeployed.
* For any new developer joining the project, it is very difficult to understand the logic of a large Monolithic application even if their responsibility is related to a single functionality.
* Load balancing is difficult because the whole code has to be in a server.
### Advantange
Simple to develop and deploy

## Microservices
It is an architectural style in which an application is made up of a colletction of autonomous services.<br>
The advantages of adopting *Microservices* are the oppostie of the disadvantages of a monolithic service.
* Each microservice must have a single responsibility to facilitate maintenance.
