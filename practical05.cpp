
#include <iostream>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived Class: Single Inheritance
class Student : public Person {
protected:
    int studentID;
    string course;

public:
    Student(string n, int a, int id, string c)
        : Person(n, a) {
        studentID = id;
        course = c;
    }

    void displayStudent() {
        displayPerson();
        cout << "Student ID: " << studentID << endl;
        cout << "Course: " << course << endl;
    }
};

// Derived Class: Multilevel Inheritance
class GraduateStudent : public Student {
private:
    string researchTopic;
    string supervisor;

public:
    GraduateStudent(string n, int a, int id,
                    string c, string topic, string sup)
        : Student(n, a, id, c) {
        researchTopic = topic;
        supervisor = sup;
    }

    void displayGraduate() {
        displayStudent();
        cout << "Research Topic: " << researchTopic << endl;
        cout << "Supervisor: " << supervisor << endl;
    }
};

int main() {

    // Student object: Single Inheritance
    cout << "--- Student Details ---" << endl;

    Student s1("Riya", 20, 101, "Computer Engineering");
    s1.displayStudent();

    // GraduateStudent object: Multilevel Inheritance
    cout << "\n--- Graduate Student Details ---" << endl;

    GraduateStudent g1("Aarav", 23, 201,
                       "Computer Science",
                       "Artificial Intelligence",
                       "Dr. Sharma");

    g1.displayGraduate();

    return 0;
}
