//Nhan Vo
//CECS 282-Lab10
#pragma once
#ifndef GAMMA_H
#define GAMMA_H
/*
* gamma class definition
*/
class gamma {
private:
	static int total;//static total variable
	int id;// id variable
public:
	gamma();//default constructor
	static void showtotal();// output total function
	void showid();// output id function
	virtual ~gamma();// virtual destructor
};
#endif // !GAMMA_H
