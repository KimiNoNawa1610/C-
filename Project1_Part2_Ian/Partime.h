#ifndef PARTIME_H
#define PARTIME_H
#include "Staff.h"
#include "Date.h"
using namespace std;

class Partime: public Staff {
	private:
		double workHours;
	public:
		Partime(string lNmae = "", string fName = "", string id = "", Sex s = M, string dateStr = "", double hourlyRate = 0., double hours = 0.);
		Partime(Partime* p);
		void setHours(double h);
		double getHours();
		void getData();
		double monthlyEarning();
		void putData();
};

#endif