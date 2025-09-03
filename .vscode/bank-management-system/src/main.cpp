#include <iostream>
#include <fstream>
#include <windows.h>
#include "account.h"

using namespace std;

int main() {
    Account mynew;
    bool exit = false;

    while (!exit) {
        system("cls");
        int val;
        cout << "\tWelcome To Bank Management System" << endl;
        cout << "\t####################################" << endl;
        cout << "\t1. Open New Account." << endl;
        cout << "\t2. Add Cash" << endl;
        cout << "\t3. Withdraw" << endl;
        cout << "\t4. Exit" << endl;
        cout << "\tEnter Your Choice: " << endl;
        cin >> val;

        switch (val) {
            case 1: {
                string accountNo, password;
                cout << "Enter Account Number: ";
                cin >> accountNo;
                mynew.setAccountNo(accountNo);
                cout << "Enter Password: ";
                cin >> password;
                mynew.setPassword(password);
                cout << "Account Created Successfully!" << endl;
                break;
            }
            case 2: {
                int amount;
                cout << "Enter Amount to Add: ";
                cin >> amount;
                mynew.setBalance(mynew.getBalance() + amount);
                cout << "Amount Added Successfully!" << endl;
                break;
            }
            case 3: {
                int amount;
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;
                if (amount <= mynew.getBalance()) {
                    mynew.setBalance(mynew.getBalance() - amount);
                    cout << "Withdrawal Successful!" << endl;
                } else {
                    cout << "Insufficient Balance!" << endl;
                }
                break;
            }
            case 4:
                exit = true;
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid Choice! Please try again." << endl;
                break;
        }
        Sleep(3000);
    }
    return 0;
}