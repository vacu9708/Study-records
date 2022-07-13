**Load balancing** refers to distributing computational load over a set of resources(servers), with the aim of making the processing more efficient.<br>

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
The advantages of adopting *Microservices* are the oppostie of the disadvantages of a monolithic service<br>.
* Each microservice must have a single responsibility to facilitate maintenance.
