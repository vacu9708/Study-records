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

- **Encalsulation** : the wrapping up of data and methods under a single unit. / The bundling of data and methods into one unit.
Another way to think about encapsulation is, it is a protective shield that prevents the data from being accessed by the code outside this shield. (Information hiding)

# SOLID design principles in OOP
## coupling
**coupling**: How much work is involved to changing something?<br>
It is important to keep software in loose coupling in order to make changes with as less code as possible<br>
Everything in business always changes!<br>
That's what SOLID principles are for.

## 1. Single Responsibility Principle
Every component of code (in general a class, but also a function) should have only one responsibility.<br>
For example, a single function, generically named(like "main"), doing all the work is bad.<br>
If a component of code has more than one responsibility, code maintenace becomes hard.<br>

## 2. Open, Closed Principle
Software components should be open for extension but closed for modification.<br>
Code should be written so that new functionality can be added without changing the existing code.<br>
That prevents situations in which a change to one of the classes also requires adapting all depending classes.<br>

## 3. Liskov Substitution Principle
Child classes must be substitutable for their parent classes.<br>
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

### Another example
~~~java
public class Rectangle{
	int width;
	int height;
	public Rectangle(int width, int height) {
		this.width = width;
		this.height = height;
	}
	
	public void set_width(int width) {
		this.width = width;
	}
}

public class Square extends Rectangle {
	public Square(int width) {
		super(width, width);
	}
	
	public void set_width(int width) {
		this.width = width;
    		this.height = width;
	}
}

public static void main(String[] args) {
		Rectangle rectangle = new Rectangle(2,3);
		rectangle.set_width(4);
		rectangle = new Square(2); // the parent class is substituted with its child
		rectangle.set_width(4); // unexpected behavior because height should not be changed
}
~~~
The above example does not obey LSP because get_area() may result in unexpected behavior, therefore Rectangle cannot be substituted with Square.<br>
The problem can be solved if the child class inherits Shape class instead.
~~~java
public class Shape{
	string shape_type;
	int width;
	int height;
	public Shape(int width, int height) {
		this.width = width;
		this.height = height;
	}
}
~~~

## 4. Interface Segregation Principle
No class should depend on code it does not use.
~~~java
class computer {
	void chatting(){
	}
	void web_browser(){
	}
	void windows_game(){
	}
}

class iphone extends computer{
	void windows_game(){
		System.out.println("Error: not supported!");
	}
}
~~~
The above example does not obey ISP because windows_game() is not supported in iphone.
windows_game() should be moved to a separated interface

## 5. Dependency Inversion Principle
High level modules should not depend on low level modules to prevent tight coupling even though it is natural for a high level module to depend on a low level module.<br>
In other words, a high level module should work regardless of changes to its low level module.
~~~java
class Samsung_pay {
    void payment() {
        System.out.println("samsung");
    }
}

class Pay_service {
    Samsung_pay pay_type;
    
    void payment(Samsung_pay pay_type) {
        this.pay_type.payment();
    }
}
~~~
The above example does not obey DIP because Pay_service depends on its low level module Samsung_pay.<br>
That is to say, if the low level module Samsung_pay changes, the high level module Pay_service has to be changed accordingly, which is a waste.(tight coupling)
~~~java
interface Pay_type{
	void payment();
}

class Samsung_pay implements Pay_type {
    void payment() {
        System.out.println("samsung");
    }
}
class Apple_pay implements Pay_type {
    void payment() {
        System.out.println("apple");
    }
}

class Pay_service {
    Pay_type pay_type;
    
    void payment(Pay_type pay_type) {
        this.pay_type.payment();
    }
}
~~~
Pay_service depends on its low level module Pay_type where changing the low level module does not matter.<br>
Even if Samsung_pay changes, Pay_service does not need to be changed thanks to the **polymorphism** of Pay_type.(loose coupling)

### Dependency injection
This process is automated in Spring framework.
~~~java
public class Kiosk {
    public void init_pay_service() {
        // Creation of bean
        Pay_type samsung_pay = new Samsung_pay();
        // Dependency injection
        Pay_service pay_service = new Pay_service(samsung_pay);
    }
}
~~~
