# Procedural programming
Procedural programming is a programming paradigm where code is processed sequentially from the top to the bottom like water flows.

# Object Oriented Programming
A programming paradigm in which a program is described as interactions between objects.

* What is an object? : An object is an abstract data type that has data and code.
* What is a class? : a class is a blueprint for creating objects.

# Advantages of OOP
1. Modularity for easier troubleshooting
2. Reuse of code through inheritance
3. Flexibility through polymorphism
4. Easier code maintenance

# 4 characteristics of OOP
### Polymorphism
Allowing a single interface (such as a name and an operator) to be used for multiple purposes that have the same meaning.<br>
Ex) **Method overriding**: overriding the method of the parent class that has the same name as the child's method.<br>
Ex) **operater overloading**: allows the same operator symbol to be used for multiple operations<br>
### Inheritance
The procedure in which one class inherits the properties of a parent class.
To put it simply, inheritance is done for the use of code that is pre-written (for reuse of code).
### Abstraction
Abstraction refers to simplifying the detailed workings by presenting only the essential features(interfaces) to the user so that they can be utilized without needing to know how they work underneath.<br>
An example of abstraction is APIs. An API is a bridge between two applications that allows them to communicate.
In summary, abstraction serves as a bridge by defining an interface that enables interaction with the abstracted component while hiding its implementation details. 
### Encalsulation
Bundling data and methods into a class, hiding the internal workings, which is a means to achieve abstraction.

# Interface and abstract class
In Java, an interface and an abstract class define a set of requirements that a class implementing that must provide. In other words, They are a "blueprint"<br>

||Abstract class|Interface|
|---|---|---|
|Purpose|Both serve as blueprints for classes||
|Instantiation|Both cannot be directly instantiated||
|Implementation|Can have both implemented methods and non-implemented methods|No implementations|
|Inheritance|Supports single inheritance|A class can implement multiple interfaces|

In summary, abstract classes are blueprints that can have implemented methods while interfaces are pure blueprints.
