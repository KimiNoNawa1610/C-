//CECS282 Project-1
//Nhan Vo and Ian Lee
#include "Employee.h"
#include "Faculty.h"
#include "Staff.h"
#include "Parttime.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
/*
* Driver: Test Employee sub-classes
*/
int main() {
    vector<Employee*> employees;  //array of ptrs to emps
    int n; 
    char ch;
    while (true)
    {
        cout << "'a' -- add data for an employee"
            "\n'd' -- display data for all employees"
            "\n'w' -- write all employee data to file"
            "\n'r' -- read all employee data from file"
            "\n'x' -- exit"
            "\nEnter selection: ";
        cin >> ch;
        switch (ch)
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
        cout << endl;
    }  //end while
}



	