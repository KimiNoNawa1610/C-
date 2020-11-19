//CECS282 Project-1
//Nhan Vo and Ian Lee
#include<iostream>
#include<iomanip>
#include"Faculty.h"
using namespace std;
/*
* Faculty class implementation
*/
Faculty::Faculty():Employee() {// default constructor
	education=Education::Education();// call Education default constructor
	level = AS;// default level is Assistant(AS)
}

Faculty::Faculty(string lName, string fName,// constructor with parameter
	string iD, string sex, string bDay, string l, 
	string d, string m, int r) : Employee(lName,// call Employe parameter constructor
		fName, iD, sex, bDay) {
	setLevel(l);// setlevel function to set the level
	education = Education::Education(d, m, r);// construct a new education object

}

void Faculty::setLevel(string l) {// level setter function implementation
	if (l == "AS"|| l=="Assistant") {// condition to set level according to the string input
		level = AS;
	}
	else if (l == "AO"||l=="Associate") {
		level = AO;
	}
	else {
		level = FU;
	}

}

void Faculty::putData() {// display method
	Employee::putData();// call employee display method
	cout <<  this->getLevel()<< " Professor " << endl;// display the level
	cout << "Monthly Salary: " << this->monthlyEarning() << endl;// display monthly salary
}

string Faculty::getLevel(){// level getter function
	string n;
		if (level == AS) {// return string value of level according to the enum level type
			n = "Assistant";
		}
		else if (level == AO) {
			n = "Associate";
		}
		else {
			n = "Full";
		}
		return n;
}

double Faculty::monthlyEarning() {// monthlyEarning function to display the Employee monthly salary
	double n;
	if (level == AS) {// depend on the level, the monthly salary will vary 
		n = Salary;
	}
	else if (level == AO) {
		n = AOrate * Salary;
	}
	else {
		n = FUrate * Salary;
	}
	return n;
}

void Faculty::setEducation(string d, string m, int r) {// set education function implementation
	education.setDegree(d);
	education.setMajor(m);
	education.setResearch(r);
}

void Faculty::getdata() {
	string l;
	string d;
	string m;
	int r;
	Employee::getdata();
	cout << "   Please enter faculty's level (AS or AO or FU only):";
	cin >> l;
	this->setLevel(l);
	cout << "   Please enter faculty's degree (MS or PhD only):";
	cin >> d;
	cout << "   Please enter the faculty's major:";
	cin >> m;
	cout << "   Please enter the faculty's number or rearch:";
	cin >> r;
	this->setEducation(d, m, r);

}