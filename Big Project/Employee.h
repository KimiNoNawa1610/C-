//CECS282 Project-1
//Nhan Vo and Ian Lee
#pragma once
#include<iostream>
#include<vector>
using namespace std;
enum Sex { M, F };// enum Sex definition with M and F
enum employee_type { staff, faculty, parttime };
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
/*
* Employee class definition
* 5 attributes: lName, fName, iD, sex, bDay represents the information of the employee
*/
class Employee {
private:
	string lName;
	string fName;
	string iD;
	Sex sex;
	string bDay;
	static vector<Employee*> employees;  //array of ptrs to emps
	static int n;
public:
	Employee();// default constructor

	Employee(string lName, string fName, string iD, string sex, string bDay);// constructor with parameters

	void virtual putData();// virtual method to output the Employee information

	virtual void getdata();// get the data for the new Employee from the user

	string getLname();// lName getter function definition

	string getFname();// fName getter function defintion

	string getiD();// iD getter function definition

	string getSex();// sex getter function definition

	string getBday();// bDay getter function definition

	void setLname(string lname);// lName setter function definition

	void setFname(string fname);// fName setter function definition

	void setiD(string iD);// iD setter function definition

	void setBday(string Bday);// bDay setter function definition

	void setSex(string s);// sex setter function definition

	virtual employee_type get_type();  //get type

	static void add();      //add an employee

	static void display();  //display all employees

	virtual double monthlyEarning() = 0;// virtual monthlyEarning function definition to calculate the monthly earning of an Employee

	static void read();     //read from disk file

	static void write();    //write to disk file

};

#endif // !EMPLOYEE_H

