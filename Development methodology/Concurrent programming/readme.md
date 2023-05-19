# Concurrent programming
Concurrenct programming refers to dividing a task into smaller subtasks and processing them at the same time. Concurrency involves both actual and apparent simultaneous execution of multiple tasks.<br>

# Parallel programming
Parallel programming refers to breaking a task into subtasks and processing them **actually** at the same time on separate processing units.<br>

---
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

---
# Synchronous programming
Each task is executed one after the other.(blocking)

# Asynchronous programming
Asynchronous programming allows a single thread to manage multiple tasks in a non-blocking manner. It can be implemented with either concurrency and parallelism.

## Non-blocking I/O
When a thread performs an I/O request, the thread does not have to wait for the I/O operation to be completed.<br>
A single thread manages and wait for multiple I/O channels but the actual I/O operations are performed by separate threads, one thread per channel.

### Example of Non-blocking I/O with Asynchronous programming
~~~javascript
async function fetchMultipleData() {
  try {
    console.log('Fetching data from multiple APIs...');

    const urls = [
      'https://api.example.com/data1',
      'https://api.example.com/data2',
      'https://api.example.com/data3'
    ];

    const promises = urls.map(url => fetchData(url));
    const results = [];
    //const results = await Promise.all(promises); // can replace for (const promise of promises){

    for (const promise of promises) {
      const data = await promise;
      results.push(data);
    }

    console.log('Data fetched:', results);
  } catch (error) {
    console.error('Error:', error);
  }
}
~~~
