#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("message.txt");
    if (!inputFile) {
        cerr << "Error: Could not open message.txt" << endl;
        return 1;
    }

    string line;
    cout << "File Content:" << endl;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    inputFile.close();
    return 0;
}
