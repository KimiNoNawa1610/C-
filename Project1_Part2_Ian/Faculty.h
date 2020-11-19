#ifndef FACULTY_H
#define FACULTY_H
#include "Employee.h"
#include "Education.h"

enum Level {
	AS,
	AO,
	FU
};

class Faculty: public Employee {
	private:
		Level level;
		Education* eduObj;
	public:
		Faculty(string lNmae = "", string fName = "", string id = "", Sex s = M, string dateStr = "", Level l = AS, string degreeStr = "MS", string major = "", int research = 0);
		Faculty(Faculty* f);
		~Faculty();
		void setLevel(Level l = AS);
		void setEducation(Education e);
		Level getLevel();
		Education getEducation();
		void getData();
		double monthlyEarning();
		void putData();
};

#endif