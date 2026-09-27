#include <cctype>
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

    size_t lineCount = 0;
    size_t wordCount = 0;
    size_t characterCount = 0;
    bool insideWord = false;
    char ch;

    while (inputFile.get(ch)) {
        ++characterCount;
        if (ch == '\n') {
            ++lineCount;
        }
        if (isspace(static_cast<unsigned char>(ch))) {
            insideWord = false;
        } else if (!insideWord) {
            ++wordCount;
            insideWord = true;
        }
    }

    if (characterCount > 0) {
        inputFile.clear();
        inputFile.seekg(-1, ios::end);
        char lastCharacter;
        inputFile.get(lastCharacter);
        if (lastCharacter != '\n') {
            ++lineCount;
        }
    }

    cout << "Lines: " << lineCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Characters: " << characterCount << endl;
    return 0;
}
