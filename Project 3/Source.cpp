#include<iostream>
#include<fstream>
using namespace std;
// Reads data from a text file into an array
int readData(int*& arr) {
    // Open the file to get the data
    int size;
    ifstream inputFile;
    inputFile.open("data.txt");
    // The first line of the file is the size of the array
    inputFile >> size;
    arr = new int[size];
    //Allocate the memory for pointer arr

    // Read the rest of the data into the array
    for (int i = 0; i < size; i++) {
        inputFile >> *(arr+i);
    } // End for loop
    inputFile.close();
    return size;
} // End readData

void bsort(int* arr, int last) {
    bool isSorted = 0;
    // Sort the numbers using pointers 
    while (!isSorted) {
        isSorted = 1;
        for (int i = 0; i < last; i++) {
            for (int j = i + 1; j < last; j++) {
                if (*(arr + i) > * (arr + j)) {
                    int temp = *(arr + i);
                    *(arr + i) = *(arr + j );
                    *(arr + j) = temp;
                    isSorted = 0;
                }
            }
        }
    }
}

void writeToConsole(int* arr, int last) {
    bsort(arr, last);
    for (int i = 0; i < last; i++) {
        cout << *(arr + i) << ",";
    }
}

int main() {

    int* arr;

    int n;

    n = readData(arr);

    return 0;
}