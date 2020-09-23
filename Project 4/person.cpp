#include<iostream>
using namespace std;
/*
* Nhan Vo
* CECS 282
* Lab#4
*/

/*
* Class person 
* Has string name
* And float salary
*/
class person {
private:
	string name;
	float salary;
public:
	void setPerson();//function holder for setPerson() function
	string getName();//function holder for getName() function
	float getSalary();//function holder for getSalary() function

};

/*
* setPerson() function
* Take the person name and salary
* 
*/
void person::setPerson() {
	cout << "Please enter a name:" << endl;// prompt the user a name
	cin >> name;//store the name
	cout << "Please enter that person salary:" << endl;//prompt the user's salary
	cin >> salary;//store the salary
}

/*
* getName() function
* return the person's name
*/
string person::getName() {
	return name;
}

/*
* getSalary() function
* return the person's salary
*/
float person::getSalary() {
	return salary;
}

/*
* order() function
* take two pointer to pointer object
* and switch the pointer 
*/
void order(person** a, person** b) {
	person *temp;// create a temporary pointer value
	temp = *a;// make the temporary point to address of pointer a
	*a = *b;// switch pointer a and b
	*b = temp;// switch pointer temp and b

}

/*
* bsort() function
* take a person**, int n- size of the array and boolean s
* if s is true, sort by name, else sort by salary
*/
void bsort(person** p, int n, bool s) {
	bool isSorted = false;// the default array is not sorted
	while (isSorted == false) {// while loop condition
		isSorted = true;// set isSorted= true
		for (int i = 0; i < n; i++) {// net for loop to swap the element
			for (int j = i + 1; j < n; j++) {
				if (s == true) {// if boolean s is true, sort by name
					if (p[i]->getName() > p[j]->getName()) {//comapre the name
						order(&p[i], &p[j]);// call function order() to swap the pointer
						isSorted = false;// set is sorted to false
					}
				}
				else {// if s is false, sort by salary
					if (p[i]->getSalary() > p[j]->getSalary()) {//compare the salary
						order(&p[i], &p[j]);// call function order() to swap the pointer
						isSorted = false;// set is sorted to false
					}
				}
			}
		}
	}
}

/*
* bsort_nonOrder() function
* take a person**, int n- size of the array and boolean s
* if s is true, sort by name, else sort by salary
* the same as bsort() function except swapping the pointers directly inside the loop. 
*/
void bsort_nonOrder(person** p, int n, bool s) {
	bool isSorted = false;// the default array is not sorted
	while (isSorted == false) {// while loop condition
		isSorted = true;// set isSorted= true
		for (int i = 0; i < n; i++) {// net for loop to swap the element
			for (int j = i + 1; j < n; j++) {
				person* temp;// create temporary pointer 
				if (s == true) {// if boolean s is true, sort by name
					if (p[i]->getName() > p[j]->getName()) {//compare the name
						temp = p[j];// make the temporary point to address of pointer p[j]
						p[j] = p[i];// switch pointer p[i] and p[j]
						p[i] = temp; // switch pointer temp and p[i]
						isSorted = false;// set is sorted to false
					}
				}
				else {// if boolean s is false, sort by salary
					if (p[i]->getSalary() > p[j]->getSalary()) {//compare the salary
						temp = p[j];// make the temporary point to address of pointer p[j]
						p[j] = p[i];// switch pointer p[i] and p[j]
						p[i] = temp;// switch pointer temp and p[i]
						isSorted = false;// set is sorted to false
					}
				}
			}
		}
	}
}

/*
* Display() function 
* display the array
* take parameter pointer to pointer person and int n-size of the array
*/
void Display(person **p, int n) {
	for (int i = 0; i < n; i++) {//for loop to output the person's information
		cout << p[i]->getName() << " Salary: " << p[i]->getSalary()<<" , ";
	}
	cout << endl;
}

/*
* Driver test class person and related functions
*/
int main() {
	person** arr;// create a pointer to pointer arr
	int n;// holder for size of the array
	cout << "please enter the size of the array" << endl;// prompt the user the size of the array
	cin >> n;//store the size of the array
	arr = new person *[n];// allocate the memory for arr
	for (int i = 0; i < n; i++) {//for loop to assign the person array
		arr[i] = new person();
		arr[i]->setPerson();
	}
	/*Output the test result*/
	cout << "Unsorted Person Array:" << endl;
	Display(arr, n);// Display the unsorted array
	cout << endl;
	cout << "Sorted Person Array by name" << endl;
	bsort(arr, n, true);//sort the array by name using bsort() function
	Display(arr, n);//display the sorted array
	cout << endl;
	cout << "Sorted Person Array by salary" << endl;
	bsort(arr, n, false);//sort the array by salary using bsort() function
	Display(arr, n);//display the sorted array
	cout << endl;
	cout << "Test the bubble sort without the order function" << endl;
	cout << "Sort by name" << endl;
	bsort_nonOrder(arr, n, true);//sort the array using bsort-nonOrder() function by name
	Display(arr, n);//display the sorted array
	cout << endl;
	cout << "Sort by salary" << endl;
	bsort_nonOrder(arr, n, false);//sort the array using bsort-nonOrder() function by salary
	Display(arr, n);//display the sorted array
	return 0;
}