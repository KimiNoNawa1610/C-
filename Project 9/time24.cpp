//Nhan Vo
//CECS 282 Lab#9
#include<iostream>
#include"time24.h"
#include"time12.h"
using namespace std;

time24::time24() : hours(0), minutes(0), seconds(0)// default constructor
{ }

time24::time24(int h, int m, int s) : //3-arg constructor
	hours(h), minutes(m), seconds(s)
{ }

 time24::operator time12() {// time24 to time12 convertor implementation
	int convert = 12;
	int max = 24;
	int nh= this->hours;
	bool pm;
	pm= this->hours==12?true:false;// if the hour is more than 12, set pm to true
	if (convert<this->hours) {// if hours is greater than 12, convert to time12 hours
		nh = this->hours % convert;// take the remainder after divide by the convertor variable
		pm = true;// set pm =true
	}
	return time12(pm,nh, this->minutes);// reutrn a time 12 object
}

void time24::display() const //format: 23:15:01
{
	if (hours < 10) cout << '0';// display hours minutes and seconds.
	cout << hours << ':';
	if (minutes < 10) cout << '0';
	cout << minutes << ':';
	if (seconds < 10) cout << '0';
	cout << seconds;
}