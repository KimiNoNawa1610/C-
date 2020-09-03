/*
*Nhan Vo & Ian Lee
* Lab2- Problem 3
*/
#include"Account.h"
#include<iostream>
using namespace std;

class Bank {
private:
	Account checking;
	Account savings;
public:
	Bank();
	void deposit(double amount, string account);
	void withdraw(double amount, string account);
	void transfer(double amount, string account);
	void print_balances();
};

Bank::Bank() {
	checking.get_balance();
	savings.get_balance();

}

void Bank::deposit(double amount, string account) {
	if (account == "S") {
		savings.deposit(amount);
	}
	else if (account == "C") {
		checking.deposit(amount);
	}
}

void Bank::withdraw(double amount, string account) {
	if (account == "S") {
		savings.withdraw(amount);
	}
	else if (account == "C") {
		checking.withdraw(amount);
	}
}

void Bank::transfer(double amount, string account) {
	if (account == "S") {
		savings.withdraw(amount);
		if (amount < savings.get_balance()) {
			checking.deposit(amount);
		}
	}
	else if (account == "C") {
		checking.withdraw(amount);
		if (amount < checking.get_balance()) {
			savings.deposit(amount);
		}
	}
}

void Bank::print_balances() {
	cout << "Your Checking Balance: $" << checking.get_balance()<<endl;
	cout << "Your Savings Balance: $" << savings.get_balance() << endl;
}

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
	my_bank.transfer(900, "C");
	my_bank.print_balances();

	cout << "trying to transfer $900 from Savings.\n";
	my_bank.transfer(900, "S");
	my_bank.print_balances();
	return 0;
}