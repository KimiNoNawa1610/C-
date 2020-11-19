#include "Faculty.h"
#include <string>
#include <iomanip>

#define FACULTY_SALARY_RATIO_AS 1.0
#define FACULTY_SALARY_RATIO_AO 1.2
#define FACULTY_SALARY_RATIO_FU 1.4

Faculty::Faculty(string lNmae, string fName, string id, Sex s, string dateStr, Level l, string degreeStr, string major, int research)
	: Employee(lNmae, fName, id, s, dateStr) 
{
	level = l;
	eduObj = new Education(degreeStr, major, research);
}

Faculty::Faculty(Faculty* f) : Employee(f) {
	level = f->level;
	eduObj = f->eduObj;
}

Faculty::~Faculty() {
	//cout << "Destructing Faculty ... \n";
	delete eduObj;
}

void Faculty::setLevel(Level l) {
 level = l;
}

void Faculty::setEducation(Education e) {
	eduObj = &e;
}

Level Faculty::getLevel() {
	return level;
}

Education Faculty::getEducation() {
	return *eduObj;
}

void Faculty::getData() {
	Employee::getData();

	string lstr;
	cout << "Level: ";
	getline(cin, lstr);
	if (lstr == "AS") level = AS;
	else if (lstr == "AO") level = AO;
	else level = FU;

	string dStr, mStr;
	int rInt;
	cout << "Degree: ";
	getline(cin, dStr);
	cout << "Major: ";
	getline(cin, mStr);
	cout << "Research: ";
	cin >> rInt;

	eduObj = new Education(dStr, mStr, rInt);
}

double Faculty::monthlyEarning() {
	double r;
	if (level == AS) r = FACULTY_SALARY_RATIO_AS;
	else if (level == AO) r = FACULTY_SALARY_RATIO_AO;
	else r = FACULTY_SALARY_RATIO_FU;

	return r * (double) FACULTY_MONTHLY_SALARY;
}

void Faculty::putData() {
	Employee::putData();

	if (level == AS) cout << "Asistant";
	else if (level == AO) cout << "Associate";
	else cout << "Full";
	cout << " Professor" << endl;
	cout << "Monthyly Salary: $" << (int) monthlyEarning() << endl;
}
