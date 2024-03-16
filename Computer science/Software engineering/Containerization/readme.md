# Invention of the container revolutionized the shipping industry
By using containers of a consistent shape, goods could be loaded and unloaded quickly and efficiently, which reduced costs and increased productivity.<br>

![image](https://github.com/vacu9708/Study-records/assets/67142421/cdc4ab70-ec13-42f8-b1a1-6541f1a39afe)

# Docker
Docker is a popular containerization platform for packing an application and its dependencies into a container that can be run on any system that supports Docker.<br>
Docker is commonly used to address difficulties related to environment setting when running an application in different environments.<br>
## Why use Docker
- ### Portability
  Docker containers can run on any system that supports Docker.<br>
  In software development, environment setup often take a long time and is time-consuming. Docker **eliminates the need for manual environment setup.**<br>
- ### Isolation
  Docker containers ensure that the application in each container runs in its own isolated environment.<br>
  This makes it easier to avoid conflicts between different applications.
   
# Why use Docker instead of Virtual machine
- **VMs** simulate a complete operating system (OS) with their own kernel, which leads to a higher overhead and consumes more memory.
- **Docker**, on the other hand, runs applications within isolated containers that share the host OS kernel. Docker containers consume fewer resources than VMs and are lightweight.

## Docker network
Docker containers are isolated. That's why network for docker is needed.
#### `Bridge`
The default network driver. It creates a private network inside the host, which allows different containers to communicate with each other and the host.
#### `Host`
This driver removes network isolation between the container and the Docker host. Containers using the host network directly use the host's IP address.
#### `Overlay`
Used in Docker Swarm to create a network that spans across all the nodes participating in the swarm.
#### `None`
This driver disables all networking.


# Kubernetes
Kubernetes is a container orchestrator, which means that it is a platform designed to automate the deployment, scaling, and management of containerized applications across multiple computers.
  
