
#include <iostream>
using namespace std;

// Function Overloading
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

// Complex Number Class
class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r, double i) {
        real = r;
        imaginary = i;
    }

    // Operator Overloading (+)
    ComplexNumber operator+(ComplexNumber c) {
        return ComplexNumber(
            real + c.real,
            imaginary + c.imaginary
        );
    }

    void display() {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

int main() {
    // Function Overloading
    cout << "Function Overloading:" << endl;
    cout << "Addition of integers: "
         << add(10, 20) << endl;

    cout << "Addition of decimals: "
         << add(5.5, 2.5) << endl;

    // Operator Overloading
    cout << "\nOperator Overloading:" << endl;

    ComplexNumber c1(3, 4);
    ComplexNumber c2(2, 5);

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    ComplexNumber c3 = c1 + c2;

    cout << "Result after addition: ";
    c3.display();

    return 0;
}
