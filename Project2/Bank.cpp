/*
*Nhan Vo & Ian Lee
* Lab2- Problem 3
*/
#include"Account.h"
#include<iostream>
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
/*
* Driver:
* Create a Bank account and test every functions of class Bank
*/
int main() {
	Bank my_bank;
	cout << "Inital bank balances: \n";
	my_bank.print_balances(); /* set up empty accounts */

	cout << "Adding some money to accounts: \n";
	my_bank.deposit(1000, "S"); /* deposit $1000 to savings */
	my_bank.deposit(2000, "C"); /* deposit $2000 to checking */
	my_bank.print_balances();

	cout << "Taking out $1500 from checking,and moving $200 from";
	cout << " savings to checking.\n";
	my_bank.withdraw(1500, "C"); /* withdraw $1500 from checking */
	my_bank.transfer(200, "S"); /* transfer $200 from savings */
	my_bank.print_balances();

	cout << "Trying to transfer $900 from Checking.\n";
	my_bank.transfer(900, "C");//Should - 5 from acocunt and not transfer
	my_bank.print_balances();

	cout << "trying to transfer $900 from Savings.\n";
	my_bank.transfer(900, "S");//Should - 5 from acocunt and not transfer
	my_bank.print_balances();
	return 0;
}