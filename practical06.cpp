
#include <iostream>
using namespace std;

// Abstract Base Class
class Shape {
public:
    virtual double area() = 0;  // Pure virtual function

    virtual ~Shape() {}
};

// Derived Class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() override {
        return 3.14 * radius * radius;
    }
};

// Derived Class: Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() override {
        return length * width;
    }
};

// Derived Class: Triangle
class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    double area() override {
        return 0.5 * base * height;
    }
};

int main() {
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(8, 5);

    // Base class pointers
    Shape* shapes[3];

    shapes[0] = &c;
    shapes[1] = &r;
    shapes[2] = &t;

    cout << "Area of Circle: " << shapes[0]->area() << endl;
    cout << "Area of Rectangle: " << shapes[1]->area() << endl;
    cout << "Area of Triangle: " << shapes[2]->area() << endl;

    return 0;
}
