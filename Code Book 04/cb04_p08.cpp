#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("students.txt");
    if (!inputFile) {
        cerr << "Error: Could not open students.txt" << endl;
        return 1;
    }

    int targetRollNumber;
    cout << "Enter roll number to search: ";
    cin >> targetRollNumber;

    string line;
    bool found = false;
    while (getline(inputFile, line)) {
        stringstream record(line);
        string rollText, name, marksText;

        if (getline(record, rollText, '|') &&
            getline(record, name, '|') &&
            getline(record, marksText)) {
            int rollNumber = stoi(rollText);
            double marks = stod(marksText);

            if (rollNumber == targetRollNumber) {
                cout << "Record Found" << endl;
                cout << "Roll Number: " << rollNumber << endl;
                cout << "Name: " << name << endl;
                cout << "Marks: " << marks << endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "Student record not found." << endl;
    }
    return 0;
}
