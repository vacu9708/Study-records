An **interrupt** is a request for the processor to interrupt the currently executing task to switch to another task with a higher priority.<br>
 
* An **external interrupt** happens as a result of outside interference such as from the user or from the peripherals.
* An **internal interrupt**, also called Trap, happens when wrong instructions or data are used. (exceptions like divided by zero, overflow)
* A **software interrupt** happens when a program is executed for it to be processed by time-sharing.

## The steps of an interrupt
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/95593a56-af6a-407f-8c8b-0e9e166045a4)

1. An interrupt occurs
2. Current program status is saved onto a stack
3. Jump to the interrupt vector
4. The interrupt is processed
5. Jump to the previous program

## polling VS (vectored) interrupt
* **polling** : Each interrupt is checked by software one by one in an infinite loop. This busy-waiting causes overheads.
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

A **system call** is an interface for a program to access a service from the OS. (it's not an interrupt)
