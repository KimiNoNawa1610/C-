/*
* Nhan Vo
* CECS 282-Lab 8
*/
#pragma once
#ifndef SALES_H
#define SALES_H
#include <iostream>
using namespace std;
/*
* Sale class definition
*/
class Sale {

public:
    //Declare functions getData and putData
    void getData();// prompt the user
    void putData();// output the data

private:
    float saleArray[3];// an array to store sales for three months

};
#endif // !SALES_H
