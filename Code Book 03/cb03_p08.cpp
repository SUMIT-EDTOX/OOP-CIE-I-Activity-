#include <iostream>
using namespace std;

class Base {
public:
    void display() const {
        cout << "Base display function" << endl;
    }
};

class Derived : public Base {
public:
    void display() const {
        cout << "Derived display function" << endl;
    }
};

int main() {
    Derived derivedObject;
    Base* basePointer = &derivedObject;
    basePointer->display();
    return 0;
}
