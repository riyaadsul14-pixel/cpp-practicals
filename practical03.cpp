#include <iostream>
#include <utility>
using namespace std;

class IntArray {
private:
    int* data;
    int size;

public:
    // Default Constructor
    IntArray() {
        size = 0;
        data = nullptr;
        cout << "Default Constructor Called" << endl;
    }

    // Parameterized Constructor
    IntArray(int s) {
        size = s;
        data = (size > 0) ? new int[size] : nullptr;

        for (int i = 0; i < size; i++) {
            data[i] = i + 1;
        }

        cout << "Parameterized Constructor Called" << endl;
    }

    // 1. Copy Constructor (Deep Copy)
    IntArray(const IntArray& other) {
        size = other.size;
        data = (size > 0) ? new int[size] : nullptr;

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }

        cout << "Copy Constructor Called" << endl;
    }

    // 2. Copy Assignment Operator
    IntArray& operator=(const IntArray& other) {
        if (this != &other) {
            int* newData = (other.size > 0)
                ? new int[other.size] : nullptr;

            for (int i = 0; i < other.size; i++) {
                newData[i] = other.data[i];
            }

            delete[] data;
            data = newData;
            size = other.size;
        }

        cout << "Copy Assignment Called" << endl;
        return *this;
    }

    // 3. Move Constructor
    IntArray(IntArray&& other) noexcept {
        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;

        cout << "Move Constructor Called" << endl;
    }

    // 4. Move Assignment Operator
    IntArray& operator=(IntArray&& other) noexcept {
        if (this != &other) {
            delete[] data;

            data = other.data;
            size = other.size;

            other.data = nullptr;
            other.size = 0;
        }

        cout << "Move Assignment Called" << endl;
        return *this;
    }

    // Display Function
    void display() {
        cout << "Array Elements: ";

        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }

        cout << endl;
    }

    // 5. Destructor
    ~IntArray() {
        delete[] data;
        cout << "Destructor Called" << endl;
    }
};

int main() {

    cout << "\n--- Default Constructor ---" << endl;
    IntArray a;

    cout << "\n--- Parameterized Constructor ---" << endl;
    IntArray b(3);
    b.display();

    cout << "\n--- Copy Constructor ---" << endl;
    IntArray c(b);
    c.display();

    cout << "\n--- Copy Assignment ---" << endl;
    IntArray d;
    d = b;
    d.display();

    cout << "\n--- Move Constructor ---" << endl;
    IntArray e(move(c));
    e.display();

    cout << "\n--- Move Assignment ---" << endl;
    IntArray f;
    f = move(d);
    f.display();

    return 0;
}
