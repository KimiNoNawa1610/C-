#include "Partime.h"

Partime::Partime(string lName, string fName, string id, Sex s, string dateStr, double hourlyRate, double hours)
	: Staff(lName, fName, id, s, dateStr, hourlyRate)
{
	workHours = hours;
}

Partime::Partime(Partime* p) : Staff(p) {
	workHours = p->workHours;
}

void Partime::setHours(double h) {
	workHours = h;
}

double Partime::getHours() {
	return workHours;
}

void Partime::getData() {
	Staff::getData();
	cout << "Hours worked per week: ";
	cin >> workHours;
}

double Partime::monthlyEarning() {
	return 4.0 * workHours * getHourlyRate();
}

void Partime::putData() {
	Employee::putData();

	cout << "Hours work per month: " << fixed << setprecision(0) << workHours << endl;
	cout << "Monthly Salary: " << fixed << setprecision(0) << monthlyEarning() << endl;
}
