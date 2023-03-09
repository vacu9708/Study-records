# concurrency
Concurrency refers to performing multiple tasks at the same time by dividing as task into smaller sub-tasks and executing them concurrently. they ***appear*** to be executed simultaneously to the user.

# Parallelism
Parallelism refers to performing multiple tasks really at the same time by executing them simultaneously on multiple processing units.

# Synchronous programming
Each statement of code is executed one after the other.(blocking)

# Asynchronous programming
Asynchronous programming allows a single thread to manage multiple tasks.(non-blocking) It can be implemented with either concurrency and paralleism.

# Blocking
When a function B was called in function A, A is stopped until B finishes.
~~~python
def A():
  print("A")
  def B():
    time.sleep(5)
    print("B")
  B() # Blocked
~~~
**blocking I/O** : When a thread calls an I/O request, All the thread can do is wait, which leads to a waste of CPU because I/O operation hardly uses CPU.

# Non-blocking
When a function B was called in function A, A is not stopped after B is executed.
~~~python
def A():
  print("A")
  def B():
    print("B")
  B()
~~~
## Non-blocking I/O
When a thread performs an I/O request, the thread does not have to wait for the I/O operation to be completed.<br>
A single thread manages and wait for multiple I/O channels but the actual I/O operations are performed by separate threads, one thread per channel.
