#include<iostream>
#include"Matrix.h"
using namespace std;

Matrix::Matrix(int r, int c) {
	rowSize = r;
	colSize = c;
	ptr = new int* [rowSize];
	for (int i = 0; i < rowSize; i++) {
		ptr[i] = new int[colSize];
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < rowSize; i++) {
		delete[] ptr[i];
	}

}