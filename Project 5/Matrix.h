#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <cassert>
using namespace std;

// Matrix class definition
/*
* The interface file for the Matrix class. The only private *
* members are the sizes of the matrix and the pointer that *
* points to the matrix in the heap. *
*/
class Matrix
{
private:
	int rowSize;
	int colSize;
	int** ptr;
public:
	Matrix(int rowSize, int colSize);//The constructor creates a matrix in the heap
	~Matrix();//the destructor deletes the allocated memory in the heap.
	void InputMatrix();//input the matrix from the user row by row
	void add(const Matrix& second, Matrix& result) const;//peform adding operator
	void subtract(const Matrix& second, Matrix& result) const;//perform subtracting operator
	void multiply(const Matrix& second, Matrix& result) const;//perform multipling operator
	void print() const;//display the matrix

};
#endif // !MATRIX_H

