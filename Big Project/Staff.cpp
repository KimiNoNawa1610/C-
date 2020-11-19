//CECS282 Project-1
//Nhan Vo and Ian Lee
#include<iostream>
#include"Staff.h"
using namespace std;
/*
* Staff class implementation
*/
Staff::Staff(): Employee(){// default constructor that calls that Employee default constructor
	hourRate = 0;// default hourRate=0
}

Staff::Staff(string lName, string fName, string iD,// constructor with parameter
	string sex, string bDay, float rate): Employee(lName, fName, iD,// call Employee constructor with parameter
		 sex, bDay){
	hourRate = rate;// set hour rate
}

void Staff::putData() {// display method implementation
	Employee::putData();// call Employee display method
	cout << "Full Time" << endl;// output full time statement
	cout << "Monthly Salary: " << this->monthlyEarning()<< endl;// output monthly salary
}

void Staff::setRate(float n) {// hour rate setter function
	hourRate = n;
}

float Staff::getRate() {// hour rate getter function
	return hourRate;
}

double Staff::monthlyEarning() {// override monthly earning function
	return hourRate * rateCount;
}

void Staff::getdata() {
	Employee::getdata();
	cout << "   Please enter staff hour-rate:";
	cin >> hourRate;
}