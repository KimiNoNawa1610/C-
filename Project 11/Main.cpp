#include <vector>
#include<iostream>

#include<algorithm>

#include<numeric>//for accumulator operations

using namespace std;

//Nhan Vo
//CECS 282-Lab 11

int main(){                              
    // an array of doubles

    double arr[] = { 1.1, 2.2, 3.3, 2.2, 4.4 };

    //Determine the array size
    int size = sizeof(arr) / sizeof(arr[0]);


  // initialize vector v1 to array arr
    vector<double> v1;
    for (int i = 0; i < size; i++) {
        v1.push_back(arr[i]);
    }


    //Display the contents of vector v1
    size = v1.size();
    cout << "v1: " << " ";
    for (int i = 0; i < size; i++) {
        cout << v1[i] << ", ";
    }
    cout << endl;
    cout << endl;

 // Sorting the Vector in Ascending order
    sort(v1.begin(), v1.end());




//Display the content of vector v1 after sorting
    cout << "v1 after sorting: " << " ";
    for (int i = 0; i < size; i++) {
        cout << v1[i] << ", ";
    }
    cout << endl;
    cout << endl;

// Reversing the Vector v1
    reverse(v1.begin(), v1.end());


//Display the content of vector v1
    cout << "v1 after reversing: " << " ";
    for (int i = 0; i < size; i++) {
        cout << v1[i] << ", ";
    }
    cout << endl;
    cout << endl;

//Display the maximum element of vector v1
    const double highest = *max_element(v1.begin(), v1.end());
    cout << "The highest Value: " << highest << endl;
    cout << endl;

 //Display the minimum element of vector v1
    const double lowest = *min_element(v1.begin(), v1.end());
    cout << "The highest Value: " << lowest << endl;
    cout << endl;

//Display the accumulation of all elements in vector v1

// Starting the summation from 0
    cout<< "v1-Sum: " << accumulate(v1.begin(), v1.end(), 0.0)<< endl;
    cout << endl;



// Counts the occurrences of 2.2 from 1st to last element

//Display the counts
    const int Count = count(v1.begin(), v1.end(), 2.2);
    cout << "Count of 2.2: " << Count << endl;
    cout << endl;
// Delete second element of vector
    v1.erase(v1.begin() + 1);
    size--;
    //Display the v1 after erasing the element
    cout << "v1 after deleting second element: " << " ";
    for (int i = 0; i < size; i++) {
        cout << v1[i] << ", ";
    }
    cout << endl;
    cout << endl;


    //Remove the duplicate occurrences
    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    size--;
    cout << "v1 after remove duplicate: " << " ";
    for (int i = 0; i < size; i++) {
        cout << v1[i] << ",";
    }
    cout << endl;
    cout << endl;
    cout << "---------------------------------demonstrates reverse(), merge(), and unique()-------------------------------" << endl;
    cout << endl;
    //Create 2 lists called list1 and list2. Store integer numbers.



    int arr1[] = { 40, 30, 20, 10 };

    int arr2[] = { 15, 20, 25, 30, 35 };

    //Determine the array size of arr1 and arr2
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

     //Push elements of array arr1 into list1
    vector<int> list1;
    for (int i = 0; i < size1; i++) {
        list1.push_back(arr1[i]);
    }


    //Push elements of array arr2 into list2
    vector<int> list2;
    for (int i = 0; i < size2; i++) {
        list2.push_back(arr2[i]);
    }

    //Diplay the content of list1 using iterator
    cout << "list1: " << " ";
    for (int i = 0; i < size1; i++) {
        cout << list1[i] << ", ";
    }
    cout << endl;
    cout << endl;

    cout << "list2: " << " ";
    for (int i = 0; i < size1; i++) {
        cout << list2[i] << ", ";
    }
    cout << endl;
    cout << endl;


    // reverse list1: 10 20 30 40
    reverse(list1.begin(), list1.end());

    cout << "Reversed-list1: " << " ";
    for (int i = 0; i < size1; i++) {
        cout << list1[i] << ", ";
    }
    cout << endl;
    cout << endl;

    // merge list2 into list1
    list1.insert( list1.end(), list2.begin(), list2.end());
    size1 += size2;

    cout << "list1-merge-list2: " << " ";
    for (int i = 0; i < size1; i++) {
        cout << list1[i] << ", ";
    }
    cout << endl;
    cout << endl;

  // remove duplicate 20 and 30 from list 1
    sort(list1.begin(), list1.end());
    list1.erase(unique(list1.begin(), list1.end()), list1.end());
    size1 = list1.size();
   

     //Display the list1 in reverse
    reverse(list1.begin(), list1.end());
    cout << "Reversed-list1 and remove duplicate of 20, 30: " << " ";
    for (int i = 0; i < size1; i++) {
        cout << list1[i] << ", ";
    }
    cout << endl;
    cout << endl;



     //Find 25 in the list. If it's found, display "Found 25";otherwise, display "Not found 25"
    if (find(list1.begin(), list1.end(), 25) != list1.end()) {
        cout << "Found 25" << endl;

    }
    else {
        cout << "Not found 25" << endl;
    }
    return 0;

}