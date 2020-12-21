#include <iostream>
#include "circleType.h"
using namespace std;

/*
* circleType class implementation
*/
void circleType::print() const// display method
{
	cout << "Center: ";
	pointType::print();// call the display method of pointType to output the x, y coordinate
	cout << endl;

	cout << "Radius: " << radius << endl;// output the radius
	cout << "Circumference: " << getCircumference() << endl;// output the circumference
	cout << "Area: " << getArea() << endl;// output the Area
}

void circleType::setRadius(double r)// setRadius method implementation
{
	radius = r;// set the new radius
}

double circleType::getRadius() const// getRadius method implementation
{
	return radius;// return the radius value
}

double circleType::getCircumference() const// getCircumference implementation
{
	return (2 * 3.1416 * radius);// calculate and return the value of the circumference
}

double circleType::getArea() const// getArea implementation
{
	return (3.1416 * radius * radius);// calculate and return the area 
}

circleType::circleType(double x, double y, double r)// circleType constructor
	:pointType(x, y)// call the pointType constructor
{
	radius = r;// set the radius of the circle
}