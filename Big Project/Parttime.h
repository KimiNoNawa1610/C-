//CECS282 Project-1
//Nhan Vo and Ian Lee
#pragma once
#include<iostream>
#include"Staff.h"
using namespace std;
#ifndef PARTTIME_H
#define PARTTIME_H
/*
* Parttime class defintion that inherit Staff class
* 1 attribute: WorkedHour
*/
class Parttime :public Staff {
private:
	int WorkedHour;
	int weeks = 4;

public:
	Parttime();// default constructor
	
	Parttime(string lName, string fName, string iD,// Constructor with parameters
		string sex, string bDay, float rate, int wh);

	void setWorkedHour(int wh);// WorkedHour setter function definition

	void getdata();

	int getWorkedHour();// WorkedHour getter function def

	void putData();// display method definition

	double monthlyEarning();// Override monthlyEarning function
};

#endif // !PARTTIME_H
