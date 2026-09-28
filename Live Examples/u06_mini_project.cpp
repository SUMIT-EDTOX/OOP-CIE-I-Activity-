#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <numeric>
using namespace std;

struct CartItem {
    string name;
    double price;
    int quantity;
};

int main() {
    map<string, double> catalog = {
        {"Laptop", 55000.0},
        {"Mouse", 450.0},
        {"Keyboard", 1200.0},
        {"Monitor", 12500.0}
    };

    vector<CartItem> cart;
    cart.push_back({"Laptop", catalog["Laptop"], 1});
    cart.push_back({"Mouse", catalog["Mouse"], 2});
    cart.push_back({"Keyboard", catalog["Keyboard"], 1});

    cout << "== E-Commerce Cart Invoice ==" << endl;
    double grandTotal = 0.0;
    for (const auto& item : cart) {
        double subtotal = item.price * item.quantity;
        grandTotal += subtotal;
        cout << item.name << " x " << item.quantity << " @ Rs. " << item.price 
             << " = Rs. " << subtotal << endl;
    }

    cout << "--------------------------------" << endl;
    cout << "Total Invoice Amount: Rs. " << grandTotal << endl;

    return 0;
}
