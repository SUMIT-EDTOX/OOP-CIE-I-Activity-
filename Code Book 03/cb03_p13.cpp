#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        cout << "Derived destructor" << endl;
    }
};

int main() {
    Base* pointer = new Derived();
    delete pointer;
    return 0;
}
