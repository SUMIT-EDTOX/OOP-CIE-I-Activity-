#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T* arr;
    size_t capacity;
    size_t count;

public:
    DynamicArray(size_t cap = 5) : capacity(cap), count(0) {
        if (cap == 0) throw invalid_argument("Capacity must be positive!");
        arr = new T[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void push(const T& val) {
        if (count >= capacity) throw overflow_error("Array capacity exceeded!");
        arr[count++] = val;
    }

    T get(size_t index) const {
        if (index >= count) throw out_of_range("Index is out of range!");
        return arr[index];
    }

    size_t size() const { return count; }

    void display() const {
        for (size_t i = 0; i < count; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    try {
        DynamicArray<string> names(3);
        names.push("Alice");
        names.push("Bob");
        cout << "Array contents: ";
        names.display();
        cout << "Element at index 1: " << names.get(1) << endl;
        cout << "Accessing invalid index:" << endl;
        names.get(5);
    } catch (const exception& ex) {
        cout << "Caught Exception: " << ex.what() << endl;
    }
    return 0;
}
