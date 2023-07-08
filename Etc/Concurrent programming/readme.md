# Concurrent programming
Concurrenct programming refers to executing multiple tasks simultaneously, which involves both actual and apparent simultaneous execution of multiple tasks.<br>
The example below divides a task into smaller subtasks and processes them simultaneously but does not improve the speed because the threads only appear to be executed simultaneously.
Concurrent programming requires synchronization mechanisms to prevent race conditions.
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
Parallel programming refers to executing multiple tasks **actually** at the same time on separate CPU processors.<br>
The example below breaks a task into subtasks and processes them simultaneously on separate CPU processors.<br>
Parallel programming requires inter-process communication because processes are designed to not commumicate with each other by default.

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
const axios = require('axios');

async function asyncIO() {
  const promises = [
    axios.get('http://localhost:8081/test/hi'),
    axios.get('http://localhost:8081/test/hello')
  ];

  // Do other jobs
  console.log("Doing other jobs...")

  const responses = [];
  // Await responses
  for (const promise of promises) {
    const response = await promise;
    responses.push(response);
  }

  for (const response of responses) {
    console.log(response.data);
  }
}

async function asyncIO2() {
  const promises = Promise.all([
    axios.get('http://localhost:8081/test/hi'),
    axios.get('http://localhost:8081/test/hello')
  ]);

  // Do other jobs
  console.log("Doing other jobs...")

  // Await responses
  const responses = await promises;

  for (const response of responses) {
    console.log(response.data);
  }
}

asyncIO();
~~~
