/*
* Nhan Vo
* CECS 282-Lab 8
*/
#include "Sales.h"
#include<iostream>
using namespace std;
/*
* Sale class implementation
*/
//Define the function getData to input sales for three months
void Sale::getData() {// prompt the user information about a sales of a publication in 3 months
	cout << "Please input the sale of the last three months:" << endl;
	cout << "Please enter the sale of the 1st month:" << endl;
	cin >> saleArray[0];// store the first month's sale 
	cout << "Please enter the sale of the 2nd month:" << endl;
	cin >> saleArray[1];// store the second month's sale 
	cout << "Please enter the sale of the 3rd month:" << endl;
	cin >> saleArray[2];// store the third month's sale 
	cin.ignore();
}

//Define the function putData to display three months of sales
void Sale::putData() {// output the sale data in 3 months
	cout << "The sale of last three months:" << endl;
	cout << "----------------------------------" << endl;
	for (int i = 0; i < 3; i++) {// for loop to output the data from saleArray[]
		cout << "The sale of the " << i << " month is: " << saleArray[i] << endl;// output the data
	}
}