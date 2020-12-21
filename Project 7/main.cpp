#include "cylinderType.h"
#include<iostream>
#include<iomanip>
using namespace std;
/*
* Nhan Vo
* CECS-282
*/
/*
* Driver:
* Use to test the pointType, circleType and cylinderType class
*/
int main()
{	// test the cylinderType constructor
	cylinderType cylinder1(3, 2.5, 4, 2.5);
	cylinderType cylinder2;// declare null cylinder2 object

	cout << fixed << showpoint;
	cout << setprecision(2);// set to two decimal value

	cout << "***** Cylinder 1 *****" << endl;
	cylinder1.print();// output the first cylinder values
	cout << endl;

	cylinder2.setPoint(-2.5, 7);// set the center point of the cylinder2
	cylinder2.setRadius(4);// set the radius of the cylinder2
	cylinder2.setHeight(3.9);// set the height of the cylinder2
	cout << "***** Cylinder 2 *****" << endl;
	cylinder2.print();// output cylinder2 value
	cout << endl;

	double x, y;// declare x,y value for center point
	double r;// r for radius
	double h;// h for height of the cylinder

	cylinderType cylinder3;// declare null cylinder3

	cout << "Enter x Coordinates of the center: ";
	cin >> x;// enter value for x coordinate
	cout << endl;

	cout << "Enter y Coordinate of the center: ";
	cin >> y;// enter value for y coordinate
	cout << endl;

	cout << "Enter base radius: ";
	cin >> r;// enter value for radius
	cout << endl;

	cout << "Enter cylinder height: ";
	cin >> h;// enter value for height
	cout << endl;

	cylinder3.setCenterRadiusHeight(x, y, r, h);// test the setCenterRadiusHeight of the cylinder class

	cout << "***** Cylinder 3 *****" << endl;
	cylinder3.print();// output the value
	cout << endl;

	return 0;
}