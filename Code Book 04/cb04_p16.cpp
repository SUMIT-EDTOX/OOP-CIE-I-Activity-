#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <utility>
using namespace std;

class Book {
private:
    int bookId;
    string title;
    string author;
    bool issued;

public:
    Book(int id, string bookTitle, string bookAuthor, bool issueStatus = false)
        : bookId(id), title(move(bookTitle)), author(move(bookAuthor)), issued(issueStatus) {}

    int getBookId() const {
        return bookId;
    }

    string toFileRecord() const {
        return to_string(bookId) + "|" + title + "|" + author + "|" + (issued ? "1" : "0");
    }

    void display() const {
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Status: " << (issued ? "Issued" : "Available") << endl;
    }
};

void addBook() {
    int id;
    string title;
    string author;

    cout << "Enter book ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);

    Book book(id, title, author);
    ofstream outputFile("library_books.txt", ios::app);
    if (!outputFile) {
        cerr << "Error: Could not open library_books.txt" << endl;
        return;
    }

    outputFile << book.toFileRecord() << endl;
    cout << "Book added successfully." << endl;
}

void displayBooks() {
    ifstream inputFile("library_books.txt");
    if (!inputFile) {
        cout << "No library record file found." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream record(line);
        string idText, title, author, issuedText;

        if (getline(record, idText, '|') &&
            getline(record, title, '|') &&
            getline(record, author, '|') &&
            getline(record, issuedText)) {
            Book book(stoi(idText), title, author, issuedText == "1");
            book.display();
            cout << "-----------------------------------" << endl;
        }
    }
}

int main() {
    int choice;
    do {
        cout << "\nLibrary Record System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 0: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
