An **interrupt** is a request for the processor to temporarily halt the current task and switch to another task with a higher priority."
 
- **external interrupt(hardware interrupt)** happens as a result of outside interference such as from the user or from the peripherals. It functions as a notifier.
- **internal interrupt**, also called Trap, happens when wrong instructions or data are used. (exceptions like divided by zero, overflow)
- **software interrupt(system call)**: is a type of interrupt that is triggered by a specific instruction in a program, rather than by an external event or hardware malfunction.
It's a mechanism for a program to interrupt the current process flow and request a service from the operating system.<br>
A program running in user mode needs to send a system call to the operating system to access system resources and perform tasks in kernel mode.

## The steps of an interrupt
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/95593a56-af6a-407f-8c8b-0e9e166045a4)

1. An interrupt occurs
2. Current program status is saved onto a stack
3. Jump to the interrupt vector
4. The interrupt is processed
5. Jump to the previous program

## polling VS (vectored) interrupt
* **polling** : Each interrupt is checked by one by one in an infinite loop. This busy-waiting causes overheads.
### Example
~~~python
while True:
  if request==0:
    response0()
  elif request==1:
    response1()
  else
    response2()
~~~

* **(vectored)interrupt** : A hardware device notifies that an interrupt has occured. (more effective)
This method has a limit that a hardware support is needed. But it is much faster than polling, so it is essential for real-time response.
