#include <iostream>
using namespace std;

class Distance {
private:
    int meters;
public:
    explicit Distance(int value) : meters(value) {}

    bool operator>(const Distance& other) const {
        return meters > other.meters;
    }

    void display() const {
        cout << meters << " meters" << endl;
    }
};

int main() {
    Distance first(120);
    Distance second(90);

    cout << "First distance: ";
    first.display();

    cout << "Second distance: ";
    second.display();

    if (first > second) {
        cout << "First distance is greater" << endl;
    } else {
        cout << "Second distance is greater or equal" << endl;
    }

    return 0;
}
