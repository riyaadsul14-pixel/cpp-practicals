
#include <iostream>
#include <exception>
#include <string>
using namespace std;

// Custom Exception: Invalid Amount
class InvalidAmount : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid amount! Amount must be greater than zero.";
    }
};

// Custom Exception: Insufficient Funds
class InsufficientFunds : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient balance! Withdrawal cannot be completed.";
    }
};

// Bank Account Class
class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw InvalidAmount();
        }

        if (amount > balance) {
            throw InsufficientFunds();
        }

        balance -= amount;

        cout << "Withdrawal successful: Rs. "
             << amount << endl;
    }

    void displayBalance() {
        cout << "Current Balance: Rs. "
             << balance << endl;
    }
};

int main() {
    BankAccount account(5000);

    cout << "--- Banking Transaction System ---" << endl;
    account.displayBalance();

    // Successful Transaction
    try {
        cout << "\nTransaction 1:" << endl;
        account.withdraw(1000);
    }
    catch (const InvalidAmount& e) {
        cout << e.what() << endl;
    }
    catch (const InsufficientFunds& e) {
        cout << e.what() << endl;
    }

    account.displayBalance();

    // Insufficient Funds Transaction
    try {
        cout << "\nTransaction 2:" << endl;
        account.withdraw(6000);
    }
    catch (const InvalidAmount& e) {
        cout << e.what() << endl;
    }
    catch (const InsufficientFunds& e) {
        cout << e.what() << endl;
    }

    account.displayBalance();

    // Invalid Amount Transaction
    try {
        cout << "\nTransaction 3:" << endl;
        account.withdraw(-500);
    }
    catch (const InvalidAmount& e) {
        cout << e.what() << endl;
    }
    catch (const InsufficientFunds& e) {
        cout << e.what() << endl;
    }

    account.displayBalance();

    return 0;
}
