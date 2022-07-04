## A process consists of
![image](https://user-images.githubusercontent.com/67142421/177061507-70e77e7f-1af0-4d3c-92a8-b0b5ba706bc2.png)

* **Code** : literally stroes the code.
* **Heap** : stores dynamically allocated variables.
* **Data** : stroes global variables.
* **Stack** : stores local variables, that is to say, stores the variables of a function.

A process has at least a thread(including the main thread).<br>
## The difference between process and thread
* A **process** is a task in memory that has resources allocated for itself.
* On the other hand, a **thread** is a flow within a process that shares resources with other threads.<br>

### Why data and stack segments are separated?
Each thread needs a stack segment to manage local allocation.<br>
But the data segment that has global variables should not be separated and needs to be shared to save memory.<br>

## Context switching
A CPU can only execute one process at a time.<br>
A **context switch** is to store the state of a process or a thread so that it can be resumed at a later point, and then jump to another task<br>
A context switch has an overhead, so it needs to be minimized.

## Multi threading VS Multi process
* **Multi threading** : when a process executes multiple threads .
* **Multi process** : when two or more processors cooperate and process one or more tasks.<br>
