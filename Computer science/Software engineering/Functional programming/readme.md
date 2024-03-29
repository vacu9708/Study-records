![image](https://user-images.githubusercontent.com/67142421/178240477-49b802bc-deb5-427b-a414-712d4b49349a.png)

# Imperative programming
**How to do it?**
Imperative programming focuses on specifying explicit steps or instructions that the computer must follow to solve a problem.<br>
### Example
This example uses a for loop to iterate over each element of the array, multiply it by 2, and store the results in a new array.<br>
~~~python
def doubleAllElements(arr):
    for i in range(len(arr)):
        arr[i] = arr[i] * 2
    return arr
    
print(doubleAllElements([1, 2, 3, 4])) # Output: [2, 4, 6, 8]
~~~

# Declarative programming
**What to do?**
Declarative programming focuses on describing what the computer should do rather than how to do it. Instead of specifying explicit steps, the desired outcome should be declared. (e.g. HTML, SQL)<br>
Imperative instructions are abstracted well in advance so that declarative programming works well.<br>
### Example
This example uses a higher level of abstraction to create a new array by applying the doubling operation to each element of the input array so that the desired outcome is expressed without explicitly defining how to achieve it.<br>
~~~python
def doubleAllElements(arr):
    return [num * 2 for num in arr]

print(doubleAllElements([1, 2, 3, 4])) # Output: [2, 4, 6, 8]
~~~

# Functional programming
Functional programming solves problems by defining functions that establish relationships between input and output, without mutable state.<br>
Mutable state refers to variables that can be modified after their initial assignment, which can make programs harder to reason about. In functional programming, instead of modifying variables, new variables with updated values are created.<br>
Functional programming allows developers to focus on the problem domain and express the logic without getting bogged down in implementation details.<br>
### Example
This functional approach uses the map function along with a lambda function to double each element of the array.<br>
~~~python
def doubleAllElements(arr):
    return list(map(lambda x: x * 2, arr))

print(doubleAllElements([1, 2, 3, 4])) # Output: [2, 4, 6, 8]
~~~
