## Procedural programming
Procedural programming is a programming paradigm where tbe code is processed sequentially from the top to the bottom like water flows.

# Object Oriented Programming
A programming paradigm in which describing a program as interactions between objects, which facilitates collaboration.

* What is an object? : An object is an abstract data type that has data and code.
* What is a class? : a class is a blueprint for creating objects.

# Advantages of OOP
1. Modularity for easier troubleshooting
2. Reuse of code through inheritance
3. Flexibility through polymorphism
4. Easier code maintenance

# 4 characteristics of OOP
* **Polymorphism** : allowing a single interface (such as a name and an operator) to be used for multiple purposes that have the same meaning.
Ex) **Method overriding** : overriding the method of the parent class that has the same name as the child's method.
Ex) **operater overloading

* **Inheritance** : the procedure in which one class inherits the properties of another class.
To put it simply, inheritance is done for the use of code that is pre-written (for reuse of code).

* **Abstraction** : wrapping something up as a simple name to hide unnecessary details
For example, when there are fish, lions, rabbits, they can be wrapped up as "life", as a class is given a name.

* **Encalsulation** : the wrapping up of data and methods under a single unit. / The bundling of data and methods into one unit.
Another way to think about encapsulation is, it is a protective shield that prevents the data from being accessed by the code outside this shield. (Information hiding)
-----

# Design principles in OOP
### 1. Single Responsibility Principle
Every component of code (in general a class, but also a function) should have only one responsibility.<br>
For example, a single function, generically named(like "main"), doing all the work is bad.<br>
If a component of code has more than one responsibility, code maintenace becomes hard.<br>

### 2. Open, Closed Principle
Software components should be open for extension but closed for modification.<br>
Code should be written so that new functionality can be added without changing the existing code.<br>
That prevents situations in which a change to one of the classes also requires adapting all depending classes.<br>
