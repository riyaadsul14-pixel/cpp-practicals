
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float marks;
};

int main() {
    Student students[3] = {
        {101, "Riya", 85.5},
        {102, "Aarav", 90.0},
        {103, "Siddhi", 88.5}
    };

    // Writing student records into CSV file
    ofstream fout("students.csv");

    if (!fout.is_open()) {
        cout << "Error opening CSV file!" << endl;
        return 1;
    }

    fout << "ID,Name,Marks" << endl;

    for (int i = 0; i < 3; i++) {
        fout << students[i].id << ","
             << students[i].name << ","
             << students[i].marks << endl;
    }

    if (!fout) {
        cout << "Error writing student records!" << endl;
        return 1;
    }

    fout.close();

    cout << "Student records written successfully."
         << endl;

    // Reading student records from CSV file
    ifstream fin("students.csv");

    if (!fin.is_open()) {
        cout << "Error opening CSV file for reading!"
             << endl;
        return 1;
    }

    cout << "\n--- Student Records ---" << endl;

    string line;
    getline(fin, line);  // Skip CSV header

    while (getline(fin, line)) {
        stringstream ss(line);
        string id, name, marks;

        if (!getline(ss, id, ',') ||
            !getline(ss, name, ',') ||
            !getline(ss, marks, ',')) {
            cout << "Malformed record skipped." << endl;
            continue;
        }

        try {
            Student s;
            s.id = stoi(id);
            s.name = name;
            s.marks = stof(marks);

            cout << "ID: " << s.id
                 << " | Name: " << s.name
                 << " | Marks: " << s.marks << endl;
        }
        catch (...) {
            cout << "Invalid record skipped." << endl;
        }
    }

    fin.close();

    // Demonstration of tellg() and seekg()
    cout << "\n--- Read Position Demonstration ---"
         << endl;

    ifstream readFile("students.csv");

    if (!readFile) {
        cout << "Unable to open CSV file." << endl;
        return 1;
    }

    cout << "Initial read position: "
         << readFile.tellg() << endl;

    char ch;
    readFile.get(ch);

    cout << "Character read: " << ch << endl;

    cout << "Position after reading one character: "
         << readFile.tellg() << endl;

    readFile.seekg(0);

    cout << "Position after seekg(0): "
         << readFile.tellg() << endl;

    readFile.close();

    // Demonstration of tellp() and seekp()
    cout << "\n--- Write Position Demonstration ---"
         << endl;

    fstream writeFile(
        "position.txt",
        ios::out | ios::trunc
    );

    if (!writeFile) {
        cout << "Unable to open position file." << endl;
        return 1;
    }

    writeFile << "HELLO";

    cout << "Write position after writing HELLO: "
         << writeFile.tellp() << endl;

    writeFile.seekp(1);

    cout << "Position after seekp(1): "
         << writeFile.tellp() << endl;

    writeFile.put('A');

    writeFile.close();

    cout << "Updated position.txt content: ";

    ifstream displayFile("position.txt");
    string content;
    getline(displayFile, content);
    cout << content << endl;

    displayFile.close();

    return 0;
}
