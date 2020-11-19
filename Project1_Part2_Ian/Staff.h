#ifndef STAFF_H
#define STAFF_H
#include "Employee.h"

class Staff: public Employee {
	private:
		double hourlyRate;
	public:
		Staff(string lNmae = "", string fName = "", string id = "", Sex s = M, string dateStr = "", double hr = 0.);
		Staff(Staff* s);
		void setHourlyRate(double r);
		double getHourlyRate();
		void getData();
		double monthlyEarning();
		void putData();
};

#endif