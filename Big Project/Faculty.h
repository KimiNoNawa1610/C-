//CECS282 Project-1
//Nhan Vo and Ian Lee
#pragma once
#include<iostream>
#include"Employee.h"
#include"Education.h"
using namespace std;
#ifndef FACULTY_H
#define FACULTY_H
enum Level{AS,AO,FU};// enum Level type with AS, AO, FU

/*
* Faculty class definition that inherit Employee class
* 2 Attributes: level, education
*/
class Faculty :public Employee {
private:
	Level level;
	Education education;
	double Salary = 5000;
	float AOrate = 1.2;
	float FUrate = 1.4;

public:
	Faculty();// default constructor

	Faculty(string lName, string fName, string iD, string sex, string bDay, 
		string l,string d, string m, int r);// constructor with parameters

	void setLevel(string l);// level setter function definition

	string getLevel();// level getter function definition

	void getdata();// get data from the user

	void putData();// display method definition

	double monthlyEarning();// override monthlyEarning method from Employee class

	void setEducation(string d, string m, int r);// education setter function definition

};
#endif // !FACULTY_H
