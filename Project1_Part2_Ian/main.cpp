#include "Employee.h"
#include "Faculty.h"
#include "Staff.h"
#include "Partime.h"
#include <iostream>
#include <vector>
#include <typeinfo>
#include <fstream>
using namespace std;

//g++ DateImp.cpp EducationImp.cpp EmployeeImp.cpp FacultyImp.cpp part1.cpp PartimeImp.cpp StaffImp.cpp -o pro1

int main()
   {
   char ch;
   while(true)
      {
      cout << "'a' -- add data for an employee"
              "\n'd' -- display data for all employees"
              "\n'w' -- write all employee data to file"
              "\n'r' -- read all employee data from file"
              "\n'x' -- exit"
              "\nEnter selection: ";
      cin >> ch;
      switch(ch)
         {
         case 'a':            //add an employee to list
            Employee::add(); break;
         case 'd':            //display all employees
            Employee::display(); break;
         case 'w':            //write employees to file
            Employee::write(); break;
         case 'r':            //read all employees from file
            Employee::read(); break;
         case 'x': exit(0);   //exit program
         default: cout << "\nUnknown command";
         }  //end switch
      }  //end while
   return 0;
   }  //end main()
