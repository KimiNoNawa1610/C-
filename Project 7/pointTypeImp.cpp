#include <iostream>
#include "pointType.h"
using namespace std;

/*
*  pointType class implementation
*/
void pointType::setPoint(double x, double y)// setPoint method implementation
{
	xCoordinate = x;// set x coordinate
	yCoordinate = y;// set y coordinate
}

void pointType::print() const// display method
{
	cout << "(" << xCoordinate << ", " << yCoordinate << ")" << endl;// output the x,y coordinate
}

double pointType::getX() const// getX method implementation
{
	return xCoordinate;// return the xCoordinate value
}

double pointType::getY() const// getY method implementation
{
	return yCoordinate;// return the yCoordinate value
}

pointType::pointType(double x, double y)// pointType constructor
{
	xCoordinate = x;// set xCoordinate
	yCoordinate = y;// set yCoordinate
}