- **Data consistency** refers to whether the same data kept at different places do or do not match. 
- **Critical section** is a code segment where shared resources are accessed.
- **Race condition** is a situation where multiple processes are accessing a shared resource(**critical section**) simultaneously, which might affect **data consistency**.
- **Process Synchronization** refers to aligning the execution timing of processes to ensure that shared resources are accessed by only one process at a time to maintain **data consistency**.

## Lock mechanisms
Lock mechanisms are used to protect shared resources from concurrent access.
- **Mutex(mutual exclusion)** : Used to ensure that a shared resource is accessed only by one thread at a time. It has two states: locked and unlocked.
- **Semaphore** : A mutex is a binary semaphore. A semaphore can allow more than one thread to access a shared resource but limits the number.
- **Monitor**: Unlike mutexes, where a thread must explicitly lock and unlock, monitors manage locks implicitly. When a thread enters a monitor's method, it automatically acquires the lock, and when it exits the method (either normally or by waiting on a condition variable), it automatically releases the lock. Monitors can use a condition variables, which are used to block a thread until a particular condition is met.

### How to implement the lock
- **Spinlock(busy waiting)**: When a thread attempts to acquire a spinlock that is already held by another thread, it will continuously check (or "spin") until the lock becomes available. This approach can be efficient if the expected wait time is short since the thread remains active and does not enter a sleep state. However, it can also waste CPU cycles if the lock is held for a long time.
- **Process queue**: The PCB of a process is put in a queue and popped when the shared resource has become available.

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

## Example using a lock for multi-processing
**Without a mutex**: There is no semaphore that protects the critical section, so the output is unstable.
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
### Output
![image](https://user-images.githubusercontent.com/67142421/177394795-d4fc8ac8-d465-4f08-b00b-40202a48e261.png)

**With a mutex**: There is a semaphore(mutex) that protects the critical section, so the output is guaranteed.
~~~python
from multiprocessing import Process, Value, Lock

def add_100(number, lock):
    for i in range(100): # with lock: <- This "monitor" can be used instead of specifying lock.acquire() and release() manually.
        lock.acquire()
        number.value += 1 # Critical section
        lock.release()

def add_100_monitor(number, lock):
    for _ in range(100):
        with lock:  # Monitor used. This will acquire the lock and automatically release it after the block
            number.value += 1  # Critical section

if __name__ == "__main__":

    semaphore = Lock() # Semaphore
    shared_number = Value('i', 0) # i = integer
    print("Start from", shared_number.value)
    p1 = Process(target=add_100, args=(shared_number, semaphore))
    p2 = Process(target=add_100, args=(shared_number, semaphore))
    p1.start()
    p2.start()
    p1.join()
    p2.join()
    print("End with ", shared_number.value)
~~~
### Output
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
