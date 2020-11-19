//CECS282 Project-1
//Nhan Vo and Ian Lee
#pragma once
#include<iostream>
using namespace std;
#ifndef EDUCATION_H
#define EDUCATION_H
enum Degree{MS, PhD};// enum Degree type definition, include two elements, MS and PhD

/*
* Education class definition
* 3 attribute: degree, major and research
*/
class Education {
private:
	Degree degree;
	string major;
	int research;
public:

	Education();// default constructor

	Education(string d, string m, int r);// constructor with parameters

	void setDegree(string d);// setDegress function definition

	void setMajor(string m);// setMajor function definition

	void setResearch(int r);// setResearch function definition

	string getDegree();// degree getter definition

	string getMajor();// major getter definition

	int getNumResearch();// research getter definition
};
#endif // !EDUCATION_H
