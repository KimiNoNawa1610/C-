/*
*Nhan Vo & Ian Lee
*/
#pragma once
#ifndef BANK_H
#define BANK_H
#include<iostream>
#include"Account.h"
using namespace std;
/*
* Class Bank:
* Has two objects, checking and savings of type Account
*/
class Bank {
private:
	Account checking;
	Account savings;
public:
	/*Create function holder of class bank*/
	Bank();// initialize the tempty bank accounts
	Bank(double checking_amount, double savings_amount);// initialize bank accounts with certain amount of money
	void deposit(double amount, string account);//Deposit into bank account(s)
	void withdraw(double amount, string account);//Withdraw from bank account(s)
	void transfer(double amount, string account);//Transfer from one account to another
	void print_balances();// Print out the accounts' balance
};
#endif // !BANK_H

