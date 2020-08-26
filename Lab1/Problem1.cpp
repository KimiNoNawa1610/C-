#include <stdio.h>
#include <iostream>
using namespace std;
/*
Take a pass by value number
Find the remainder of the number and reduce it by 10 percent each itteration
If the remainder is odd, add to the sum
*/
int OddCalculation(int x) {
    int temp = 0, sum = 0;
    while (x > 0) {
        temp = x % 10;
        x = x / 10;
        if (temp % 2 != 0) {
            sum += temp;
        }
    }
    return sum;
}

/*
Driver:
Take the input from the user
Call the OddCalculation() function with the number from the user.
*/
int main()
{
    int input;
    cout << "Please Enter your number" << endl;
    cin >> input;
    cout << OddCalculation(input);
    return 0;
}