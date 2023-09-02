
#include <vector>
#include <iomanip>



#include <iostream>

// Define a class for transactions
class Transaction {
public:
    std::string type;
    double amount;

    Transaction(const std::string& _type, double _amount)
        : type(_type), amount(_amount) {}
};

// Define a class for an ATM account
class Account {
public:
    std::string accountNumber;
    double balance;
    std::vector<Transaction> transactionHistory;

    Account(const std::string& _accountNumber, double initialBalance)
        : accountNumber(_accountNumber), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionHistory.push_back(Transaction("Deposit", amount));
            std::cout << "Deposit successful. Current balance: $" << balance << "\n";
        } else {
            std::cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactionHistory.push_back(Transaction("Withdraw", amount));
            std::cout << "Withdrawal successful. Current balance: $" << balance << "\n";
        } else {
            std::cout << "Invalid withdrawal amount or insufficient balance.\n";
        }
    }

    void transfer(Account& recipient, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            recipient.balance += amount;
            transactionHistory.push_back(Transaction("Transfer", amount));
            std::cout << "Transfer successful. Current balance: $" << balance << "\n";
        } else {
            std::cout << "Invalid transfer amount or insufficient balance.\n";
        }
    }

    void displayTransactionHistory() {
        std::cout << "Transaction History for Account " << accountNumber << ":\n";
        std::cout << std::setw(15) << "Transaction" << std::setw(10) << "Amount\n";
        for (const Transaction& transaction : transactionHistory) {
            std::cout << std::setw(15) << transaction.type << std::setw(10) << "$" << transaction.amount << "\n";
        }
    }
};

int main() {
    // Create two accounts for testing
    Account account1("123456", 1000.0);
    Account account2("789101", 500.0);

    std::string accountId;
    int option;
    double amount;

    std::cout << "Welcome to the ATM Interface\n";
    std::cout << "Enter your account number: ";
    std::cin >> accountId;

    // Assuming PIN validation would be done here

    while (true) {
        std::cout << "\nATM Menu:\n";
        std::cout << "1. View Transaction History\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Deposit\n";
        std::cout << "4. Transfer\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;

        switch (option) {
            case 1:
                account1.displayTransactionHistory(); // Display transaction history for account1
                break;
            case 2:
                std::cout << "Enter withdrawal amount: $";
                std::cin >> amount;
                account1.withdraw(amount); // Withdraw from account1
                break;
            case 3:
                std::cout << "Enter deposit amount: $";
                std::cin >> amount;
                account1.deposit(amount); // Deposit to account1
                break;
            case 4:
                std::cout << "Enter recipient account number: ";
                std::cin >> accountId;
                if (accountId == account2.accountNumber) {
                    std::cout << "Enter transfer amount: $";
                    std::cin >> amount;
                    account1.transfer(account2, amount); // Transfer from account1 to account2
                } else {
                    std::cout << "Recipient account not found.\n";
                }
                break;
            case 5:
                std::cout << "Thank you for using the ATM. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}







































































































