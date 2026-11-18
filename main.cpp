
#include <iostream>
using namespace std;

int main() {
    int age;
    float marks;
    const int MAX_MARKS = 100;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your marks: ";
    cin >> marks;

    float percentage = (marks / MAX_MARKS) * 100;

    bool passed = (marks >= 40);
    bool eligible = (age >= 18 && passed);

    cout << "\n--- Student Details ---" << endl;
    cout << "Age: " << age << endl;
    cout << "Marks: " << marks << endl;
    cout << "Percentage: " << percentage << "%" << endl;
    cout << "Passed: " << (passed ? "Yes" : "No") << endl;
    cout << "Eligible: " << (eligible ? "Yes" : "No") << endl;

    return 0;
}
