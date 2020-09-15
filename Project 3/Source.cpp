#include<iostream>
#include<fstream>
/*
* Nhan Vo
* CECS 282- Project 3
*/
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

/*
* arr is a pointer to an array of integers to be sorted. last is the number of elements in the array. 
*/
void bsort(int* arr, int last) {
    bool isSorted = false;// default that the list is not sorted
    // Sort the numbers using pointers 
    while (!isSorted) {
        isSorted = true;// change the isSorted value to true
        for (int i = 0; i < last; i++) {// create net loop to check 2 element in the array
            for (int j = i + 1; j < last; j++) {
                if (*(arr + i) > * (arr + j)) {//The function bsort sorts the list of integers in ascending order.
                    //Swap the i and j element in the array
                    int temp = *(arr + i);
                    *(arr + i) = *(arr + j );
                    *(arr + j) = temp;
                    isSorted = false; // update the isSorted condition to false
                }
            }
        }
    }
}

/*
* arr is a pointer to an array of integers. last is the number of elements in the array.
*/
void writeToConsole(int* arr, int last) {
    for (int i = 0; i < last; i++) {// displays the list
        cout << *(arr + i) << ",";
    }
    cout << endl;
}

/*
* isGreater than function to compare if number a greater than number b
*/
bool isGreater(int a, int b) {
    if (a > b) {// if a>b return true
        return true;
    }
    return false;// else return false
}

/*
* isLess than function to compare if number a less than number b
*/
bool isLess(int a, int b) {
    if (a < b) {// if a<b return true
        return true;
    }
    return false;// else return false
}

/*
Pre condition
array - a pointer to a an array of size element.
pointer to function - a pointer to a function that compares two values (depending on sorting in ascending order or descending order)
Post condition
Sort the array in ascending or descending based on the the pointer to a function.
*/
void bubble_sort(int* array, int size, bool(*hold)(int, int)) {
    bool isSorted = false;
    // default that the list is not sorted
    // Sort the numbers using pointers 
    //Similar to the bsort function
    //except the condition value of bool (*hold)
    while (!isSorted) {
        isSorted = true;// change the isSorted value to true
        for (int i = 0; i < size; i++) {// create net loop to check 2 element in the array
            for (int j = i + 1; j < size; j++) {
                bool cond = (*hold)(*(array + i), *(array + j));// store the boolean value of ascending or descending condition 
                if (cond==true) {//The function bsort sorts the list of integers in order according to the cond condition.
                    //Swap the i and j element in the array
                    int temp = *(array + i);
                    *(array + i) = *(array + j);
                    *(array + j) = temp;
                    isSorted = false;// update the isSorted condition to false
                }
            }
        }
    }
}

/*
* Driver:
* Test the previous functions
*/

int main() {

    int* arr;// create pointer of an integer

    int n;// create an integer value

    cout <<"The size of the array (readData function tester)"<<endl;
    n = readData(arr);// call readData to store the size of the array in the n value 
    cout << "The array has size of: " << n << endl;
    cout << endl;
    cout << "bsort function testing:" << endl;
    bsort(arr, n);// Test the bsort function by calling bsort to sort arr in ascending order
    writeToConsole(arr, n);

    cout << endl;
    cout << "Array sorted in decending order:" << endl;
    bubble_sort(arr, n, isLess);  // Test bubble_sort in ascending order
    writeToConsole(arr, n);

    cout << endl;

    cout << "Array sorted in ascending order:" << endl;
    bubble_sort(arr, n, isGreater);// Test bubble_sort in deceding order
    writeToConsole(arr, n);
    

    return 0;
}