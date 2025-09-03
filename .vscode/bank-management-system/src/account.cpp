#include "account.h"

void Account::setAccountNo(string id) {
    AccountNo = id;
}

void Account::setPassword(string pw) {
    Password = pw;
}

void Account::setBalance(int b) {
    Balance = b;
}

string Account::getAccountNo() {
    return AccountNo;
}

string Account::getPassword() {
    return Password;
}

int Account::getBalance() {
    return Balance;
}