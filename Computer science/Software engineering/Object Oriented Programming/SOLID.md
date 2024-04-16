# Cohesion and coupling
### Cohesion
- Cohesion refers to the degree to which the functionality is focused within a single component.
- High cohesion indicates that the component is well-defined and performs a specific task effectively.
### Coupling
- Coupling measures how closely connected two components are to each other.
- Loose coupling means that changes in one(child) component do not necessitate changes in another(parent) component thanks to the existence of the interface, leading to improved maintainability.
### How to make loose coupling
- For a lowly coupled system, modules should interact through interfaces or abstractions to minimize their dependencies on each other.<br>
- An interface makes it possible for multiple child modules to be used with that one interface.

# SOLID design principles in OOP
SOLID principles were introduced in an effort to keep cohesion high and coupling low.
## 1. Single Responsibility Principle
A class should have only one reason to change.<br>
Every component of code (in general a class, but also a function) should have only one responsibility.<br>
For example, a single component, generically named(like "main"), doing all the work is bad.<br>
If a component of code has more than one responsibility, code maintenace becomes hard.<br>
### Example of not obeying SRP
~~~java
public class User {
    private String name;
    private String email;
    private String password;

    public User(String name, String email, String password) {
        this.name = name;
        this.email = email;
        this.password = password;
    }

    public void updateEmail(String newEmail) {
        // Update the user's email in the database
        this.email = newEmail;
    }

    public void sendEmail(String recipient, String message) {
	// Implementation details of sending email
        // ...
    }
}
~~~

### Example of obeying SRP
~~~java
public class User {
    private String name;
    private String email;
    private String password;

    public User(String name, String email, String password) {
        this.name = name;
        this.email = email;
        this.password = password;
    }

    public void updateEmail(String newEmail) {
        // Update the user's email in the database
        this.email = newEmail;
    }
}

public class NotificationService {
    public void sendEmail(String recipient, String message) {
        // Implementation details of sending email
        // ...
    }
}


~~~
#### Primary advantage:
High cohesion

## 2. Open, Closed Principle
The principle states that components should be open for extension but closed for modification. In other words, components should be easily extended without modifying their existing code.<br>
The OCP go hand in hand with the ***Single Responsibility Principle***, which facilitates high cohesion and ***Dependency Inversion Principle***, which facilitates loose coupling.<br>
#### Primary advantage:
High cohesion, Loose coupling

## 3. Liskov Substitution Principle
Child classes must be substitutable for their parent classes.<br>
LSP enables the use of subtype polymorphism, which allows a subclass to be treated as their superclass. This enables modularity and extensibility by allowing new subclasses to be added without affecting the existing code.<br>
LSP facilitates Dependency inversion by allowing high-level modules to depend on the abstraction of low level modules.<br>
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
High cohesion(one interface only has one functionality), Loose coupling(only necessary dependencies)
### Example of not obeying ISP
~~~java
public interface Printer {
    void print();
    void scan();
}

class Scanner implements Printer {
    public void print() {
        System.out.println("Printing");
    }
    
    public void scan() {
        System.out.println("Scanning");
    }
}
~~~
The above example violates ISP because the child component Scanner depends on the unnecessary component Printer.<br>

### Example of obeying ISP
~~~java
interface Printer {
    void print();
}

interface Scanner {
    void scan();
}

interface AdvancedPrinter extends Printer, Scanner {
    void print();
    void scan();   
}

class AdvancedPrinterImpl implements AdvancedPrinter {
    public void print() {
        System.out.println("Printing");
    }
    
    public void scan() {
        System.out.println("Scanning");
    }
}
~~~
By following the Interface Segregation Principle, the code is more modular.<br>

## 5. Dependency Inversion Principle
The name refers to the inversion of the traditional dependency direction, where a high-level module directly depends on its low-level modules.<br>
DIP states that a high-level module should not directly depend on its low-level modules, but their abstraction, so that the high level module can work without needing to writing code for each of its low level module.<br>
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
The above example does not obey DIP because PayService depends on its low level module SamsungPay.<br>
If the low level module(dependency) SamsungPay changes or a new dependency is added, PayService is forced to be changed accordingly, which is inefficient.(tight coupling)

### Example of obeying DIP
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/6f7ab505-d273-48a3-a8a2-c6469661c375)

~~~java
interface PayType{
	String payment();
}

class Samsung_pay implements PayType {
    	String payment() {
		return "samsung";
    }
}
class Apple_pay implements PayType {
 	String payment() {
        	return "apple";
    }
}

class Pay_service {
	PayType payType;
	setPayType(PayType payType) {
		this.pay_type = pay_type;
 	}

	pay() {
		this.payType.payment();
	}
}
~~~
Whether pay_type is samsung or apple, Pay_service does not need to be changed thanks to the **polymorphism** of Pay_type.(loose coupling)
