#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void addBook(const string& isbn, const string& title, const string& author, bool available) {
    ofstream out("books_db.txt", ios::app);
    if (out) {
        out << isbn << "|" << title << "|" << author << "|" << (available ? "1" : "0") << "\n";
    }
}

void displayBooks() {
    ifstream in("books_db.txt");
    if (!in) {
        cout << "No library records found." << endl;
        return;
    }
    string line;
    cout << "\n--- Library Book Catalog ---" << endl;
    while (getline(in, line)) {
        stringstream ss(line);
        string isbn, title, author, avail;
        if (getline(ss, isbn, '|') && getline(ss, title, '|') &&
            getline(ss, author, '|') && getline(ss, avail)) {
            cout << "ISBN: " << isbn << " | " << title << " by " << author 
                 << " [" << (avail == "1" ? "Available" : "Issued") << "]" << endl;
        }
    }
}

int main() {
    addBook("978-0131103627", "The C++ Programming Language", "Bjarne Stroustrup", true);
    addBook("978-0201633610", "Design Patterns", "Gang of Four", false);
    displayBooks();
    return 0;
}
