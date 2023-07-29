## A process consists of
![image](https://user-images.githubusercontent.com/67142421/177061507-70e77e7f-1af0-4d3c-92a8-b0b5ba706bc2.png)

- **Code** : stroes the instructions of the program
- **Data** : stroes static data
- **Heap** : stores dynamically allocated data
- **Stack** : stores temporary data created by a function

A process has at least a thread(including the main thread).<br>
## The difference between process and thread
* A **process** is a flow of code that has resources allocated for itself.
* A **thread** is a flow of code that shares resources with other threads.<br>

## Multi threading VS Multi processing
* **Multi processing** : when two or more processors cooperate.
* **Multi threading** : when a process executes multiple threads. The synchronization of shared resources should be taken good care of in multi threading.
### Why can multi threading be better
1. The system call to allocate resources for a process can be less executed, which allows effectively managing resources.
2. Communication between threads takes less cost than Inter Process Communication.

## fork() VS vfork()
* fork() : The memory of the parent process is copied. (like deep copy)
* vfork() : The memory is shared with the parent process. Memory is not copied, so it is created faster. But it can cause a race condition because the memory is shared.(like shallow copy)

## Threading pool
A group of threads that can be taken when needed and reused, which is used because creating and destroying threads causes a big overhead.
