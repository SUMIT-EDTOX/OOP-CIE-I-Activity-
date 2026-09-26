#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() const {
        cout << "Base object" << endl;
    }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void display() const override {
        cout << "Derived object" << endl;
    }
};

void displayByValue(Base object) {
    object.display();
}

void displayByReference(const Base& object) {
    object.display();
}

int main() {
    Derived derived;

    cout << "Passing by value: ";
    displayByValue(derived);

    cout << "Passing by reference: ";
    displayByReference(derived);

    return 0;
}
