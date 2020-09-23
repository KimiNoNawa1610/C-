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
class Matrix
{
private:
	int rowSize;
	int colSize;
	int** ptr;
public:
	Matrix(int rowSize, int colSize);
	~Matrix();
	void InputMatrix();//input the matrix from the user row by row
	void add(const Matrix& second, Matrix& result) const;
	void subtract(const Matrix& second, Matrix& result) const;
	void multiply(const Matrix& second, Matrix& result) const;
	void print() const;
};
#endif // !MATRIX_H

