#pragma once
#ifndef H_CylinderType
#define H_CylinderType
#include "circleType.h"

/*
* cylinderType class definition
*/
class cylinderType : public circleType //inherit the circleType
{
public:
	void print() const;// display method
	void setHeight(double h);// change the height value of the cylinder
	void setBaseCenter(double x, double y);// set the circle base of the cylinder
	void setCenterRadiusHeight(double x, double y,
		double r, double h);// set all value of the cylinder

	double getHeight() const;// get the height of the cylinder
	double getVolume() const;// calculate the volume of the cylinder
	double getSurfaceArea() const;// calculate the surface area of the cylinder
	cylinderType(double x = 0.0, double y = 0.0,
		double r = 0.0, double h = 0.0);// cylinderType constructor

protected:
	double height;// protected height variable of the cylinderType
};


#endif // !CYLINDERTYPE_H

