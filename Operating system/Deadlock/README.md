**Deadlock** is a situation where a set of processes are blocked because each process is holding a resource and waiting for another resource acquired by some other process.<br>

## 4 conditions of deadlock
1. mutual exclusion : Only one process for a resource
2. hold and wait : Holding a resource while waiting
3. no preemption : A picked process cannot be taken
4. circular wait : Waiting for a resource that is held by another process “together”

## Dining philosopher problem
![image](https://user-images.githubusercontent.com/67142421/176333583-a1ffafd2-a73b-4a73-bbe4-706c0e076d25.png)

It can be described with either forks or chopsticks.
The problem was designed to illustrate the challenges of avoiding deadlock.<br>

>The dining philosophers problem states that there are 5 philosophers sharing a circular table and they eat and think alternatively.<br>
>A hungry philosopher may only eat if there are both chopsticks available. Otherwise a philosopher puts down their chopstick and begins thinking again.<br>
>The dining philosophers is a classic synchronization problem as it demonstrates a large class of concurrency control problems.<br>

## Deadlock prevention: 
1. Mutual exclusion banned (almost impossible because mutual exclusion is usually essential)
2. Obtaining all resources needed before beginning to perform a process.
3. Resources can be obtained only when they are not taken. (though ineffective)
4. Release all resources that are being used,
5. Resources request are allowed only in a fixed order.

## How philosophers behave
1. think until the left chopstick is available; when it is, pick it up;
2. think until the right chopstick is available; when it is, pick it up;
3. He picks up another chopstick too
4. when both forks are held, eat for a fixed amount of time;
5. put the left fork down;
6. put the right fork down;
7. repeat from the beginning.

**This satisfies all of the 4 conditions of deadlock**

## Solution of Dining Philosophers Problem
1. Don't allow all philosophers to eat/think at once so that there are always remaining chopsticks
2. Pick up both chopsticks (in a critical section)
3. Alternate choice of first chopstick (Either left or right chopstick can be picked up)

## Banker's algorithm 
A deadlock avoidance algorithm that avoids a deadlock by only allocating available resources that can finish a task.<br>

### Example
![image](https://user-images.githubusercontent.com/67142421/176335355-321373a4-e7db-429f-9728-f2e3bdd1c302.png)<br>
P0 has been allocated A:0, B:1, C:0 and needs A:7, B:4, C:3 to finish the task. But the available resources are only A:3, B:3, C:2, so the task cannot be completed
for the moment.<br>
P1 can complete its take if it obtains A:1, B:2, C:2 and return Max(A:3, B:2, C:2). The available resources satisfy the completion condition of P1, so the task
of P1 is completed and the available resources become A:5, B:3, C:2 (because A:2 is given from A:3, B:2, C:2)
