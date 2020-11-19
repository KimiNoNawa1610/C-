#ifndef Date_H
#define Date_H
#include <iostream>
using namespace std;

class Date {
	private:
		int year;
		int month;
		int day;
		string dateString;
	public:
		Date(string dateStr = "1/1/1900");
		void setMonth(int m);
		void setDay(int d);
		void setYear(int y);
		string getDateString();
};

#endif