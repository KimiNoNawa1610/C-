#include "Date.h"
#include <string>

Date::Date(string dateStr) {
	dateString = dateStr;
}

void Date::setMonth(int m) {
	month = m;
}

void Date::setDay(int d)
{
	day = d;
}

void Date::setYear(int y)
{
	year = y;
}

string Date::getDateString() {
	return dateString;
}