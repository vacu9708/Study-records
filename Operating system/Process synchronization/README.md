A **race condition** occurs when two processes or threads access shared memory at the same time and it affects *data consistency*.<br>

**Process Synchronization** is the task of coordinating processes so that shared resources can be accessed by only one process to maintain *data consistency*.<br>

The **critical section** is a code segment that can be accessed by only one process at a time. Process Synchronization is to manage the critical section.<br>

## Methods to prevent accessing shared memory at the same time
* **Busy waiting** method can be used (repeatedly checking to see if a condition is true) But it is ineffective since it takes computing resource constantly.<br>
* **semaphore** : a method to solve the busy waiting problem where whether shared resource is in use is checked before a process gets into the critical section.<br>
* **mutex(mutual exclusion)** : it is a kind of semaphore. Unlike the normal semaphore where multiple processes can share resource, mutex is binary semaphore.
In other words, only lock and unlock exist.<br>

~~~c++
class semaphore{
	int shared_resource; // starts with 1. (-) shared_resource means the number of waiting processes.
	list process_queue;
	semaphore(n){
		this->left_resource=n;
}

void acquire(semaphore *S){ // When a process wants to take shared resource
    S->shared_resource--; // Try taking shared resource
    if ( S->shared_resource < 0 ) { // If another process is using the shared resource.
        S->process_queue.enqueue(current_process); // Put the process in queue
        block(process);
    }
}

void release(semaphore *S) { // When stopping the process that has taken the resource
    S->shared_resource++; // Release shared resource
    if ( S->shared_resource <= 0 ) { // If there's a waiting process
        process=S->process_queue.dequeue(); // Execute a process in queue
        wakeup(process);
    }
}
~~~

# Example with multi processing
## Without a semaphore where the critical section is not protected, so the output is unstable.
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

## With a semaphore where the critical section is protected, so the output is always the same.
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

## Bounded buffer problem
producer : data putter / consumer : data taker<br>
* Producer determines empty elements using semaphore called empty.
* Consumer determines full elements using semaphore called full.
producer and consumer are controleld by mutex.

~~~c++
// Producer
acquire(empty) // Try putting sth in the current empty element, so producer cannot access to the current element
acquire(mutex) // Consumer cannot access to the buffer
put_item();
release(mutex)
release(full) // Consumer can access to the current element

// Consumer (Just opposite of producer)
acquire(full); // Try taking the current full element ,so consumer cannot access to the current element
acquire(mutex); // Producer cannot access to the buffer
take_Item();
release(mutex);
release(empty); // Producer can access to the current element
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
