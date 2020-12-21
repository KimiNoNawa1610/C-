#include<iostream>
#include"Matrix.h"
using namespace std;
/*
* Matrix constructor, creates a matrix in heap 
*/
Matrix::Matrix(int r, int c) {
	rowSize = r;//initialize rowSize
	colSize = c;//initialize colSize
	ptr = new int* [rowSize];// dynamic allocate a new pointer array
	for (int i = 0; i < rowSize; i++) {
		ptr[i] = new int[colSize];// allocate mutiple column in the matrix
	}
}

/*
* Matrix destructor to delete the allocated memory in heap
*/
Matrix::~Matrix() {
	for (int i = 0; i < rowSize; i++) {
		delete[] ptr[i];//perform deletion 
	}
}

/*
* InputMatrix: Prompt the user to create a matrix
*/
void Matrix::InputMatrix() {
	int n;
	int i, j;
	i = j = 0;
	int size = rowSize * colSize;// calculation the iteration of the loop
	while (size > 0) {// use while loop to prompt the user
		cin >> n;
		size--;
		ptr[i][j] = n;// store the user input into the allocated memory
		j++;
		if (j == colSize) {
			j = 0;//reset column position
			i++;
		}
	}
}

/*
* Display the matrix 
*/
void Matrix::print() const{
	for (int i = 0; i < rowSize; i++) {// use nested for loop to output each number in a matrix
		for (int j = 0; j < colSize; j++) {
			cout << ptr[i][j] << " ";
		}
		cout << "\n";
	}
}
/*
* add operator: Perform addition of two matrices with the same dimesion
* The matrix need to have the same number of row and column
*/
void Matrix::add(const Matrix& second, Matrix& result) const {
	if (this->colSize == second.colSize && this->rowSize==second.rowSize) {//If the dimensions of the two matrices are the same
		for (int i = 0; i < rowSize; i++) {//nested for loop to perform adding row by row and column by column of two matrices
			for (int j = 0; j < colSize; j++) {
				result.ptr[i][j] = this->ptr[i][j] + second.ptr[i][j];// store the sum of two number in the matrices in a new matrix
			}
		}
	}
	else {// Output error message if the dimestions of the two matrices are different
		cout << " Matrices need to have the same dimension" << endl;
	}
}

/*
* subtract operator: Perform subtraction of two matrices with the same dimension
* The matrix need to have the same number of row and column
*/
void Matrix::subtract(const Matrix& second, Matrix& result) const {
	if (this->colSize == second.colSize && this->rowSize == second.rowSize) {//If the dimensions of the two matrices are the same
		for (int i = 0; i < rowSize; i++) {//nested for loop to perform subtracting row by row and column by column of two matrices
			for (int j = 0; j < colSize; j++) {
				result.ptr[i][j] = this->ptr[i][j] - second.ptr[i][j];// store the difference of two number in the matrices in a new matrix
			}
		}
	}
	else {// Output error message if the dimestions of the two matrices are different
		cout << " Matrices need to have the same dimension" << endl;
	}
}

/*
* multiply operator: Perform multiplication of two matrices.
* The number of column in the first matrix has to equal the number or row in the second matrix
*/
void Matrix::multiply(const Matrix& second, Matrix& result) const {
	if (this->colSize == second.rowSize) {// If the column of the first matrix equals the number of row in the second matrix
		for (int i = 0; i < this->rowSize;i++) {//Nested for loop to perform multiplication
			for (int j = 0; j < second.colSize; j++) {
				result.ptr[i][j] = 0;// initialize the number of null position in the result matrix
				for (int k = 0; k < second.rowSize; k++) {
					result.ptr[i][j] += this->ptr[i][k] * second.ptr[k][j];//store the multiplication result into the new matrix
				}
			}
		}
	}
	else {// if the column size of the first matrix is different from the row size of the second matrix
		cout << " Second Matrix's row and first Matrix's Column need to be the same" << endl;
	}
}