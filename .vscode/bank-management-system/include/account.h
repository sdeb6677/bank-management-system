// filepath: bank-management-system/include/account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account
{
    private:
        string AccountNo;
        string Password;
        int Balance;

    public:
        Account();

        void setAccountNo(string id);
        void setPassword(string pw);
        void setBalance(int b);

        string getAccountNo() const;
        string getPassword() const;
        int getBalance() const;
};

#endif // ACCOUNT_H