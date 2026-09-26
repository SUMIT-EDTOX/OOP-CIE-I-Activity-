#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() const {
        cout << "Animal makes a sound" << endl;
    }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void sound() const override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() const override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;

    Animal* animal = &dog;
    animal->sound();

    animal = &cat;
    animal->sound();

    return 0;
}
