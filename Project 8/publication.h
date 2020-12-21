/*
* Nhan Vo
* CECS 282-Lab 8
*/
#pragma once
#ifndef PUBLICATION_PUBLICATION_H
#define PUBLICATION_PUBLICATION_H
#include <iostream>
using namespace std;
/*
* Publication class definition
*/

class Publication {

public:
	//Declare two functions getData and putData
	void getData();// prompt the user
	void putData();// output the publication data



	//Declare title and price
private:
	string title;// has a string title of a publication
	double price;// price variable of a publication


};

#endif //PUBLICATION_PUBLICATION_H