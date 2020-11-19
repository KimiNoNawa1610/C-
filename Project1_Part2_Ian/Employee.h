#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Date.h"
#include <iomanip>
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

const int LEN = 32;
const int MAXEM = 100;

#define FACULTY_MONTHLY_SALARY 5000.00;
#define STAFF_MONTHLY_HOURS_WORKED 160.;

enum Employee_type {
	tFaculty, tStaff, tPartime
};

enum Sex {
	M,
	F
};

class Employee {
	private:
		string lastName;
		string firstName;
		string idNumber;
		Sex sex;
		Date* birthDate;
		static int n;
		static vector<Employee*> employees;


	public:
		Employee(string lNmae = "", string fName = "", string id = "", Sex s = M, string dateStr = "");
		Employee(Employee* e);
		virtual ~Employee();
		void setLastName(string name);
		void setFirstName(string name);
		void setIdNumber(int id);
		void setSex(Sex s);
		void setBirthDate(Date* d);
		string getLastName();
		string getFirstName();
		string getIdNumber();
		Sex getSex();
		Date* getBirthDate();
		string getBirthDateString();
		virtual void getData();
		virtual double monthlyEarning() = 0;
		virtual void putData();
		static void add();
		static void display();
		static void write();
		static void read();
		virtual Employee_type get_type();
};

#endif