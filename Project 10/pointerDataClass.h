//Nhan Vo
//CECS 282-Lab10
#pragma once
#ifndef POINTERDATACLASS_H
#define POINTERDATACLASS_H
#include<iostream>
using namespace std;
/*
* pointerDataClass definition
*/
class pointerDataClass

{
	int maxSize;//variable to store the maximum size of p

	int length;//variable to store the number of elements in p

	int* p;// pointer to an int array

public:
	//Constructor to create an array of the size specified by the parameter size.

	pointerDataClass(int size);

	//Destructor to deallocate the memory space occupied by the array p

	~pointerDataClass();

	//the function insertAt inserts num into array p at the position specified by  
	//index

	void insertAt(int index, int num);

	//The function displayData displays all the array elements in p

	void displayData();

	//Copy constructor
	pointerDataClass(const pointerDataClass& p1);//deep copy


};
#endif // !POINTERDATACLASS


