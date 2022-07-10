* **Synchronous** : When tasks are synchronous, one task has to end so that another task can start.
* **Asynchronous** : When tasks are asynchronous. they can be executed at the same time.

### Blocking
When a function B was called in function A, A is stopped until B finishes.
~~~python
def A():
  print("A")
  def B():
    time.sleep(5)
    print("B")
  B() # Blocked
~~~

### Non-blocking
When a function B was called in function A, A is not stopped after B is executed.
~~~python
def A():
  print("A")
  def B():
    print("B")
  B()
~~~

Load balancing : refers to efficiently distributing network traffic across a group of servers.
