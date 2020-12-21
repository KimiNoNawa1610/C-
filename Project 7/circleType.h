#pragma once
#ifndef H_CircleType
#define H_CircleType
#include "pointType.h"
/*
* Circle class definition
*/
class circleType : public pointType// inherit pointType class
{
public:
	void print() const;// display method
	void setRadius(double r);// set radius of the circle
	double getRadius() const;// get the radius
	double getCircumference() const;// calculate the circumference
	double getArea() const;// calculate the area of the circle
	circleType(double x = 0.0, double y = 0.0, double r = 0.0);// circleType constructor

protected:
	double radius;// declare protected radius variable of the circle
};

#endif // !CIRCLETYPE_H
