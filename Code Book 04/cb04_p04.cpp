#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream sourceFile("message.txt");
    ofstream destinationFile("message_copy.txt");

    if (!sourceFile) {
        cerr << "Error: Could not open source file." << endl;
        return 1;
    }
    if (!destinationFile) {
        cerr << "Error: Could not create destination file." << endl;
        return 1;
    }

    string line;
    while (getline(sourceFile, line)) {
        destinationFile << line << endl;
    }

    cout << "File copied successfully to message_copy.txt" << endl;
    return 0;
}
