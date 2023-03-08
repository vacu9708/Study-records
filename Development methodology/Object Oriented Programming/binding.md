# Types of binding
- Static binding: The address is set upon compile.
- Dynamic binding: The address is going to be set upon the allocation of the class in case the type of its objects is not fixed. Polymorphism is meaningful thanks to **dynamic binding**.
~~~c++
#include <iostream>
using namespace std;

class Person {
public:
    void static_binding() {
        printf("static: Person\n");
    }
    virtual void dynamic_binding() {
        printf("dynamic: Person\n");
    }
};

class Male : public Person {
public:
    void static_binding() {
        printf("static: Male\n");
    }
    void dynamic_binding() {
        printf("dynamic: Male\n");
    }
};

class Female : public Person {
};

void get_info(Person* person) {
    person->static_binding();
    person->dynamic_binding();
    printf("---\n");
}

int main(void) {
    Person* person;
    person = new Person();
    get_info(person);
    person = new Male();
    get_info(person);
    person = new Female();
    get_info(person);
}
~~~
# Output
![image](https://user-images.githubusercontent.com/67142421/221264116-ce996b0f-d8b5-4356-aa01-4397eb64cdd7.png)

