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
    int n; 
    char ch;
    vector <Employee*> empPtrs(9);
    // Creat Staff Objects according to the Test Data in the assignment.
    empPtrs[0] = new Staff("Allen", "Paita", "123", "M", "2/23/1959", 50.);
    empPtrs[3] = new Staff("Zapata", "Steven", "456", "F", "7/12/1964", 35.);
    empPtrs[6] = new Staff("Rios", "Enrique", "789", "M", "6/2/70", 40.);
    // Creat Faculty Objects according to the Test Data in the assignment
    empPtrs[1] = new Faculty("Johnson", "Anne", "243", "F", "4/27/1962", "FU","Ph.D", "Engineering", 3);
    empPtrs[4] = new Faculty("Bouris", "William", "791", "F", "3/14/1975", "AO","Ph.D", "English", 1);
    empPtrs[7] = new Faculty("Andrade", "Christopher", "623", "F", "5/22/1980","AS", "MS", "Physical Education", 0);
    // Creat Faculty Objects according to the Test Data in the assignment
    empPtrs[2] = new Parttime("Guzman", "Augusto", "455", "F", "8/10/1977", 35.,30);
    empPtrs[5] = new Parttime("Depirro", "Martin", "678", "F", "9/15/1987", 30.,15);
    empPtrs[8] = new Parttime("Aldaco", "Marque", "945", "M", "11/24/1988", 20.,35);

    Employee::setVector(empPtrs);

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



	