#include<iostream>
#pragma warning (disable:4786)
#include<set>
#include <string>
using namespace std;
class person
{
private:
	string lastName;
	string firstName;
	long phoneNumber;
public: // default constructor
	person() : lastName("blank"),
		firstName("blank"), phoneNumber(0)
	{ }
	// 3-arg constructor
	person(string lana, string fina, long pho) :
		lastName(lana), firstName(fina), phoneNumber(pho)
	{ }
	friend bool operator<(const person&, const person&);
	friend bool operator==(const person&, const person&);
	void display() const // display person's data
	{
		cout << endl << lastName << ",\t" << firstName
			<< "\t\tPhone: " << phoneNumber;
	}
};
// operator < for person class
bool operator<(const person& p1, const person& p2)
{
	if (p1.lastName == p2.lastName)
		return (p1.firstName < p2.firstName) ? true : false;
	return (p1.lastName < p2.lastName) ? true : false;
}
// operator == for person class
bool operator==(const person& p1, const person& p2)
{
	return (p1.lastName == p2.lastName &&
		p1.firstName == p2.firstName) ? true : false;
}
// comparePersons function object
class comparePersons
{
public:
	bool operator() (const person* ptrP1,
		const person* ptrP2) const
	{
		return *ptrP1 < *ptrP2;
	}
};

// displayPerson function object
class displayPerson
{
public:
	void operator() (const person* ptrP) const
	{
		ptrP->display();
	}
};


//driver
//Test the searching function and multiset Person
int main() {

	multiset<person*, comparePersons> personSet;// create multiset Person
	
	multiset<person*, comparePersons>::iterator iter;// create iterator Person 

	person* ptrP1 = new person("KuangThu", "Bruce", 4157300);
	personSet.insert(ptrP1);

	person* ptrP2 = new person("Deauville", "William", 8435150);
	personSet.insert(ptrP2);

	person* ptrP3 = new person("Wellington", "John", 9207404);
	personSet.insert(ptrP3);

	person* ptrP4 = new person("Bartoski", "Peter", 6946473);
	personSet.insert(ptrP4);

	person* ptrP5 = new person("Fredericks", "Roger", 7049982);
	personSet.insert(ptrP5);

	person* ptrP6 = new person("McDonald", "Stacey", 7764987);
	personSet.insert(ptrP6);

	person* ptrP7 = new person("KuangThu", "Bruce", 5551230);
	personSet.insert(ptrP7);

	person* ptrP8 = new person("Deauville", "William", 8435150);
	personSet.insert(ptrP8);

	for (iter= personSet.begin(); iter != personSet.end(); iter++) {
		(*iter)->display();
		cout <<endl;
		cout <<"____________________________________________________________"<< endl;
	}
	char in;
	do {
		string searchLastName;
		string searchFirstName;
		cout << "Please enter the first name of a person you want to search: ";
		cin >> searchFirstName;
		cout<< "Please enter the last name of a person you want to search: ";
		cin >> searchLastName;
		person searchPerson(searchLastName, searchFirstName, 0);
		person* sPerson = &searchPerson;
		cin.ignore();
		iter=personSet.find(sPerson);
		if (iter != personSet.end()) {
			(*iter)->display();
			cout << endl;
			int cntPersons = personSet.count(sPerson);
			cout << "Number of the person appearance: " << cntPersons << endl;
		}
		else {
			cout << "Cannot find the person, please try again" << endl;
		}
		cout << "Do you wan to continue (y/n)?";// prompt the user to redo the program if they want
		cout << endl;
		cin >> in;
		cout << endl;
	} while (in!='n');

	return 0;
}