/*
* Nhan Vo
* CECS 282-Lab 8
*/
#pragma once
#ifndef PUBLICATION_DIGITAL_H
#define PUBLICATION_DIGITAL_H
#include "Publication.h"
#include "Sales.h"
/*
* Class Digital definition
*/
//Class Digital is created from classes Publication and Sales
class Digital :public Publication, Sale {// inherit Publication and Sale class
public:
	void getData();// prompt data from the user
	void putData();// output the data
private:
	double data;// size of a Digital object
};

//In this class you need to declare two functions getData and putData and a data member for storage



#endif //PUBLICATION_DIGITAL_H