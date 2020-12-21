//Nhan Vo
//CECS 282-Lab10
#include<iostream>
#include"alpha.h"
#include"pointerDataClass.h"
#include"gamma.h"
/*
* driver: test alpha, gamma, pointerDataClass
*/
using namespace std;
int main()
{
	cout << "*******Alpha Testing*******" << endl;
	cout << endl;
	alpha a1(37);
	alpha a2;

	a2 = a1;
	cout << "\na2=";
	a2.display(); //display a2

	alpha a3(a1); //invoke copy constructor
	cout << "\na3=";
	a3.display(); //display a3
	alpha a4 = a1;
	cout << "\na4=";
	a4.display();
	cout << endl;
	cout << endl;
	cout << "*******pointerDataClass (Deep copy)*******" << endl;
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
	cout << "*******Gamma Testing*******" << endl;
	cout << endl;
	gamma g1;
	gamma::showtotal();
	gamma g2, g3;
	gamma::showtotal();
	g1.showid();

	g2.showid();

	g3.showid();

	cout << "----------end of program----------\n";

	return 0;
}


