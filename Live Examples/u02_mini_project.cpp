#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Account {
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account(int accNo, string name, double bal)
        : accountNumber(accNo), holderName(name), balance(bal) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited Rs. " << amount << ". New Balance: Rs. " << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew Rs. " << amount << ". New Balance: Rs. " << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void calculateInterest() = 0;

    virtual void display() const {
        cout << "Account: " << accountNumber << " | Holder: " << holderName 
             << " | Balance: Rs. " << balance << endl;
    }

    virtual ~Account() = default;
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : Account(accNo, name, bal), interestRate(rate) {}

    void calculateInterest() override {
        double interest = (balance * interestRate) / 100.0;
        balance += interest;
        cout << "Savings Interest Added: Rs. " << interest << ". Balance: Rs. " << balance << endl;
    }
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(int accNo, string name, double bal, double limit)
        : Account(accNo, name, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrew Rs. " << amount << " using overdraft. Balance: Rs. " << balance << endl;
        } else {
            cout << "Exceeded overdraft limit!" << endl;
        }
    }

    void calculateInterest() override {
        cout << "No interest for Current Account." << endl;
    }
};

int main() {
    vector<unique_ptr<Account>> bank;
    bank.push_back(make_unique<SavingsAccount>(1001, "Rahul Patil", 15000.0, 4.0));
    bank.push_back(make_unique<CurrentAccount>(1002, "Sneha Enterprise", 25000.0, 10000.0));

    cout << "== Bank Accounts Dashboard ==" << endl;
    for (const auto& acc : bank) {
        acc->display();
        acc->calculateInterest();
        cout << endl;
    }

    return 0;
}
