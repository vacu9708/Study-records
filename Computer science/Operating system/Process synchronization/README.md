[Explanation of Lock](https://github.com/vacu9708/Study-records/blob/main/Embedded_system/Linux%20kernel/5.%20Lock.pdf)

~~~c++
class Semaphore{
	int shared_resource; // 1 or more (If this is initialized with the value 1, it can function similarly to a mutex.)
	Queue process_queue;
}

void acquire(Semaphore* S, Process* process){ // When a process wants to take a shared resource
    S->shared_resource--;
    if ( S->shared_resource < 0 ) { // Put the process to sleep if other processes are using the shared resource
        S->process_queue.enqueue(process);
        sleep(process);
    }
}

void release(Semaphore* S) { // Wakes up a process that wanted to take a shared resource
    S->shared_resource++;
    if ( S->shared_resource <= 0 ) { 
        process=S->process_queue.dequeue();
        wakeup(process);
    }
}
~~~

## Example of using a lock for synchronization in multi-processing
### Without a mutex
There is no semaphore that protects the critical section, so the output is unstable.
~~~python
from multiprocessing import Process, Value, Lock

def add_100(number):
    for i in range(100):
        number.value += 1 # Critical section

if __name__ == "__main__":
    shared_number = Value('i', 0) # i = integer
    print("Start from", shared_number.value)
    p1 = Process(target=add_100, args=(shared_number,))
    p2 = Process(target=add_100, args=(shared_number,))
    p1.start()
    p2.start()
    p1.join()
    p2.join()
    print("End with ", shared_number.value)
~~~
#### Output
![image](https://user-images.githubusercontent.com/67142421/177394795-d4fc8ac8-d465-4f08-b00b-40202a48e261.png)

### With a mutex
There is a semaphore(mutex) that protects the critical section, so the output is guaranteed.
~~~python
from multiprocessing import Process, Value, Lock

def add_100(number, lock):
    for i in range(100):
        lock.acquire()
        number.value += 1 # Critical section
        lock.release()
```
# with lock: <- This "monitor" can be used instead of specifying lock.acquire() and release() manually.
def add_100_monitor(number, lock):
    for _ in range(100):
        with lock:  # Monitor used. This will acquire the lock and automatically release it after the block
            number.value += 1  # Critical section
```
if __name__ == "__main__":
    lock = Lock() # Lock
    shared_number = Value('i', 0) # i = integer
    print("Start from", shared_number.value)
    p1 = Process(target=add_100, args=(shared_number, lock))
    p2 = Process(target=add_100, args=(shared_number, lock))
    p1.start()
    p2.start()
    p1.join()
    p2.join()
    print("End with ", shared_number.value)
~~~
#### Output
![image](https://user-images.githubusercontent.com/67142421/177388487-051bd0f0-e5ea-4242-9278-a97af7899ca5.png)

## Bounded buffer problem(also called producer-consumer problem)
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/96cf93d8-74ea-4347-abf5-6fef6e22ab79)

producer : data putter / consumer : data taker<br>
The semaphores which will be used here are:
- mutex, a binary semaphore which is used to acquire and release the lock.
- empty, a counting semaphore whose initial value is the number of slots in the buffer, since initially all slots are empty.
- full, a counting semaphore whose initial value is 0, since initially no slots are full.

~~~c++
total = [0]
while:
	// Producer
	acquire(empty) // A slot is taken
	acquire(mutex) // Consumer has to wait for producer
	put_item(total)
	release(mutex)
	release(full)

	// Consumer
	acquire(full) // A slot gets available
	acquire(mutex) // Producer has to wait for consumer
	take_item(total)
	release(mutex)
	release(empty)
~~~

## Readers, writer problem
Readers do not change data and maintains data consistency. Therefore readers can access shared data at the same time.<nt>
However, in the middle of writing, neither readers nor writers can access it. So it is simple because only mutex is needed.<br>

~~~c++
void Read(){
	acquire(reader_count_mutex) // Try acquiring reader count
	reader_count++;
	if(reader_count==1) // If it's the 1st reader, which means writer is off
		acquire(writer_mutex) // Disable writing
	release(reader_count_mutex);
	read();
	acquire(reader_count_mutex);
	reader_count--;
	if(reader_count==0) // If this is the last reader
		release(writer_mutex); // Enable writing
	release(reader_count_mutex);
}

void Write(){
	acquire(writer_mutex);
	write();
	release(writer_mutex);
}
~~~
