/*
*Nhan Vo & Ian Lee
*/
#include"Bank.h"
#include"Account.h"
#include<iostream>
using namespace std;
/*
* Driver:
* Create a Account and test every function of class Account
* Create a Bank account and test every functions of class Bank
*/
int main() {
	/*Problem 1 tester- Account class functions*/
	cout << "----Problem 1 Tester----" << endl;
	Account my_account(100);
	my_account.deposit(50);// test deopsit
	my_account.withdraw(175);// test withdraw error
	my_account.withdraw(25);// test withdraw 

	cout << "Account balance:" << my_account.get_balance() << "\n";

	my_account.withdraw(my_account.get_balance());// withdraw all from account
	cout << "Account balance:" << my_account.get_balance() << "\n";
	cout << endl;
	/*Problem 2 tester- Determine the number of months to double the initial investment. 
	Create a menu to allow the user to enter the initial investment and the annual interest rate.*/
	cout << "----Problem 2 Tester----" << endl;
	double init_amount;// holder for user input
	float rate;// initialize rate amount
	double months = 1;// initialize the first month
	cout << "Enter initial amount of your account:";// prompt the user deposit amount
	cin >> init_amount;// store user input
	cout << "Enter your interest rate:";// prompt the user interest rate
	cin >> rate;//store interest rate
	my_account.deposit(init_amount);//deposit the money into my_account
	double final_amount = init_amount * 2;// calculate the double amount
	while (my_account.get_balance() < final_amount) {// calculate month with while loop
		my_account.add_interest(rate / 12);
		months++;
	}

	cout << "It took " << months << " for $" << init_amount << " to double at " << rate << "% annual interest." << "\n";// output result
	cout << "Account balance: $" << my_account.get_balance() << "\n";
	cout << endl;
	/*Problem 3 tester- Bank class function*/
	cout << "----Problem 3 Tester----" << endl;
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