#include<iostream>
#include"cylinderType.h"
using namespace std;

/*
* CylinderType class implementation
*/
cylinderType::cylinderType(double x , double y ,// CylinderType constructor
	double r, double h ):circleType(x,y,r){// Call the circleType constructor
	this->height = h;// set the height of the cylinder
}

void cylinderType::print() const{// display method
	cout << "Base Center: (" << this->getX() << ", " << this->getY() << ")"<<endl;// output the base x,y coordinate

	cout << endl;
	cout << "Base Radius: " << this->getRadius()<<endl;// output the radius of the cylinder
	cout << "Base Circumference: " << this->getCircumference() << endl;// output the base circumference
	cout << "Base Area: " << this->getArea() << endl;// output the base area of the cylinder
	cout << "Cylinder height: " << this->getHeight()<< endl;// output the height of the cylinder
	cout << "Cylinder surface area: " << this->getSurfaceArea()<<endl;// output the surface area of the cylinder
	cout << "Cylinder volume:" << this->getVolume() << endl;// output the volume of the cylinder
}

void cylinderType::setHeight(double h) {// setHeight method implementation
	this->height = h;// change the height of the cylinder
}

void cylinderType::setBaseCenter(double x, double y){// setBaseCenter method implementation
	this->setPoint(x, y);// change the base coordinate
}

void cylinderType::setCenterRadiusHeight(double x, double y,
	double r, double h) {// setCenterRadiusHeight method implementation
	this->setPoint(x, y);// set the new base center
	this->setHeight(h);// set the new Height
	this->setRadius(r);// set the new Radius
}

double cylinderType::getHeight() const{// getHeight method implementation
	return this->height;// return the Height of the Cylinder
}

double cylinderType::getVolume() const{// getVolume method implementation
	return this->getArea() * this->getHeight();// calculate the base area and multiply by the height and return the value
}

double cylinderType::getSurfaceArea() const {// getSurfaceArea method implementation
	return (2 * 3.1416 * this->getRadius() * this->getHeight() + 2*this->getArea());// calculate and return the surface area of the cylinder
}