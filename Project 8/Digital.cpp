/*
* Nhan Vo
* CECS 282-Lab 8
*/
#include "Digital.h"
#include <iostream>
/*
* Digital class implementation
*/
void Digital::getData() {// prompt the user about the Digital information
	Publication::getData();// call Publication getData() to prompt the user
	cout << "Please enter your storage:" << endl;// prompt the size of the Digital
	cin >> data;// store the size in data 
	Sale::getData();// call Sale getData() to prompt the user
}

void Digital::putData() {// Display teh Digital values
	Publication::putData();// call Publication putData() to display information of the Digital
	cout << "Storage: " << data << " MB" << endl;// Display the digital file's size
	Sale::putData();// call Sale putdata() to display Digital's sale
}