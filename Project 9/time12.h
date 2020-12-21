//Nhan Vo
//CECS 282 Lab#9
#pragma once
#ifndef TIME12_H
#define TIME12_H
#include<iostream>
using namespace std;
class time12
{
private:
	bool pm; //true = pm, false = am
	int hrs; //1 to 12
	int mins; //0 to 59
public: 
	time12();//no-arg constructor

	
	time12(bool ap, int h, int m);//3-arg constructor

	void display() const;// display time method
};
#endif // !TIME12_H
