#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream outputFile("message.txt", ios::app);
    if (!outputFile) {
        cerr << "Error: Could not open message.txt for appending" << endl;
        return 1;
    }

    outputFile << "This line was added using append mode." << endl;
    outputFile.close();

    cout << "New line appended successfully." << endl;
    return 0;
}
