* **Spinlock** is to make a thread trying to acquire a shared resource wait in a loop until it is available.(busy waiting)
# Deadlock
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/950cfd23-dbcc-4fab-8e62-8092ffcb0cae)

Deadlock is a situation where processes are waiting for each other to release their shared resource and none of them ever does.<br>
Improper synchronization results in deadlock.

### 4 conditions of deadlock
1. **Mutual Exclusion**: Only one process can hold a resource at a time
2. **Hold and wait**: Holding a resource while waiting
3. **No preemption**: A held resource cannot be forcefully taken away
4. **Circular wait**: Processes are waiting for resources held by each other.

### Deadlock prevention:
Deadlock can be avoided by getting rid of one of the 4 conditions of deadlock.<br>
1. **Mutual Exclusion**: Allow multiple processes to access shared resources simultaneously.
2. **Hold and wait**: Require processes to acquire all necessary resources before execution, eliminating the possibility of holding a resource while waiting for others.
3. **No preemption**: Allows resources to be forcibly taken away from processes.
4. **Circular wait**: Assign a unique numerical identifier to each resource and require processes to request resources in ascending order of these identifiers.
#### Example of circular wait solution:
Let's say resource 2 has a higher priority.
1. Process 1, holding resource 1, realizes it needs resource 2 to proceed.
2. Since resource 2 has a higher identifier than resource 1, Process 1 decides to release resource 1.
3. Process 2, holding resource 2, can now acquire resource 1
4. Process 2 completes its task and releases both resource 1 and resource 2.
5. Process 1 can now acquire resource 2 and continue its execution.

## Banker's algorithm 
Banker's algorithm ensures that resource requests will not lead to deadlock by checking whether the system will be in a safe state before granting resource allocation.<br>
It checks if resources can be allocated without causing a resource shortage to prevent the deadlock.

### Example
![image](https://user-images.githubusercontent.com/67142421/176335355-321373a4-e7db-429f-9728-f2e3bdd1c302.png)<br>
Max = Need + Allocation<br>
1. P0 has been allocated A:0, B:1, C:0 and needs A:7, B:4, C:3 to complete its task.
2. However, there are only A:3, B:3, C:2 available, so P0 cannot be completed at the moment.
3. P1 can be completed because it needs A:1, B:2, C:2, which can be satisfied using the available resources.
4. P1 is completed and its allocated resources (A:2, B:0, C:0) are released and added to the available resources, which becomes A:5, B:3, C:2.
## Dining philosopher problem
![image](https://user-images.githubusercontent.com/67142421/176333583-a1ffafd2-a73b-4a73-bbe4-706c0e076d25.png)

[공부!!](https://m.blog.naver.com/hirit808/221788147057)
It can be described with either forks or chopsticks.
The problem was designed to illustrate the challenges of avoiding deadlock.<br>

>The dining philosophers problem states that there are 5 philosophers sharing a circular table and they eat and think alternatively.<br>
>A hungry philosopher may only eat if there are both chopsticks available. Otherwise a philosopher puts down their chopstick and begins thinking again.<br>
>The dining philosophers is a classic synchronization problem as it demonstrates a large class of concurrency control problems.<br>

### How philosophers behave
1. think until the left chopstick is available; when it is, pick it up;
2. think until the right chopstick is available; when it is, pick it up;
3. He picks up another chopstick too
4. when both forks are held, eat for a fixed amount of time;
5. put the left fork down;
6. put the right fork down;
7. repeat from the beginning.

**This satisfies all of the 4 conditions of deadlock**

## Solution of Dining Philosophers Problem
1. **Mutual Exclusion**: Cannot be allowed because it is a basic condition of the problem.
2. **Hold and wait**: A philosopher must acquire both chopsticks simultaneously. 
3. **No preemption**: Cannot be allowed because this is a basic condition of the problem.
4. **Circular wait**: The "resource hierarchy" approach can be used. Assign a unique identifier to each and require the philosophers to always acquire the chopsticks in a defined order.
