//Nhan Vo
//CECS 282-Lab10
#include<iostream>
using namespace std;
class pointerDataClass

{
	int maxSize;//variable to store the maximum size of p

	int length;//variable to store the number of elements in p

	int* p;// pointer to an int array
	
	int dynamic=0;// condition to see if a pointer is dynamically allocated or not

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

pointerDataClass::pointerDataClass(int size) {// parameter constructor
    dynamic++;
	maxSize = size;// set size
	p = new int[size];// dynamically allocate pointer p
	length = 0;// length=0
	for (int i = 0; i < maxSize; i++) {
		p[i] = 0;// initiate pointer array
	}
}

//Shallow copy
pointerDataClass::pointerDataClass(const pointerDataClass& p1) {
	this->length = p1.length;// copy length value
	this->maxSize = p1.maxSize;// copy maxSize value
	this->p = p1.p;// point p array into p1 array memory address
}

pointerDataClass::~pointerDataClass() {// Destructor
    if(p!=nullptr&&dynamic!=0){// delete if p had been dynamically allocate
        delete this->p;
        cout<<"Done"<<endl;
    }
}

void pointerDataClass::insertAt(int index, int num) {// insertAt function to insert into p pointer array
	for (int i = maxSize-1; i >=index; i--) {
		p[i]=p[i-1];// move the element after index to the right 1 digit
	}
	p[index] = num;// assign num to index element
	length++;// increment length
}

void pointerDataClass::displayData() {// displayData function
	for (int i = 0; i < maxSize; i++) {// for loop to display p array
		cout << p[i] << ", ";
	}
	cout << endl;
}
//driver to output shallow copy
int main(){
    cout << "*******pointerDataClass (Shallow copy)*******" << endl;
	cout << endl;
	pointerDataClass list1(10);
	list1.insertAt(0, 50);
	list1.insertAt(4, 30);
	list1.insertAt(8, 60);
	cout << "List1: " << endl;
	list1.displayData();
	cout << endl;
	cout << "List 2: " << endl;
	pointerDataClass list2(list1);
	list2.displayData();
	cout << endl;
	list1.insertAt(4, 100);
	cout << "List1: (after insert 100 at indext 4) " << endl;
	list1.displayData();
	cout << endl;
	cout << "List 2: " << endl;
	list2.displayData();
	cout << endl;
    return 0;
}

