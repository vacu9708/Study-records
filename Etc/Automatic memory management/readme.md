# Automatic memory management
Manually managing memory turned out to be too difficult. That is why the automatic memory management appeared.<br>
### How it works?
Automatic memory management is performed through the concept **"reachability"**. The reachability means that a piece of allocated memory can be reached and used.<br>
If an object no longer has any reference to it, it means the object is a waste of memory and should be deleted.<br>

# C++ smart pointers
### std::unique_ptr
**std::unique_ptr** enforces exclusive ownership, meaning there is only one owner for the managed object.<br>
#### A std::unique_ptr automatically deallocates its object when:<br>
- The std::unique_ptr is detroyed
- The std::unique_ptr is assigned a new memory address

The exclusive ownership has a limit that circular references(e.g. linked list) are impossible
~~~c++
#include <iostream>
#include <memory>

class Node {
public:
    std::unique_ptr<Node> next;
    int data;
    Node(int data): data(data) {}
};

int main() {
    std::unique_ptr<Node> node1 = std::make_unique<Node>(1);
    std::unique_ptr<Node> node2 = std::make_unique<Node>(2);

    node1->next = std::move(node2);  // Connect node1 to node2 (move ownership)
    node2->next = std::move(node1);  // Error! Circular reference is not allowed

    printf("%d", node1->data);
    return 0;
}

~~~

### std::shared_ptr
**std::shared_ptr** can manage ownership of multiple objects, enabling the handling of circular references.<br>
However, **std::shared_ptr** has the overhead of maintaining the reference count.<br>
#### How std::shared_ptr dellocates its object:
When **shared_ptr1** assigns **shared_ptr2**, the reference count of shared_ptr2 is incremented by one<br>
A **std::shared_ptr** automatically deallocates its object when: the reference count reaches zero.(i.e. when std::shared_ptr whose reference count is 1 is destroyed)<br>
~~~c++
#include <memory>

struct Node {
    int data;
    std::shared_ptr<Node> next;
    Node(int val) : data(val) {}
};

int main() {
    // Create two nodes
    std::shared_ptr<Node> node1 = std::make_shared<Node>(1); // reference count of node1: 1
    std::shared_ptr<Node> node2 = std::make_shared<Node>(2); // reference count of node2: 1

    // Establish the circular reference
    node1->next = node2; // reference count: node1=1, node2=2
    node2->next = node1;  // reference count: node1=2, node2=2

    printf("%d\n", node1->data);
    printf("%d\n", node1->next->data);
    // Both nodes will be deallocated when all shared_ptrs are released
    return 0;
}

~~~

# Java Garbage Collector
A **Java GC** constantly monitors all allocated memory and reclaims memory which was allocated, but is no longer referenced.<br>
GCs incur overhead during garbage collection cycles.<br>

## Reachable object
![image](https://user-images.githubusercontent.com/67142421/177013694-8add3600-ae4d-47ad-899f-2611edaf7317.png)

## Unreachable object
![image](https://user-images.githubusercontent.com/67142421/178157740-cd8b3828-ca89-4a37-a89c-20a26c80d12b.png)

## Optimization of garbage collection
A garbage collection operation is a CPU-demanding task, so it needs optimization.
### Generational collection
Objects are divided into "young objects" and "old objects(or permanent objects)".<br>
Garbage collection can be optimized based on the fact that the majority of objects created newly become unreachable.<br>
- The garbage collection monitors and deletes young objects actively. This is called **Minor Gabarge Collection**.
- Objects created early that survive minor collection are moved to "old objects", Old objects are monitored less frequently than young objects, which is called

### Major Garbage Collection

### Idle-time collection
Garbage collection is performed only when the CPU is idle to minimize the latency and exploit CPU idle times.

## Garbage collection cycle
**Object metadata**: When an object is created in the heap, it includes metadata that the garbage collector (GC) uses to manage memory. This metadata is used by the GC to track various information about the object.<br>
### STW(Stop The World)
The garbage collector pauses the execution of the application threads

### Mark Phase:
#### `(1)`
Initial object graph<br>
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/d8fe0bcb-e369-4f9a-8d4e-0f9caee67bf4)<br>
>(The actual object graph does not include the "marked" flag(reachability) but include the object's address to access the "marked" flag)<br>

#### `(2)`
The GC traverses the object graph which includes object addresses to reference to. While traversing, the GC references to the object address of each node that is encountered to mark the object as reachable. This process implicitly identifies objects that are unreachable.<br>
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/2b1a2f6b-7c45-4674-9aa5-f2976bf66521)<br>

### Sweep Phase:
#### `(3)`
The GC scans the entire heap of the process, checking the reachability state of each object.<br>
Reachable objects are kept, while unreachable objects are deleted. During this phase, the remaining objects' reachability bits are reset to the default which is usually false.<br>
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/593b7956-4636-410a-9c28-5c1c0140a934)<br>

# Which is better between C++ smart pointers and Java GC?
It is possible for std::shared_ptr in C++ to be faster than the garbage collector (GC) in Java in certain scenarios, and the opposite situation is also possible.
- std::shared_ptr is better when the overhead of reference counting is low compared to the periodic pauses of the GC.
- Garbage collection is better in scenarios with frequent object creation and destruction, where the GC's optimized memory management techniques, like generational GC, can provide better performance by efficiently reclaiming short-lived objects.
