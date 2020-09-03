#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
//Header of class Account
/*
* Class Account:
* Has balance object
* and Function to interact with balance
*/
class Account {
private:
    double balance;// balance object

public:
    Account();// constructor

    Account(double balance);//constructor with balance value

    void deposit(double amount);// deposit into balance

    void withdraw(double amount);// withdraw from balance

    double get_balance();// get the balance amount

    void add_interest(float rate);// Add interest rate to balance

};
#endif // !ACCOUNT_H

