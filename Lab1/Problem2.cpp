#include <stdio.h>
#include<iostream>
using namespace std;
/*
bin2Dec function:
Take a reference of a string as parameter
if the char in the string is not 0, add to sum
implement the power.
*/
int bin2Dec(const string& binaryString) {
    int power = 1, sum = 0;
    for (int i = 0; i < binaryString.length(); i++) {
        if (binaryString[i] != '0') {
            sum += power;
        }
        power *= 2;
    }
    return sum;

}
/*
Driver:
Take string input from the user and pass it as a parameter to bin2Dec function
output the result.
*/
int main()
{
    string input;
    cout << "Please enter your binary number" << endl;
    cin >> input;
    cout << "Binary Conversion: " << bin2Dec(input) << endl;

    return 0;
}