* **Shallow copy** : copying just the reference address.
* **Deep copy** : copying the whole object.

~~~javascript
a = { } // Object
a = [ ] // Array

b = a // **Complete shallow copy**
b = Object.assign({}, a) // **Partial deep copy** that only works for one dimensional objects, that is, it doesn't work for nested objects.
b. = [...a] // **Partial deep copy** that only works for one dimensional arrays
~~~

### JSON can be used to do a complete deepcopy.
JSON.stringify() for changing an object to JSON.<br>
JSON.parse() for changing JSON to an object.<br>
~~~javascript
b = JSON.parse(JSON.stringify(a))
~~~

In python, import copy and then use copy() and deepcopy()
