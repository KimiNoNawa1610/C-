#pragma once
#ifndef POINTTYPE_H
#define POINTTYPE_H

/*
* pointType class definition
*/
class pointType
{
public:
	void setPoint(double x, double y);// set the new x and y value for pointType
	void print() const;// display method
	double getX() const;// get the x-coordinate
	double getY() const;// get the y-coordinate
	pointType(double x = 0.0, double y = 0.0);// pointType constructor

protected:
	double xCoordinate;// protected xCoordinate variable of pointType
	double yCoordinate;// protected yCoordinate variable of pointType
};

#endif // !POINTTYPE_H
