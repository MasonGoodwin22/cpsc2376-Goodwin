#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

const string FILENAME = "account_balance.txt";
const double INITIAL_BALANCE = 100.00;

double readBalanceFromFile() {
    ifstream file(FILENAME);
    double balance;
    if (file.is_open()) {
        file >> balance;
        file.close();
    } else {
        balance = INITIAL_BALANCE;
        ofstream newFile(FILENAME);
        newFile << fixed << setprecision(2) << balance;
        newFile.close();
        cout << "Initializing account with $" << balance << "...\n";
    }
    return balance;
}

void writeBalanceToFile(double balance) {
    ofstream file(FILENAME);
    if (file.is_open()) {
        file << fixed << setprecision(2) << balance;
        file.close();
    } else {
        cerr << "Error: Unable to update balance file." << endl;
        exit(1);
    }
}

void checkBalance(double balance) {
    cout << "Your current balance is: $" << fixed << setprecision(2) << balance << "\n";
}

void deposit(double &balance) {
    double amount;
    cout << "Enter deposit amount: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Error: Deposit amount must be positive.\n";
        return;
    }
    balance += amount;
    writeBalanceToFile(balance);
    cout << "Deposit successful. Your new balance is: $" << fixed << setprecision(2) << balance << "\n";
}

void withdraw(double &balance) {
    double amount;
    cout << "Enter withdrawal amount: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Error: Withdrawal amount must be positive.\n";
        return;
    }
    if (amount > balance) {
        cout << "Error: Insufficient funds. Your balance is $" << fixed << setprecision(2) << balance << "\n";
        return;
    }
    balance -= amount;
    writeBalanceToFile(balance);
    cout << "Withdrawal successful. Your new balance is: $" << fixed << setprecision(2) << balance << "\n";
}

void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    cout << "Welcome to Your Bank Account!\n";
    double balance = readBalanceFromFile();
    int choice;
    do {
        displayMenu();
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }
        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                deposit(balance);
                break;
            case 3:
                withdraw(balance);
                break;
            case 4:
                cout << "Thank you for using Your Bank Account. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
        }
    } while (choice != 4);
    return 0;
}
