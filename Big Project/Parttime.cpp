//CECS282 Project-1
//Nhan Vo and Ian Lee
#include"Parttime.h"
#include<iostream>
using namespace std;
/*
* Parttime class implementation
*/
Parttime::Parttime():Staff() {// default constructor that call the default Staff constructor
	WorkedHour = 0;// default workedHour =0
}

Parttime::Parttime(string lName, string fName, string iD,// constructor with parameter, call the Staff parameter constructor
	string sex, string bDay, float rate, int wh): Staff(lName, 
		fName, iD, sex, bDay, rate){
	WorkedHour = wh;// set worked hour
}

void Parttime::setWorkedHour(int wh) {// worked hour setter method
	WorkedHour = wh;
}

int Parttime::getWorkedHour(){// worked hour getter method
	return WorkedHour;
}

void Parttime::putData() {// display method
	Employee::putData();// call Employee display method
	cout << "Hour worked per month: " << this->getWorkedHour()*weeks << endl;// display worked hour
	cout << "Monthly Salary: " << this->monthlyEarning() << endl;// display monthly salary
}

double Parttime::monthlyEarning() {// calculate monthly salary method
	return this->getRate() * WorkedHour * weeks;
}

void Parttime::getdata() {
	Staff::getdata();
	cout << "   Please enter Parttime worked hour(s):";
	cin >> WorkedHour;
}