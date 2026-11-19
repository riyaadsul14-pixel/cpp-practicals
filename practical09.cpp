
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Generic Stack Class
template <class T>
class Stack {
private:
    vector<T> items;

public:
    // Push element
    void push(T value) {
        items.push_back(value);
        cout << value << " pushed into stack." << endl;
    }

    // Pop element
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop."
                 << endl;
            return;
        }

        cout << items.back() << " popped from stack."
             << endl;
        items.pop_back();
    }

    // Check whether stack is empty
    bool isEmpty() {
        return items.empty();
    }

    // Access top element safely
    void top() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element."
                 << endl;
            return;
        }

        cout << "Top element: " << items.back() << endl;
    }
};

int main() {

    // Integer Stack
    cout << "--- Integer Stack ---" << endl;
    Stack<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.top();
    s1.pop();

    // Float Stack
    cout << "\n--- Float Stack ---" << endl;
    Stack<float> s2;

    s2.push(10.5);
    s2.push(20.5);
    s2.top();
    s2.pop();

    // String Stack
    cout << "\n--- String Stack ---" << endl;
    Stack<string> s3;

    s3.push("Hello");
    s3.push("C++");
    s3.top();
    s3.pop();

    // Empty Stack Condition
    cout << "\n--- Empty Stack Test ---" << endl;
    Stack<int> s4;

    s4.pop();
    s4.top();

    return 0;
}
