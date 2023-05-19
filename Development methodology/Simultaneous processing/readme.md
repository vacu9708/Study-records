# Concurrent programming
Concurrenct programming refers to dividing a task into smaller subtasks and processing them at the same time. Concurrency involves both actual and apparent simultaneous execution of multiple tasks.<br>

~~~python
import time

def heavy_work_thread(sums):
    sum = 0
    for i in range(5000000):
        sum += 0.1
    sums.append(round(sum)) # 500000

if __name__ == '__main__':
    import threading
    start = time.time()
    sums=[]
    # Divide a task for making 2000000 into 4 subtasks
    threads = []
    for i in range(4):
        t = threading.Thread(target=heavy_work_thread, args=(sums,))
        t.start()
        threads.append(t)

    # Wait for all the threads to complete
    for t in threads:
        t.join()
    # Merge partial sums to calculate the final sum
    final_sum=0
    for sum in sums:
        final_sum+=sum

    print("Multi-threading-> Final sum: %d, Elapsed time: %f" % (final_sum, time.time() - start))
~~~

# Parallel programming
Parallel programming refers to breaking a task into subtasks and processing them **actually** at the same time on separate CPU processors.<br>
### Multi-processing requires:
- Synchronization mechanisms to prevent race conditions.
- Inter-process communication because processes are designed not to commumicate by default.

In python, **if __name__ == '__main__'** allows the code inside it to be executed only in the top module, which prevents unintended execution of code when a python file is imported as a module.
~~~python
def heavy_work_process(sums):
    sum = 0
    for i in range(5000000):
        sum += 0.1
    sums.put(round(sum)) # 500000

if __name__ == '__main__':
    import multiprocessing
    start = time.time()
    # Reasons for using multiprocessing.Queue():
    # 1. multiprocessing.Queue() provides built-in synchronization mechanisms
    # 2. For inter-process communication
    sums=multiprocessing.Queue()
    # Divide a task for making 2000000 into 4 subtasks
    processes = []
    for i in range(4):
        p = multiprocessing.Process(target=heavy_work_process, args=(sums, ))
        p.start()
        processes.append(p)
    # Wait for all the processes to complete
    for p in processes:
        p.join()
    # Merge partial sums to calculate the final sum
    final_sum=0
    while not sums.empty():
        final_sum+=sums.get()

    print("Multi-processing-> Final sum: %d, Elapsed time: %f" % (final_sum, time.time() - start))
~~~
---

# Synchronous programming
Each task is executed one after the other.(blocking)

# Asynchronous programming
Asynchronous programming allows a single thread to manage multiple tasks in a non-blocking manner. It can be implemented with either concurrency and parallelism.

## Non-blocking I/O
When a thread performs an I/O operation, all the thread can do is wait, which leads to a waste of CPU because I/O operation hardly uses CPU.<br>
In non-blocking I/O, a thread has I/O operations performed on separate threads without blocking the execution.<br>

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
