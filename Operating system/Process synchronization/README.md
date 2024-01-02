- A **race condition** is a situation where multiple processes are accessing shared data simultaneously and it affects ***data consistency***.<br>
- **Process Synchronization** refers to aligning the execution timing of processes to ensure that shared resources are accessed by only one process at a time to maintain data consistency.<br>
- The **critical section** is a code segment that can be accessed by only one process at a time. Process Synchronization is to manage the critical section.<br>

### Lock mechanisms used to protect shared resources from concurrent access
- **Spinlock(busy waiting)** : When a thread attempts to acquire a spinlock that is already held by another thread, it will continuously check (or "spin") until the lock becomes available. This approach can be efficient if the expected wait time is short since the thread remains active and does not enter a sleep state. However, it can also waste CPU cycles if the lock is held for a long time.
- **Semaphore** : used to solve the busy waiting problem by checking whether a shared resource is in use before a process enters the critical section.
- **Mutex(mutual exclusion)** : a type of semaphore. While a normal semaphore allows multiple processes to share a resource, a mutex is a binary semaphore. In other words, it has only two states: locked and unlocked.

~~~c++
class Semaphore{
	int waiting_processes; // means the number of waiting processes.
	list process_queue;
}

void acquire(Semaphore *S, Process process){ // When a process wants to take shared resource 
    if ( S->waiting_processes > 0 ) { // If another process is using the shared resource.
        S->process_queue.enqueue(process); // Put the process in queue
        block(process);
    }
    S->waiting_processes++; // Try taking shared resource
}

void release(Semaphore *S) { // When stopping the process that has taken the resource
    if ( S->waiting_processes > 0 ) { // If another process is using the shared resource.
        process=S->process_queue.dequeue(); // Execute a process in queue
        wakeup(process);
    }
    S->waiting_processes--; // Release shared resource
}
~~~

## Example with multi-processing
There is no semaphore that protects the critical section, so the output is unstable.
~~~python
from multiprocessing import Process, Value, Lock

def add_100(number):
    for i in range(100):
        number.value += 1

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

There is a semaphore(mutex) that protects the critical section, so the output is guaranteed.
~~~python
from multiprocessing import Process, Value, Lock

def add_100(number, lock):
    for i in range(100):
        lock.acquire() # Acquire semaphore
        number.value += 1
        lock.release() # Release semaphore


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
- full, a counting semaphore whose initial value is 0.

~~~c++
while:
	// Producer
	acquire(empty) //
	acquire(mutex) // Consumer has to wait for producer
	put_item()
	release(mutex)
	release(full)

	// Consumer
	acquire(full); //
	acquire(mutex); // Producer has to wait for consumer
	take_item()
	release(mutex);
	release(empty);
~~~

## Readers, writer problem
Readers do not change data, so data consistency is maintained. Therefore readers can access shared data at the same time.<nt>
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
