/*
*Nhan Vo & Ian Lee
* Lab2- Problem 3
*/
#include <iostream>
using namespace std;
#include "Account.h"

//Construct an empty account
Account::Account() {
    balance = 0;
}
//Construct a account with balance
Account::Account(double balance) {
    this->balance = balance;
}
//Deposit into the account
void Account::deposit(double amount) {
    balance += amount;
}
//Withdraw from account
void Account::withdraw(double amount) {
    // if the account has enough money to perform withdraw
    //then withdraw amount
    if (amount <= balance) {
        balance -= amount;
    }
    //else -5 from that account
    else if ((amount > balance) && (balance > 5)) {
        balance -= 5;
    }
}
// return balance value
double Account::get_balance() {
    return balance;
}
// Add interest to balance
void Account::add_interest(float rate) {
    balance *= (1 + rate / 100);
}

