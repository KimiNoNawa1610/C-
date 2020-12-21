//CECS282 Project-1
//Nhan Vo and Ian Lee
#include"Employee.h"
#include"Staff.h"
#include <fstream> 
#include"Parttime.h"
#include"Faculty.h"
#include<iostream>
using namespace std;
/*
* Employee class implementation
*/

int Employee::n = 0;
const int MAXEM = 100;
vector<Employee*> Employee::employees(MAXEM);
Employee::Employee() {// default constructor
	lName = "None";// default last name is none
	fName = "None";// default first name is none
	iD = "None";// default iD is none
	sex = M;// default sex is M (because Me and my partner are both male (o.o))
	bDay = "None";// default bDay is none
}

Employee::Employee(string lName, string fName, string iD, string sex, string bDay) {// constructor with parameters
	this->lName = lName;// set last name
	this->fName = fName;//set first name
	this->iD = iD;// set iD
	(sex =="Male") ? this->sex = M : F;// depend on the information, set sex
	this->bDay = bDay;// set bDay
}

void Employee::putData() {// display function implementation
	cout << "Employee ID number: " << iD << endl;// display Employee iD
	cout << "Employee name: " << fName << " " << lName<<endl;// display Employee full name
	cout << "Birthdate: " << bDay << endl;// display Employee bDay
}

string Employee::getLname() {// last name getter function implementation
	return lName;// return last name
}

string Employee::getFname() {// first name getter function implementation
	return fName;// return first name
}

string Employee::getiD() {// iD getter function implementation
	return iD;// return iD
}

string Employee::getSex() {// sex getter function implementation
	if (sex == M) {// condition to return string type depends on sex
		return "M";
	}
	else if (sex == F) {
		return "F";
	}
}

string Employee::getBday() {// bDay getter function implementation
	return bDay;// return bDay
}

void Employee::setLname(string lname) {// last name setter function implementation
	lName = lname;
}

void Employee::setFname(string fname) {// first name setter function implementation
	fName = fname;
}

void Employee::setiD(string id) {// iD setter function implementation
	iD = id;
}

void Employee::setBday(string Bday) {// bDay setter function implementation
	bDay = Bday;
}

void Employee::setSex(string s) {// sex setter function implementation
	if (s == "Male"||s=="M") {
		sex = M;
	}
	else if (s == "Female" || s == "F") {
		sex = F;
	}
}

void Employee::getdata() {
	cin.ignore(10, '\n');
	string s;
	cout << "   Please enter first name: ";
	cin >> fName;
	cout << "   Please enter last name: "; 
	cin >> lName;
	cout << "   Please enter id number: "; 
	cin >> iD;
	cout << "   Please enter employee's gender (M or F only): ";
	cin >> s;
	this->setSex(s);
	cout << "   Please enter employee's Birthday: ";
	cin >> bDay;
}

employee_type Employee::get_type() {
	if (typeid(*this) == typeid(Staff))
		return staff;
	else if (typeid(*this) == typeid(Faculty))
		return faculty;
	else if (typeid(*this) == typeid(Parttime))
		return parttime;
	else
	{
		cerr << "\nBad employee type"; 
		exit(1);
	}
}

void Employee::setVector(vector<Employee*> const& emp){
	for (int i = 0; i < emp.size();i++) {
		employees[n++] = emp[i];
	}
	
}

void Employee::add() {
	char ch;
	cout << "'f' to add a faculty"
		"\n's' to add a staff"
		"\n'p' to add a parttime"
		"\nEnter selection: ";
	cin >> ch;
	switch (ch)
	{                       //create specified employee type
	case 'f': 
		employees[n] = new Faculty;   
		break;
	case 's': 
		employees[n] = new Staff; 
		break;
	case 'p': 
		employees[n] = new Parttime;   
		break;
	default: cout << "\nUnknown employee type\n"; return;
	}
	employees[n++]->getdata();     //get employee data from user
}

void Employee::display() {
	for (int j = 0; j < n; j++)
	{
		cout << (j + 1);           //display number
		switch (employees[j]->get_type())   //display type
		{
		case staff:    
			cout << ". Type: Staff" << endl;
			break;
		case faculty:  
			cout << ". Type: Faculty" << endl;
			break;
		case parttime:    
			cout << ". Type: Parttime" << endl;
			break;
		default: 
			cout << ". Unknown type" << endl;
		}
		employees[j]->putData();    //display employee data
		cout << endl;
	}
}

void Employee::read()
{
	int size;                  //size of employee object
	employee_type etype;       //type of employee
	ifstream inf;              //open ifstream in binary
	inf.open("EMPLOY.DAT", ios::binary);
	if (!inf)
	{
		cout << "\nCan't open file\n"; return;
	}
	n = 0;                     //no employees in memory yet
	while (true)
	{                       //read type of next employee
		inf.read((char*)&etype, sizeof(etype));
		if (inf.eof())         //quit loop on eof
			break;
		if (!inf)                //error reading type
		{
			cout << "\nCan't read type from file\n"; return;
		}
		switch (etype)
		{                    //make new employee
		case staff:       //of correct type
			employees[n] = new Staff;
			size = sizeof(Staff);
			break;
		case parttime:
			employees[n] = new Parttime;
			size = sizeof(Parttime);
			break;
		case faculty:
			employees[n] = new Faculty;
			size = sizeof(Faculty);
			break;
		default: cout << "\nUnknown type in file\n"; return;
		}                    //read data from file into it
		inf.read((char*)employees[n], size);
		if (!inf)                //error but not eof
		{
			cout << "\nCan't read data from file\n"; return;
		}
		n++;                    //count employee
	}  //end while
	cout << "Reading " << n << " employees\n";
}

void Employee::write() {
	int size;
	cout << "Writing " << n << " employees.\n";
	ofstream ouf;              //open ofstream in binary
	employee_type etype;       //type of each employee object

	ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		cout << "\nCan't open file\n"; return;
	}
	for (int j = 0; j < n; j++)     //for every employee object
	{                       //get its type
		etype = employees[j]->get_type();
		//write type to file
		ouf.write((char*)&etype, sizeof(etype));
		switch (etype)           //find its size
		{
		case staff:
			size = sizeof(Staff); 
			break;
		case parttime: 
			size = sizeof(Parttime); 
			break;
		case faculty:   
			size = sizeof(Faculty); 
			break;
		}                    //write employee object to file
		ouf.write((char*)(employees[j]), size);
		if (!ouf)
		{
			cout << "\nCan't write to file\n"; return;
		}
	}
}




