Methods to prevent accessing shared memory at the same time are needed.<br>
**Busy waiting** method can be used (repeatedly checking to see if a condition is true) But it is ineffective since it takes computing resource constantly.<br>


**semaphore** : a method to solve the busy waiting problem where whether shared resource is in use is checked before a process gets into the critical section.<br>
**mutex(mutual exclusion)** : it is a kind of semaphore. Unlike the normal semaphore where multiple processes can share resource, mutex is binary semaphore.
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
