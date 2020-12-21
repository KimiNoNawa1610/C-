//Nhan Vo
//CECS 282-Lab10
#include<iostream>
#include"alpha.h"
using namespace std;
/*
* alpha class implementation
*/
alpha::alpha():data(0){}// default constructor

alpha::alpha(const alpha& a1) {// copy constructor
	this->data = a1.data;// past the value of data to the new alpha object
}

alpha::alpha(int n) {// parameter constructor
	this->data = n;// set data
}

void alpha::display() {// display function
	cout << data << endl;// output data
}