/*
* Nhan Vo
* CECS 282-Lab 8
*/
#include "Sales.h"
#include "Publication.h"
#include "Book.h"
#include "Digital.h"
#include <iostream>
#include <string>
using namespace std;
/*
* Driver:
* Test the Book and Digital class
*/
int main() {
    Book book;// create a Book object
    Digital digital;// create a Digital object
    book.getData();// test Book getData() function
    cout << endl;
    cout << "------The Book output------" << endl;
    book.putData();// test Book putData() function
    cout << endl;
    cout <<"-----------------------------------------------------------"<< endl;
    digital.getData();// test Digital getData() function
    cout << endl;
    cout << "------The Digital output------"<<endl;
    digital.putData();// test Digital putDate() function
    cout << endl;
    return 0;
}