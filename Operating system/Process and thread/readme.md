# A process consists of
![image](https://user-images.githubusercontent.com/67142421/177061507-70e77e7f-1af0-4d3c-92a8-b0b5ba706bc2.png)

- **Code** : stores the instructions of the program
- **Data** : stores static data
- **Heap** : stores dynamically allocated data
- **Stack** : stores temporary data created by a function

A process has at least a thread(including the main thread).<br>
## The difference between process and thread
* A **process** is a flow of code that has resources allocated for itself.
* A **thread** is a flow of code that shares resources with other threads.

# Multi threading VS Multi processing
* **Multi processing** : when two or more processors cooperate.
* **Multi threading** : when a process executes multiple threads. The synchronization of shared resources should be taken good care of in multi threading.
### Why can multi threading be better
1. The system call to allocate resources for a process can be less executed, which allows effectively managing resources.
2. Communication between threads takes less cost than Inter Process Communication.

# Process life cycle
The process life cycle refers to the various stages that a process goes through from its initiation to its termination.<br>
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/9dc70cc5-c03b-4209-8909-d0e47fc649a6)<br>
1. New: The process is being created.
2. Ready: The process is ready to be scheduled for execution.
3. Running: The process is currently executing.
4. Waiting: The process is waiting for an event to occur, like I/O completion.
5. Terminated: The process has finished execution.

# Threading pool
A group of threads that can be taken when needed and reused, which is used because creating and destroying threads causes a big overhead.<br>
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/cad1ae03-a0d7-4368-9347-a47f9cf5da8e)

## Child process
A "child process" in computing refers to a process that is created by another process (known as the parent process) during the course of its execution. This creation is typically done through a system call such as fork() in Unix-like operating systems.
- fork() : The memory of the parent process is copied. (like deep copy)
- vfork() : The memory is shared with the parent process. Memory is not copied, so it is created faster. But it can cause a race condition because the memory is shared.(like shallow copy)
