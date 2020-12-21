/*
* Nhan Vo
* CECS 282-Lab 8
*/
#pragma once
#ifndef BOOK_H
#define BOOK_H
#include "publication.h"
#include "Sales.h"
/*
* Class Book definition
*/
class Book:public Publication, Sale {// Inherit Publication and Sale classes
public:
	void getData();// get input from the user
	void putData();// output the data of the Book object
private:
	int pageCount;// number of page count of a book
};
#endif // 
