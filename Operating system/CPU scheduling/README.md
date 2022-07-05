***CPU Scheduling*** is a process of determining which process will own CPU for execution while another process is on hold<br>
The main task of CPU scheduling is to make sure that whenever the CPU remains idle, the OS at least select one of the processes available in the ready queue 
for execution.<br>

## Objectives of Process Scheduling Algorithm:
* Utilization of CPU at maximum level. i.e. Keep CPU as busy as possible.
* Throughput should be Maximum. i.e. Number of processes that complete their execution per time unit should be maximized.
* Minimum response time. i.e. The time when a process is moved onto the ready queue should be as less as possible.
* Minimum waiting time, i.e. The process should not starve in the ready queue.
* Minimum turnaround time, i.e. Time taken by a process to finish execution should be the least.

## Process states
![image](https://user-images.githubusercontent.com/67142421/177235984-3a7a2698-c758-4fef-93b2-da6b516b13bd.png)

## Context switching
![image](https://user-images.githubusercontent.com/67142421/177234829-9c080823-63e8-450f-b758-74b1e8b9ee29.png)

A CPU can only execute one process at a time.<br>
A **context switch** is to store the state(Process Control Block) of a process or a thread so that it can be resumed at a later point, and then jump to another task<br>
A context switch has an overhead, which needs to be minimized.<br>
>Process Control Block is data structure of OS that stores information on a process for context switching.

* **Premtive scheduling** : A process can take CPU that is being used. ((Processing time is hard to estimate)
* **Non-preemtive scheduling** : A process cannot take CPU that is being used. (Processing time can be estimated easily)

**Short-term scheduler** : Decides which process in the ready queue(main memory) is to be executed.<br>
**Medium-term scheduler** : Remove process from memory, store on disk, bring back in from disk to continue execution. (Storing temporarily in case main memory runs out)
	This is called Swap-in and Swap-out. (swapping)<br>
**Long-term scheduler** : Decides which process is to be put in the ready queue. In other words, Long-term scheduler controls Short-term scheduler.<br>

* **First-Come, First-Served Scheduling** : The oldest entry is processed first. it has little overhead but can be ineffective due to the waiting time.
* **Short-Job-First** : Only the execution time that was predicted at the beginning is considered without remaining time updated.
* **Shortest-Remaining-Time-First Scheduling** : It has overhead but the shortest waiting time. It is hard to know how much time a process will take.
* **Priority Scheduling** : The most used method. It solves starvation with aging method.
* **Round robin** : Puts processes into a round queue where all processses get fair share of CPU. Time quantum must be large to prevent high overhead(on context switching)
