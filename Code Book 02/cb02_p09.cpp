#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Person {
protected:
    string name;
public:
    explicit Person(string personName) : name(move(personName)) {}
};

class Student : public Person {
private:
    int rollNumber;
public:
    Student(string studentName, int roll)
        : Person(move(studentName)), rollNumber(roll) {}
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
    }
};

int main() {
    Student student("Kiran", 24);
    student.display();
    return 0;
}
