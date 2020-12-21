//Nhan Vo
//CECS 282 Lab#9
#pragma once
#ifndef DISTANCE_H
#define DISTANCE_H
#include<iostream>
using namespace std;
/*
* class Distance definition  
* 2 attribute: feet, inches
*/
class Distance //English Distance class
{
private:
	int feet;
	float inches;
	int convert = 12;// the coefficient to convert feet to inches and vice versa
public: 
	Distance(); //constructor (no args)
	Distance(int ft, float in);//constructor (two args)

	Distance operator+(const Distance& a) const;// overloading "+" operator

	Distance operator+(const double a) const;// overloading "+" operator with normal integer

	Distance operator-(const Distance& a) const;// overloading "-" operator

	Distance operator-(const double a) const;// overloading "-" operator

	Distance operator++(int);// overloading "++" operator postfix

	friend bool operator==(const Distance& a, const Distance& b);// overloading equal comparision

	friend bool operator>(const Distance& a, const Distance& b);// evaluation ">" operator

	friend bool operator<(const Distance& a, const Distance& b);// evaluation "<" operator

	friend ostream& operator<<(ostream& a, const Distance& b);// overloading ostream

	friend istream& operator>>(istream& a, Distance& b);// overloading istream

};
#endif // !DISTANCE_H

