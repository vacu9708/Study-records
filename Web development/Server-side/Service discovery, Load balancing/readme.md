# Service discovery
The abstraction and decoupling are the key reason for using the service discovery mechanism.<br>
Service discovery promotes loose coupling between multiple instances of a service. Services can discover and communicate with each other without tight coupling to specific IP addresses
- `Load balancing`: Service discovery enables load balancing by distributing incoming requests across multiple instances of a service by the abstraction, that is, service name.
- `Fault tolerance and resilience`: Service discovery enhances fault tolerance and resilience. In case a service instance fails, the service discovery mechanism can detect the failure and route requests to healthy instances.

# Load balancing
![image](https://user-images.githubusercontent.com/67142421/178641574-83f7e9d2-98e5-4996-a2ff-150741741bbe.png)<br>
Load balancing refers to **evenly** distributing incoming network traffic across multiple servers.<br>
Horizontal scaling is complemented by load balancing to evenly, efficiently distribute traffic across the expanded server infrastructure.<br>
## Load balancing algorithms
1. **Round Robin** : one of the simplest and most used load balancing algorithms where a client request is forwarded to each server in turn
2. **Least Connection** : distributing client requests to the server with the least number of active connections at the time the client request is received.
3. **Source** : Distribtuing client requests by hashing clients' IP, which ensures a specific client is connected to the same server. 
