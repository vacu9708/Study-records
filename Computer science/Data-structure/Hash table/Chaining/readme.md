# Solution of hash collision
# Chaining
![image](https://user-images.githubusercontent.com/67142421/150531067-fe59c4e7-2f4c-4d55-9705-1fb2d1c509ce.png)<br>
Chaining is a technique used to resolve hash collisions in a hash table. When two keys hash to the same index in the table and a collision occurs, chaining allows both key-value pairs to be stored at that index by linking them together in a list.

## Implementation
- **Bucket with a linked list**: Each slot (or bucket) in the hash table array points to a linked list (or chain) of entries that have been hashed to the same index.
- **Insertion**: When inserting a new key-value pair, the hash function calculates the index for the key.
  - If the bucket at that index is empty, the key-value pair is added and becomes the first element of the list.
  - If the bucket is not empty (indicating a collision), the new key-value pair is added to the head or tail of the linked list at that index, depending on the implementation.
- **Lookup (Retrieval)**: To retrieve the value associated with a specific key, the hash function is used to find the appropriate bucket. Then, a search is performed through the linked list at that index to find the key. If the key is found, the corresponding value is returned. Otherwise, a signal that the key does not exist in the table is returned.
- **Deletion**: To remove a key-value pair, the process is similar to lookup. The list is searched for the key. If found, the key-value pair is removed from the list.

## Advantages
- **Simplicity**: Chaining is straightforward to implement and understand.
- **Flexibility**: It can handle an arbitrary number of collisions gracefully, as the linked list can grow as needed.
## Disadvantages
- **Memory Overhead**: Each entry in the list requires additional memory for the pointer to the next element, which can be significant, especially if the keys and values are small.
- **Variable Performance: The worst-case time complexity can degrade to O(n) (where n is the number of elements) if too many keys hash to the same index, making all operations slower as they require linear search through the list.

## Optimizing Chaining
To optimize the performance of a hash table using chaining:
- A **low load factor** (the ratio of the number of stored entries to the number of buckets) can be maintained by increasing the size of the hash table as it fills up, thus spreading out the entries more evenly.
- A **good hash function** that minimizes collisions and distributes keys uniformly across the buckets is crucial.

## Example C++ code
~~~C++
#include <iostream>
#include <list>
using namespace std;

class HashTable {
	int table_length;
public:
	class Node {
	public:
		string key;
		string data;
		Node(string key, string value) {
			this->key = key;
			this->data = value;
		}
	};

	list<Node>* buckets;
	HashTable(int table_length) {
		this->table_length = table_length;
		this->buckets = new list<Node>[table_length];
	}

	int make_index(string key) {
		// Make a hash code with key
		int hashcode = 0;
		int weight = 1;
		for (char c : key) {
			hashcode += c * weight; // To distinguish anagrams such as "abc" and "cba"
			weight *= 10;
		}
		return hashcode % table_length; // Hash function : convert hash code to index.
	}

	void insert(string key, string data) { // Insert data into hash table
		int index = make_index(key);
		buckets[index].push_back(Node(key, data));
	}

	void deleteData(string key) { // Delete the last data
		int index = make_index(key);

		// Find the node that has the key
		list<Node>::iterator iterator;
		for (iterator = buckets[index].begin(); iterator != buckets[index].end(); iterator++)
			if (iterator->key == key)
				break;
		//-----
		if (iterator == buckets[index].end()) {
			cout << "(" << key << ") not found\n";
			return;
		}

		cout << "Delete (" << key << ")\n";
		buckets[index].erase(iterator);
	}

	void search(string key) {
		int index = make_index(key);

		// Find the node that has the key
		list<Node>::iterator iterator;
		for (iterator = buckets[index].begin(); iterator != buckets[index].end(); iterator++)
			if (iterator->key == key)
				break;
		//-----
		if (iterator == buckets[index].end()) {
			cout << "Search : (" << key << ") -> (not found)\n";
			return;
		}

		cout << "Search : (" << key << ") -> (" << iterator->data << ") found\n";
	}
};

int main() {
	HashTable* h = new HashTable(1);
	list<string> container;
	h->insert("John", "He is cute");
	h->insert("Paul", "He is a cutie");
	h->search("John");
	h->search("Paul");
	h->deleteData("John");
	h->search("John");
}
~~~
## Output
![Untitled](https://user-images.githubusercontent.com/67142421/149351330-0c070a9a-0547-44f4-abdf-68530d6f9aee.png)

