//Nhan Vo
//CECS 282 Lab#9
#include<iostream>
#include"Time12.h"
using namespace std;

time12::time12() : pm(true), hrs(0), mins(0)// default constructor
{ }

time12::time12(bool ap, int h, int m) : pm(ap), hrs(h), mins(m)//3-arg constructor implementation
{ }

void time12::display() const //format: 11:59 p.m.
{
	cout << hrs << ':';
	if (mins < 10)
		cout << '0'; //extra zero for "01"
	cout << mins << ' ';
	string am_pm = pm ? "p.m." : "a.m.";// set the pm value
	cout << am_pm;
}