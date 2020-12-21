/*
* Nhan Vo
* CECS 282-Lab 8
*/
#include<iostream>
#include "publication.h";
#include "Sales.h";
#include "Book.h";
using namespace std;
/*
* Book class implementation
*/
void Book::getData(){// get the information about the book
	Publication::getData();// call Publication getData() to prompt the user
	cout << "Please enter page count:" << endl;// prompt the user the page number
	cin >> pageCount;// store the user value in pageCount
	Sale::getData();// call Sale getData() to prompt the user
}

void Book::putData() {// display the book information
	Publication::putData();// call publication putData to display to Book data
	cout << "Page Count: " << pageCount << endl;// display the page count
	Sale::putData();// call Sale putData to display the Book's sale
}