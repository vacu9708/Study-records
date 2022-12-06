#include <iostream>
using namespace std;

class Person {
public:
    void static_binding() { // The address is set to class A (static binding)
        printf("Neutral\n");
    }
    virtual void dynamic_binding() { // The address is going to be set later in case of inheritance (dynamic binding)
        printf("Neutral\n");
    }
};

class Male: public Person {
public:
    void static_binding() {
        printf("Male\n");
    }
    void dynamic_binding() {
        printf("Male\n");
    }
};

class Female: public Person {
public:
    void dynamic_binding() {
        printf("Female\n");
    }
};

void get_info(Person* person) {
    person->static_binding();
    person->dynamic_binding();
    printf("---\n");
}

int main(void) {
    Person* person = new Person();
    get_info(person);
    person = new Male();
    get_info(person);
    person = new Female();
    get_info(person);
}

# Output
![image](https://user-images.githubusercontent.com/67142421/205872545-d0cf356c-5093-4ceb-8bf0-11fd312b63e8.png)
