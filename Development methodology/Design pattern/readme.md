~~~
A design pattern provides a solution for the common problems that occur in software design.
It facilitates maintenance and communication between coworkers.
~~~

# Creational patterns
>decide how an object has to be created.<br>

List : Factory Method, Abstract Factory, Builder, Singleton, Object Pool, and Prototype. 

## Singleton
It is used to allow only one instance of a class.

## Prototype
The pattern of javascript prototype

## Builder
~~~java
public class Car {
    private String make;
    private String model;

    Car(String make, String model) {
        this.make = make;
        this.model = model;
    }

    public static CarBuilder builder() {
        return new CarBuilder();
    }

    public String getMake() {
        return this.make;
    }

    public String getModel() {
        return this.model;
    }

    public static class CarBuilder {
        private String make;
        private String model;

        CarBuilder() {
        }

        public CarBuilder make(String make) {
            this.make = make;
            return this;
        }

        public CarBuilder model(String model) {
            this.model = model;
            return this;
        }

        public Car build() {
            return new Car(this.make, this.model);
        }
    }
}

Car car = Car.builder()
                .make("Toyota")
                .model("Camry")
                .build();
~~~

---
# Structural patterns
>manipulate a relationship between objects.<br>

List : Adapter, Bridge, Composite, Decorator, Facade, Flyweight, Private Class Data, and Proxy.

## Adaptor
When 2 interfaces are not compatible with each other, a new class can be created to connect them.<br>
![image](https://user-images.githubusercontent.com/67142421/178671279-5239da73-796e-48cd-b44e-ef2dd7e21ee1.png)<br>

---
# Behavioral patterns
>are about algorithms and the assignment of responsibilities between objects.<br>

List : Chain of responsibility, Command, Interpreter, Iterator, Mediator, Memento, Null Object, Observer, State, Strategy, Template method, Visitor 

## Template method
It is to define skeleton algorithms and leave the details to be implemented by the child classes.
