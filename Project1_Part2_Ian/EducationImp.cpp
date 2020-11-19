#include "Education.h"

Education::Education(string d, string m, int r) {
	setDegree(d);
	major = m;
	research = r;
}

Education::Education(Education* e) {
	degree = e->degree;
	major = e->major;
	research = e->research;
}

void Education::setDegree(Degree d)
{
	degree = d;
}

void Education::setDegree(string d) {
	if (d == "MS") degree = MS;
	else degree = PhD;
}

void Education::setMajor(string m)
{
	major = m;
}

void Education::setResearch(int r) {
	research = r;
}

Degree Education::getDegree() {
	return degree;
}

string Education::getDegreeStr() {
	if (degree == MS) return "MS";
	else return "Ph.D";
}

string Education::getMajor() {
	return major;
}

int Education::getResearch() {
	return research;
}
