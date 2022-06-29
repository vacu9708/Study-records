***CPU Scheduling*** is a process of determining which process will own CPU for execution while another process is on hold<br>
The main task of CPU scheduling is to make sure that whenever the CPU remains idle, the OS at least select one of the processes available in the ready queue 
for execution.<br>

**Short-term scheduler** : Decides which process in the ready queue(main memory) is to be executed.<br>
**Medium-term scheduler** : Remove process from memory, store on disk, bring back in from disk to continue execution. (Storing temporarily in case main memory runs out)
	This is called Swap-in and Swap-out. (swapping)<br>
**Long-term scheduler** : Decides which process is to be put in the ready queue. In other words, Long-term scheduler controls Short-term scheduler.<br>

A **context switch** is storing the state of a process of thread so that it can be resumed at a later point.
![image](https://user-images.githubusercontent.com/67142421/176330810-9567f787-7692-48ff-9d96-0de47d37f664.png)

**preemtive** : A process can take CPU that is being used.

**First-Come, First-Served Scheduling** : The oldest entry is processed first. it has little overhead but can be ineffective due to the waiting time.
**Shortest-Remaining-Time-First Scheduling** : It has overhead but the shortest waiting time. It is hard to know how much time a process will take.
**Short-Job-First** : Only the execution time that was predicted at the beginning is considered without remaining time updated.
**Priority Scheduling** : The most used method. It solves starvation with aging method.
**Round robin** : Puts processes into a round queue where all processses get fair share of CPU. Time quantum must be large to prevent high overhead(on context switching)
