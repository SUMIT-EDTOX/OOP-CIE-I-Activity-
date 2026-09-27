#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream outputFile("message.txt");
    if (!outputFile) {
        cerr << "Error: Could not create message.txt" << endl;
        return 1;
    }

    outputFile << "Welcome to C++ File Handling" << endl;
    outputFile << "This is the first line written to a file." << endl;
    outputFile << "Files store data permanently." << endl;
    outputFile.close();

    cout << "Data written successfully to message.txt" << endl;
    return 0;
}
