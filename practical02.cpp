
#include <iostream>
using namespace std;

// Class declaration
class BankAccount {
    
    // Private members: Cannot be accessed directly outside the class
    int accountNumber;
    double balance;

public:
    // Constructor to initialize account details
    BankAccount(int accNo, double bal) {
        accountNumber = accNo;
        balance = (bal >= 0) ? bal : 0;
    }

    // Public member function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful!" << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Public member function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful!" << endl;
        } else {
            cout << "Invalid withdrawal!" << endl;
        }
    }

    // Public function to display account details
    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main() {

    // Creating two objects
    BankAccount acc1(101, 5000);
    BankAccount acc2(102, 8000);

    cout << "--- Account 1 ---" << endl;
    acc1.display();
    acc1.deposit(2000);
    acc1.withdraw(1000);
    acc1.display();

    cout << "\n--- Account 2 ---" << endl;
    acc2.display();
    acc2.deposit(1500);
    acc2.withdraw(500);
    acc2.display();

    return 0;
}
