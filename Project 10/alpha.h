//Nhan Vo
//CECS 282-Lab10
#pragma once
#ifndef ALPHA_H
#define ALPHA_H
#include <iostream>
using namespace std;
/*
* alpha class definition
*/
class alpha
{
private:
	int data;// data variable
public:
	alpha();// default constructor
	alpha(const alpha& a1);// copy constructor (deep copy)
	alpha(int n);// parameter constructor
	void display();// display function to output result

};
#endif // !ALPHA_H

