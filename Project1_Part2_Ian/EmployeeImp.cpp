#include "Employee.h"
#include "Date.h"
#include "Faculty.h"
#include "Staff.h"
#include "Partime.h"
#include <string>

int Employee::n;
vector<Employee*> Employee::employees(MAXEM);

Employee::Employee(string lNmae, string fName, string id, Sex s, string dateStr) {
	firstName = fName;
	lastName = lNmae;
	idNumber = id;
	sex = s;
	birthDate = new Date(dateStr);
}

Employee::Employee(Employee* e) {
	firstName = e->firstName;
	lastName = e->lastName;
	idNumber = e->idNumber;
	sex = e->sex;
	birthDate = e->birthDate;
}

Employee::~Employee() {
	//cout << "Destructing Employee ... \n";
	delete birthDate;
}

void Employee::setLastName(string name) {
	lastName = name;
}

void Employee::setFirstName(string name) {
	firstName = name;
}

void Employee::setIdNumber(int id) {
	idNumber = id;
}

void Employee::setSex(Sex s) {
	sex = s;
}

void Employee::setBirthDate(Date* d) {
	birthDate = d;
}

string Employee::getLastName() {
	return lastName;
}

string Employee::getFirstName() {
	return firstName;
}

string Employee::getIdNumber() {
	return idNumber;
}

Sex Employee::getSex() {
	return sex;
}

Date* Employee::getBirthDate() {
	return birthDate;
}

string Employee::getBirthDateString() {
	string resStr = "";
	if (birthDate) resStr = birthDate->getDateString();
	return resStr;
}

void Employee::getData() {
	int idx;
	string name, dateStr;
	cin.ignore(10, '\n');
	cout << "ID Employee Number: ";
	getline(cin, idNumber);
	
	cout << "Employee Name: ";
	getline(cin, name);
	if ((idx = name.rfind(" ")) != string::npos) {
		lastName = name.substr(idx, name.length() - idx + 1);
		firstName = name.erase(idx, lastName.length());
	}
	else {
		firstName = "";
		lastName = name;
	}
	
	cout << "Birth date(mm/dd/yyyy): ";
	getline(cin, dateStr);
	birthDate = new Date(dateStr);
}

void Employee::putData() {
	cout << "ID Employee number: " << idNumber << endl;
	cout << "Employee name: " << firstName << " " << lastName << endl;
	cout << "Birth date: " << birthDate->getDateString() << endl;
}

void Employee::add() {
   char ch;
   cout << "'f' to add a Faculty"
           "\n's' to add a Staff"
           "\n'p' to add a Partime"
           "\nEnter selection: ";
   cin >> ch;
   switch(ch)
      {                       //create specified employee type
      case 'f': employees[n] = new Faculty;   break;
      case 's': employees[n] = new Staff; break;
      case 'p': employees[n] = new Partime;   break;
      default: cout << "\nUnknown employee type\n"; return;
      }
   employees[n++]->getData();     //get employee data from user
}

void Employee::display() {
	for(int j=0; j<n; j++)
	{
		cout  << (j+1);           //display number
      
		switch( employees[j]->get_type() )   //display type
		{
			case tFaculty: cout << ". Type: Faculty";   break;
			case tStaff:  cout << ". Type: Staff"; break;
			case tPartime:    cout << ". Type: Partime";   break;
			default: cout << ". Unknown type";
		}
		cout << endl;
		employees[j]->putData();    //display employee data
		cout << endl;
	}
}

Employee_type Employee::get_type() {
	if( typeid(*this) == typeid(Faculty) )
      return tFaculty;
   else if( typeid(*this)==typeid(Staff) )
      return tStaff;
   else if( typeid(*this)==typeid(Partime) )
      return tPartime;
   else
      { cerr << "\nBad employee type"; exit(1); }
}

void Employee::write() {
int size;
cout << "Writing " << n << " employees.\n";
ofstream ouf;              //open ofstream in binary
Employee_type etype;       //type of each employee object

ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
if(!ouf) { cout << "\nCan't open file\n"; return; }
for(int j=0; j<n; j++)     //for every employee object
{                       //get its type
   etype = employees[j]->get_type();
                              //write type to file
   ouf.write((char*)&etype, sizeof(etype));
   switch(etype)           //find its size
   {
      case tFaculty:   size=sizeof(Faculty); break;
      case tStaff: size=sizeof(Staff); break;
      case tPartime:   size=sizeof(Partime); break;
   }                    //write employee object to file
   ouf.write( (char*)(employees[j]), size );
   ouf.write((char*)(employees[j]->getBirthDate()), sizeof(Date));
   if (etype == tFaculty) {
		Education edu = ((Faculty *)employees[j])->getEducation();
		ouf.write((char *)&edu, sizeof(Education));
	 }
   if(!ouf)
      { cout << "\nCan't write to file\n"; return; }
   }
ouf.close();
}

void Employee::read()
   {
   int size;                  //size of employee object
   Employee* empPtr;
   Education* eduPtr;
   Employee_type etype;       //type of employee
   ifstream inf;              //open ifstream in binary
   inf.open("EMPLOY.DAT", ios::in | ios::binary);
   if(!inf)
      { cout << "\nCan't open file\n"; return; }
   n = 0;                     //no employees in memory yet
   while(true)
      {                       //read type of next employee
      inf.read( (char*)&etype, sizeof(etype) );
      if( inf.eof() )         //quit loop on eof
         break;
      if(!inf)                //error reading type
         { cout << "\nCan't read type from file\n"; return; }
      switch(etype)
         {                    //make new employee
         case tFaculty:       //of correct type
            empPtr = new Faculty;
            size=sizeof(Faculty);
            break;
         case tStaff:
			 empPtr = new Staff;
            size=sizeof(Staff);
            break;
         case tPartime:
            empPtr = new Partime;
            size=sizeof(Partime);
            break;
         default: cout << "\nUnknown type in file\n"; return;
         }                    //read data from file into it
      inf.read( (char*)empPtr, size  );
	  Date* tmpDate = new Date;
	  inf.read((char*)(tmpDate), sizeof(Date));
	  if (etype == tFaculty) {
		  eduPtr = new Education;
		  inf.read((char*)eduPtr, sizeof(Education));
		  Faculty* facu = new Faculty((Faculty *)empPtr);
		  facu->setEducation(*eduPtr);
		  employees[n] = facu;
	  }
	  else if (etype == tStaff) {
		  Staff* staff = new Staff((Staff*)empPtr);
		  employees[n] = staff;
	  }
	  else if (etype == tPartime) {
		  Partime* part = new Partime((Partime*)empPtr);
		  employees[n] = part;
	  }
	  employees[n]->setBirthDate(tmpDate);

	  Employee_type et = employees[n]->get_type();

      if(!inf)                //error but not eof
         { cout << "\nCan't read data from file\n"; return; }
      n++;                    //count employee
      }  //end while
   inf.close();
   cout << "Reading " << n << " employees\n";
   }
