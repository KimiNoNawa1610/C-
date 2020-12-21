//Nhan Vo
//CECS 282 Lab#9
#pragma once
#ifndef TIME24_H
#define TIME24_H
#include"time12.h"
class time24
{
private:
	int hours; //0 to 23
	int minutes; //0 to 59
	int seconds; //0 to 59
public: 
	time24();//no-arg constructor

	time24(int h, int m, int s);//3-arg constructor

	operator time12();// object-type overloading operator to convert time24 to time 12

	void display() const;// display time method

};
#endif // !TIME24_H
