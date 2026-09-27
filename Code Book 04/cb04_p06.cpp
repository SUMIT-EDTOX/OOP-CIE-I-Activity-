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

    string searchWord;
    cout << "Enter word to search: ";
    cin >> searchWord;

    string word;
    int count = 0;
    while (inputFile >> word) {
        if (word == searchWord) {
            ++count;
        }
    }

    cout << "The word '" << searchWord << "' occurred " << count << " time(s)." << endl;
    return 0;
}
