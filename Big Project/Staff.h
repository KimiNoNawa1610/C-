//CECS282 Project-1
//Nhan Vo and Ian Lee
#pragma once
#include<iostream>
#include"Employee.h"
using namespace std;
#ifndef STAFF_H
#define STAFF_H
/*
* Staff class definition
* 1 attribute: hourRate
*/
class Staff :public Employee {
private:
	float hourRate;
	int rateCount = 160;
public:
	Staff();// defalut constructor

	Staff(string lName, string fName, string iD, string sex, string bDay, float rate);// constructor with parameter

	void virtual putData();// virtual method to display information

	void setRate(float n);// hourRate setter function definition

	float getRate();// hourRate getter function definition

	void getdata();

	double monthlyEarning();// override monthlyEarning function

};

#endif // !STAFF_H
