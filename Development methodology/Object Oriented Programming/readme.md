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
- **Polymorphism** : allowing a single interface (such as a name and an operator) to be used for multiple purposes that have the same meaning.<br>
Ex) **Method overriding**: overriding the method of the parent class that has the same name as the child's method.<br>
Ex) **operater overloading**: allows the same operator symbol to be used for multiple operations<br>

- **Inheritance** : the procedure in which one class inherits the properties of another class.
To put it simply, inheritance is done for the use of code that is pre-written (for reuse of code).

- **Abstraction** : wrapping something up as a simple name to hide unnecessary details
For example, when there are fish, lions, rabbits, they can be wrapped up as "life", as a class is given a name.

- **Encalsulation** : the wrapping up of data and methods under a single unit. (Information hiding)

# SOLID design principles in OOP
### Coupling
Coupling measures how closely connected two components are to each other.<br>
Loose coupling means that changes in one(child) component do not necessitate changes in another(parent) component, leading to improved maintainability.<br>

### Cohesion
Cohesion refers to the degree to which the functionality is related and focused within a single component.<br>
High cohesion indicates that the component is well-defined and performs a specific task effectively.

## 1. Single Responsibility Principle
Every component of code (in general a class, but also a function) should have only one responsibility.<br>
For example, a single function, generically named(like "main"), doing all the work is bad.<br>
If a component of code has more than one responsibility, code maintenace becomes hard.<br>
#### Primary advantage:
High cohesion

## 2. Open, Closed Principle
Open extensibility, closed modification<br>
The OCP helps to achieve loose coupling by promoting extensibility without modifying existing code.<br>
The OCP often go hand in hand with the Dependency Inversion Principle.<br>
#### Primary advantage:
Loose coupling

## 3. Liskov Substitution Principle
Child classes must be substitutable for their parent classes.<br>
LSP enables the use of subtype polymorphism, which allows objects of a subclass to be treated as objects of their superclass This enables modularity and extensibility by allowing new subclasses to be added without affecting the existing code that relies on the superclass.<br>
LSP facilitates Dependency inversion by allowing high-level modules to depend on the abstractions provided by the superclass.<br>
#### Primary advantage:
Loose coupling(abstract common interface)
### Example
~~~java
public class Computer{
}
public class Laptop extends Computer{
	public void get_CPU(){
		System.out.println("A laptop has CPU");
	}
}
public class Desktop extends Computer{
	public void get_CPU(){
		System.out.println("A desktop has CPU");
	}
}
public class Keyboard extends Computer{
	public void get_CPU(){
		System.out.println("ERROR");
	}
}
public static void main(String[] args) {
	Computer computer = new Laptop(); // obeys LSP
	Computer desptop = new Desptop(); // obeys LSP
	Computer keyboard = new Keyboard(); // violates LSP because this child cannot be substituted with its parent
}
~~~

## 4. Interface Segregation Principle
The ISP states that no code should depend on interfaces it does not use.
#### Primary advantage:
Loose coupling(only necessary dependencies), High cohesion(one interface only has one functionality)
### Example of not obeying ISP
~~~java
public interface Printer {
    void print();
    void scan();
}

public class Scanner implements Printer {
    public void print() {
        // Implementation for printing
    }
    
    public void scan() {
        // Implementation for scanning
    }
}
~~~
The above example violates ISP because the child component Scanner depends on the unnecessary component Printer.<br>

### Example of obeying ISP
~~~java
public interface Printer {
    void print();
}

public interface Scanner {
    void scan();
}

public class BasicScanner implements Scanner {
    public void scan() {
        // Implementation for scanning
    }
}

public class AdvancedPrinter implements Printer, Scanner {
    public void print() {
        // Implementation for printing
    }
    
    public void scan() {
        // Implementation for scanning
    }
}
~~~
By following the Interface Segregation Principle, the code is more modular.<br>

## 5. Dependency Inversion Principle
The name refers to the inversion of the traditional dependency direction, where high-level modules depend on low-level modules.<br>
DIP states that high-level modules should not directly depend on low-level modules, but their abstraction, so that high level modules can work regardless of changes to their low level modules.<br>
#### Primary advantage:
Loose coupling(abstract common interface)
### Example of not obeying DIP
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/498b3955-7209-4879-90fa-cd860c5f5152)

~~~java
class Samsung_pay {
    String payment() {
        return "samsung";
    }
}

class Pay_service {
    Samsung_pay pay_type = new Samsung_pay();
    String payment() {
        return this.pay_type.payment();
    }
}
~~~
The above example does not obey DIP because Pay_service depends on its low level module Samsung_pay.<br>
If the low level module Samsung_pay changes, the high level module Pay_service has to be changed too, which is inefficient.(tight coupling)

### Example of obeying DIP
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/6f7ab505-d273-48a3-a8a2-c6469661c375)

Dependency injection and an interface(abstraction) enable dependency inversion.<br>
***Dependency injection*** means providing the dependencies of a class from outside of the class, rather than creating them within the class itself.
~~~java
interface Pay_type{
	String payment();
}

class Samsung_pay implements Pay_type {
    	String payment() {
		return "samsung";
    }
}
class Apple_pay implements Pay_type {
 	String payment() {
        	return "apple";
    }
}

class Pay_service {
	Pay_type pay_type;
	Pay_service(Pay_type pay_type) {
		this.pay_type = pay_type;
		this.pay_type.payment();
 	}	
}
~~~
Whether pay_type is samsung or apple, Pay_service does not need to be changed thanks to the **polymorphism** of Pay_type.(loose coupling)
