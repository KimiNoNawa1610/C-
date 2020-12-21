//Nhan Vo
//CECS 282-Lab10
#include"pointerDataClass.h"
#include<iostream>
using namespace std;

/*
* pointerDataClass implementation
*/
pointerDataClass::pointerDataClass(int size) {// parameter constructor
	maxSize = size;// set size
	p = new int[size];// dynamically allocate pointer p
	length = 0;// length=0
	for (int i = 0; i < maxSize; i++) {
		p[i] = 0;// initiate pointer array
	}
}

//Deep copy
pointerDataClass::pointerDataClass(const pointerDataClass& p1) {// copy constructor
	this->length = p1.length;// copy length value
	this->maxSize = p1.maxSize;// copy maxSize value
	this->p = new int[maxSize];// dynamically initiate new array pointer
	for (int i = 0; i < this->maxSize; i++) {
		this->p[i] = p1.p[i];// copy value from the p1 object
	}
}

pointerDataClass::~pointerDataClass() {// destructor
	delete this->p;// delete p
}

void pointerDataClass::insertAt(int index, int num) {// insertAt function to insert into p pointer array
	for (int i = maxSize-1; i >=index; i--) {
		p[i]=p[i-1];// move the element after index to the right 1 digit
	}
	p[index] = num;// assign num to index element
	length++;// increment length
}

void pointerDataClass::displayData() {// displayData function
	for (int i = 0; i < maxSize; i++) {// for loop to display p array
		cout << p[i] << ", ";
	}
	cout << endl;
}