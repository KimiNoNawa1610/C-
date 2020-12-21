//Nhan Vo
//CECS 282-Lab10
#include<iostream>
#include"gamma.h"
using namespace std;
/*
* gamma class implementation
*/
int gamma::total = 0;// initiate total

gamma::gamma() {// default constructor
	total++;// increment total
	id = total;// set id=total
}

gamma::~gamma() {// destructor
	cout << "Destroying ID number " << id << endl;// output the destructed object
	total=total-1;// decrement total
}

void gamma::showtotal() {// showtotal function
	cout << "Total is " << total << endl;// display total
	cout << endl;
}

void gamma::showid() {// showid function
	cout << "ID number is " << id << endl;// display id
}