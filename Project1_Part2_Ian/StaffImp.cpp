#include "Staff.h"

Staff::Staff(string lNmae, string fName, string id, Sex s, string dateStr, double hr)
	: Employee(lNmae, fName, id, s, dateStr) {
	hourlyRate = hr;
}

Staff::Staff(Staff* s) : Employee(s) {
	hourlyRate = s->hourlyRate;
}

void Staff::setHourlyRate(double r) {
	hourlyRate = r;
}
double Staff::getHourlyRate() {
	return hourlyRate;
}

void Staff::getData() {
	Employee::getData();

	cout << "Hourly Rate: $ ";
	cin >> hourlyRate;	
}

double Staff::monthlyEarning() {
	return hourlyRate * (double) STAFF_MONTHLY_HOURS_WORKED ;
}

void Staff::putData() {
	Employee::putData();

	cout << "Full Time" << endl;
	cout << "Monthly Salary: $" << (int) monthlyEarning() << endl;
}
