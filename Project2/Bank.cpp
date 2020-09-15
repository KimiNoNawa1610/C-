/*
*Nhan Vo & Ian Lee
* Lab2- Problem 3
*/
#include"Account.h"
#include<iostream>
#include"Bank.h"
using namespace std;

// initialize the tempty bank accounts
Bank::Bank() {
	checking.deposit(0);// deposit amount is 0
	savings.deposit(0);// deposit amount is 0
}
// initialize bank accounts with certain amount of money
Bank::Bank(double checking_amount, double savings_amount) {
	checking.deposit(checking_amount);// deposit amount is checking_amount
	savings.deposit(savings_amount);// deposit amount is savings_amount
}
//Deposit into bank account(s)
void Bank::deposit(double amount, string account) {
	//Identify account type that users want to deposit
	if (account == "S") {// deposit to savings account
		savings.deposit(amount);
	}
	else if (account == "C") {// deposit to checking account
		checking.deposit(amount);
	}
}
//Withdraw from bank account(s)
/*Widthdraw function implement the withdraw function from Account class. 
* If the account does not have more than the amount users want to withdraw, minus $5 from Account balance
*/
void Bank::withdraw(double amount, string account) {
	//Identify account type that users want to withdraw
	if (account == "S") {// withdraw from savings account
		savings.withdraw(amount);
	}
	else if (account == "C") {//withdraw from checking account
		checking.withdraw(amount);
	}
}
//Transfer from one account to another
void Bank::transfer(double amount, string account) {
	//Identify account type that users want to transfer from
	if (account == "S") {//Transfer from savings account
		savings.withdraw(amount);
		if (amount < savings.get_balance()) {// If the amount is no more than account balance then deposit
			checking.deposit(amount);
		}
	}
	else if (account == "C") {//Transfer from checking account
		checking.withdraw(amount);
		if (amount < checking.get_balance()) {// If the amount is no more than account balance then deposit
			savings.deposit(amount);
		}
	}
}
// Print out the accounts' balance
void Bank::print_balances() {
	cout << "Your Checking Balance: $" << checking.get_balance()<<endl;// output checking account balance
	cout << "Your Savings Balance: $" << savings.get_balance() << endl;// output savings account balance
}
