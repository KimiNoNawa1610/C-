/*
* Nhan Vo
* CECS 282-Lab 8
*/
#include<iostream>
#include<string>
#include"publication.h";
using namespace std;
/*
* Publication class implementation
*/
void Publication::getData() {// prompt the user the information of a Publication
	cout << "Please enter the title of the publication" << endl;// prompt the publication's title
	getline(cin, title);// get the entire line and store it int title variable
	cout << "Please enter the price of the publication in $" << endl;// prompt the publication's price
	cin >> price;// store the price value in price
}

void Publication::putData() {// display the data of Publication object
	cout << "The book " << title << " has a price of $" << price << endl;// display Publication Data
}