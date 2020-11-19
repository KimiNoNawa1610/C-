#ifndef EDUCATION_H
#define EDUCATION_H
#include <iostream>
using namespace std;

enum Degree { MS, PhD };

class Education {
	private:
		Degree degree;
		string major;
		int research;
	public:
		Education(string d = "MS", string m = "", int r = 0);
		Education(Education* e);
		void setDegree(Degree d = MS);
		void setDegree(string d = "MS");
		void setMajor(string m);
		void setResearch(int r);
		Degree getDegree();
		string getDegreeStr();
		string getMajor();
		int getResearch();
};

#endif