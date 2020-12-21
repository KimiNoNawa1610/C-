//Nhan Vo
//CECS 282 Lab#9
#include<iostream>
#include"Distance.h"
using namespace std;
/*
* class Distance implementation
*/
Distance::Distance() : feet(0), inches(0.0) {}// default constructor implementation

Distance::Distance(int ft, float in) : feet(ft), inches(in)
{ }// parameter constructor implementation

Distance Distance::operator+(Distance const&a) const{// overloading "+" operator
	Distance b;// create a new Distance object
	b.feet = this->feet + a.feet;// set the attribute for that obejct based on the sum of the two objects
	b.inches = this->inches + a.inches;
	return  b;// return that object

}

Distance Distance::operator+(const double a) const {// overloading "+" operator with normal integer implementation
	Distance b;// create a new Distance object
	b.feet = this->feet + a;// add the feet with a integer
	b.inches = this->inches;// keep the old inches
	return b;// retunr Distance b
}

Distance Distance::operator-(Distance const& a) const {// overloading "-" operator
	Distance b;// create a new Distance object
	b.feet = this->feet - a.feet;// set the attribute for that obejct based on the sum of the two objects
	b.inches = this->inches - a.inches;
	return  b;// return that object

}

Distance Distance::operator-(const double a) const {// overloading "-" operator with normal integer implementation
	Distance b;// create a new Distance object
	b.feet = this->feet - a;// subtract the feet with a integer
	b.inches = this->inches;// keep the old inches
	return b;// retunr Distance b
}

bool operator==(const Distance& a, const Distance& b) {// overloading equal comparision
	return(a.feet == b.feet && a.inches == b.inches);// return true if feet and inches of a and b are equal, false otherwise
}

bool operator>(const Distance& a, const Distance& b) {// evaluation ">" operator
	if (a.feet < b.feet|| (a.feet==b.feet &&a.inches<b.inches)) {// compare the feet and inches value of two Distance object
		return false;// return false if the condition is not met
	}
	return true;// return true if the condition is met
}

bool operator<(const Distance& a, const Distance& b) {
	if (a.feet > b.feet || (a.feet == b.feet && a.inches > b.inches)) {// evaluation "<" operator
		return false;// Similar to the evaluation ">" operator except reverse the condition
	}
	return true;
}

Distance Distance::operator++(int) {// overloading "++" operator postfix
	int index = 1;
	Distance b;// create a Distance b object
	b.feet = this->feet+index;// increment the feet by 1 index
	b.inches = this->inches;// keep the old inches
	return b;// return Distance b
}

ostream& operator<<(ostream& a, const Distance& b) {// overloading ostream
	if (b.inches > 12) {// if the inches more than 12, convert to feet
		cout << (b.feet + (int)b.inches / b.convert) << " ft " << fmod(b.inches,b.convert) << " inches " << endl;// output the result
	}
	else {
		cout << b.feet << " ft " << b.inches << " inches " << endl;// output the result
	}
	return a;// return ostream object
}

istream& operator>>(istream& a, Distance& b) {// overloading istream
	cout << "Please enter the feet number" << endl;// prompt the feet attribute
	a >> b.feet;// store the feet value
	cout << "Please enter the inches number" << endl;// prompt the inches attribute
	a >> b.inches;// store the inches value
	return a;
}