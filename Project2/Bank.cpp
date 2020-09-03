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
	void print_balance();
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

void Bank::print_balance() {
	cout << "Your Checking Balance: $" << checking.get_balance()<<endl;
	cout << "Your Savings Balance: $" << savings.get_balance() << endl;
}

int main() {
	Bank my_bank;
	my_bank.print_balance();
	return 0;
}