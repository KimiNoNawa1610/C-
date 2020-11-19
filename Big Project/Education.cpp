//CECS282 Project-1
//Nhan Vo and Ian Lee
#include<iostream>
#include"Education.h"
using namespace std;
/*
* Education class implementation
*/
Education::Education() {// default constructor implementation
	degree = MS;// default degree is MS(master)
	major = "None";// default major is none
	research = 0;// default research =0;
}

Education::Education(string d, string m, int r) {// constructor with paramenter
	(d == "MS") ? degree = MS : PhD;// set the degree
	major = m;// set the major
	research = r;// set number of research
}

void Education::setDegree(string d) {// degree setter function implementation
	(d == "MS") ? degree = MS : PhD;// tranform the condition from the string to enum type value
}

void Education::setMajor(string m) {// major setter function implementation
	major = m;// set the major
}

void Education::setResearch(int r) {// research setter function implmentation
	research = r;// set the research number
}

string Education::getDegree() {// degree getter function implementation
	string n;// create an empty string
	(degree == MS) ? n = "MS" : "PhD";// depend on the degree, output the equivalent string 
	return n;
}

string Education::getMajor() {// major getter function implementation
	return major;// return the major string
}

int Education::getNumResearch() {// research getter function implementation
	return research;// return number of research
}
