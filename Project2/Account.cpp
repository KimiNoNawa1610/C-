#include <iostream>
using namespace std;
#include "Account.h"


Account::Account() {
    balance = 0;
}

Account::Account(int balance) {
    this->balance = balance;
}

int Account::deposit(int amount) {
    balance += amount;
    return 0;
}

int Account::withdraw(int amount) {
    if (amount <= balance) {
        balance -= amount;
        return 0;
    }

    else if ((amount > balance) && (balance > 5)) {
        balance -= 5;
        return 0;
    }

    return 0;
}

float Account::get_balance() {
    return balance;
}

int Account::add_interest(float rate) {
    balance *= (1 + rate / 100);
    return 0;
}

