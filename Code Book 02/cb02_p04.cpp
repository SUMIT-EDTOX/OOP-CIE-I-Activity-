#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Person {
protected:
    string name;
public:
    explicit Person(string personName) : name(move(personName)) {}
    void showPerson() const {
        cout << "Name: " << name << endl;
    }
};

class Employee : public Person {
protected:
    int employeeId;
public:
    Employee(string employeeName, int id)
        : Person(move(employeeName)), employeeId(id) {}
    void showEmployee() const {
        cout << "Employee ID: " << employeeId << endl;
    }
};

class Manager : public Employee {
private:
    int teamSize;
public:
    Manager(string managerName, int id, int size)
        : Employee(move(managerName), id), teamSize(size) {}
    void showManager() const {
        showPerson();
        showEmployee();
        cout << "Team Size: " << teamSize << endl;
    }
};

int main() {
    Manager manager("Ravi", 501, 8);
    manager.showManager();
    return 0;
}
