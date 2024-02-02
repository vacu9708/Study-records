# Solution of hash collision
## Chaining
>The idea is to make each cell of hash table have a linked list to solve the hash collision.
![image](https://user-images.githubusercontent.com/67142421/150531067-fe59c4e7-2f4c-4d55-9705-1fb2d1c509ce.png)

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

