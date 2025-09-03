#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

// Class to represent a bank account
class BankAccount {
    int accountNumber;
    char name[100];
    double balance;

public:
    void createAccount();      // Get data from user
    void showAccount() const;  // Show data on screen
    void deposit(double);      // Add to balance
    void withdraw(double);     // Subtract from balance
    void report() const;       // Show data in tabular format
    int getAccountNumber() const; // Get account number
    double getBalance() const;   // Get balance
};

// Function to get account data from the user
void BankAccount::createAccount() {
    std::cout << "\nEnter The Account No. : ";
    std::cin >> accountNumber;
    std::cout << "\nEnter The Name of The Account Holder : ";
    std::cin.ignore();
    std::cin.getline(name, 100);
    std::cout << "\nEnter Initial Amount (>=500) : ";
    std::cin >> balance;
    if (balance < 500) {
        std::cout << "\nInitial amount must be at least 500. Setting balance to 500.";
        balance = 500;
    }
    std::cout << "\n\nAccount Created..";
}

// Function to display account details
void BankAccount::showAccount() const {
    std::cout << "\nAccount No. : " << accountNumber;
    std::cout << "\nAccount Holder Name : ";
    std::cout << name;
    std::cout << "\nBalance amount : " << balance;
}

// Function to deposit money
void BankAccount::deposit(double amount) {
    balance += amount;
}

// Function to withdraw money
void BankAccount::withdraw(double amount) {
    balance -= amount;
}

// Function to display account details in a report format
void BankAccount::report() const {
    std::cout << accountNumber << std::setw(10) << " " << name << std::setw(10) << " " << balance << std::endl;
}

// Function to get the account number
int BankAccount::getAccountNumber() const {
    return accountNumber;
}

// Function to get the current balance
double BankAccount::getBalance() const {
    return balance;
}


// Function declarations for file operations
void writeAccount();
void displaySpecific(int);
void modifyAccount(int);
void deleteAccount(int);
void displayAll();
void depositWithdraw(int, int);

// Main function
int main() {
    char ch;
    int num;
    do {
        system("cls"); // Use "clear" for Linux/macOS
        std::cout << "\n\n\t\tBANK MANAGEMENT SYSTEM";
        std::cout << "\n\n\t\t::MAIN MENU::\n";
        std::cout << "\n\t\t1. NEW ACCOUNT";
        std::cout << "\n\t\t2. DEPOSIT AMOUNT";
        std::cout << "\n\t\t3. WITHDRAW AMOUNT";
        std::cout << "\n\t\t4. BALANCE ENQUIRY";
        std::cout << "\n\t\t5. ALL ACCOUNT HOLDER LIST";
        std::cout << "\n\t\t6. CLOSE AN ACCOUNT";
        std::cout << "\n\t\t7. EXIT";
        std::cout << "\n\n\t\tSelect Your Option (1-7) ";
        std::cin >> ch;

        switch (ch) {
        case '1':
            writeAccount();
            break;
        case '2':
            std::cout << "\n\n\tEnter The account No. : ";
            std::cin >> num;
            depositWithdraw(num, 1); // 1 for deposit
            break;
        case '3':
            std::cout << "\n\n\tEnter The account No. : ";
            std::cin >> num;
            depositWithdraw(num, 2); // 2 for withdraw
            break;
        case '4':
            std::cout << "\n\n\tEnter The account No. : ";
            std::cin >> num;
            displaySpecific(num);
            break;
        case '5':
            displayAll();
            break;
        case '6':
            std::cout << "\n\n\tEnter The account No. : ";
            std::cin >> num;
            deleteAccount(num);
            break;
        case '7':
            std::cout << "\n\n\tThanks for using bank management system";
            break;
        default:
            std::cout << "\a";
        }
        std::cin.ignore();
        std::cin.get();
    } while (ch != '7');
    return 0;
}

// Function to write a new account to the file
void writeAccount() {
    BankAccount ac;
    std::ofstream outFile;
    outFile.open("accounts.dat", std::ios::binary | std::ios::app);
    ac.createAccount();
    outFile.write(reinterpret_cast<char*>(&ac), sizeof(BankAccount));
    outFile.close();
}

// Function to read and display a specific account from the file
void displaySpecific(int n) {
    BankAccount ac;
    bool flag = false;
    std::ifstream inFile;
    inFile.open("accounts.dat", std::ios::binary);
    if (!inFile) {
        std::cout << "File could not be open !! Press any Key...";
        return;
    }
    std::cout << "\nBALANCE DETAILS\n";
    while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(BankAccount))) {
        if (ac.getAccountNumber() == n) {
            ac.showAccount();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        std::cout << "\n\nAccount number does not exist";
}

// Function to modify an account in the file
void modifyAccount(int n) {
    bool found = false;
    BankAccount ac;
    std::fstream File;
    File.open("accounts.dat", std::ios::binary | std::ios::in | std::ios::out);
    if (!File) {
        std::cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false) {
        File.read(reinterpret_cast<char*>(&ac), sizeof(BankAccount));
        if (ac.getAccountNumber() == n) {
            ac.showAccount();
            std::cout << "\n\nEnter The New Details of account" << std::endl;
            ac.createAccount();
            int pos = (-1) * static_cast<int>(sizeof(BankAccount));
            File.seekp(pos, std::ios::cur);
            File.write(reinterpret_cast<char*>(&ac), sizeof(BankAccount));
            std::cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        std::cout << "\n\n Record Not Found ";
}


// Function to delete an account from the file
void deleteAccount(int n) {
    BankAccount ac;
    std::ifstream inFile;
    std::ofstream outFile;
    inFile.open("accounts.dat", std::ios::binary);
    if (!inFile) {
        std::cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat", std::ios::binary);
    inFile.seekg(0, std::ios::beg);
    while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(BankAccount))) {
        if (ac.getAccountNumber() != n) {
            outFile.write(reinterpret_cast<char*>(&ac), sizeof(BankAccount));
        }
    }
    inFile.close();
    outFile.close();
    remove("accounts.dat");
    rename("Temp.dat", "accounts.dat");
    std::cout << "\n\n\tRecord Deleted ..";
}

// Function to display all accounts from the file
void displayAll() {
    BankAccount ac;
    std::ifstream inFile;
    inFile.open("accounts.dat", std::ios::binary);
    if (!inFile) {
        std::cout << "File could not be open !! Press any Key...";
        return;
    }
    std::cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    std::cout << "====================================================\n";
    std::cout << "A/c no.      NAME           Balance\n";
    std::cout << "====================================================\n";
    while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(BankAccount))) {
        ac.report();
    }
    inFile.close();
}

// Function to handle deposit and withdrawal operations
void depositWithdraw(int n, int option) {
    double amt;
    bool found = false;
    BankAccount ac;
    std::fstream File;
    File.open("accounts.dat", std::ios::binary | std::ios::in | std::ios::out);
    if (!File) {
        std::cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false) {
        File.read(reinterpret_cast<char*>(&ac), sizeof(BankAccount));
        if (ac.getAccountNumber() == n) {
            ac.showAccount();
            if (option == 1) { // Deposit
                std::cout << "\n\n\tTO DEPOSIT AMOUNT ";
                std::cout << "\n\nEnter The amount to be deposited: ";
                std::cin >> amt;
                ac.deposit(amt);
            }
            if (option == 2) { // Withdraw
                std::cout << "\n\n\tTO WITHDRAW AMOUNT ";
                std::cout << "\n\nEnter The amount to be withdrawn: ";
                std::cin >> amt;
                double bal = ac.getBalance() - amt;
                if (bal < 500)
                    std::cout << "Insufficience balance";
                else
                    ac.withdraw(amt);
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, std::ios::cur);
            File.write(reinterpret_cast<char*>(&ac), sizeof(BankAccount));
            std::cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        std::cout << "\n\n Record Not Found ";
}