//Nhan Vo
// CECS 282 LAB 1-Problem 1
#include <iostream>
using namespace std;
/*
Take a pass by value number
Find the remainder of the number and reduce it by 10 percent each itteration
If the remainder is odd, add to the sum
*/
int OddCalculation(int x){
    
    int temp=0;
    int sum=0;
    int factor=2;
    int decimal=10;
    
    
    while(x>0){
        
        temp=x%decimal;// seperate each number in x
        
        x=x/decimal;// remove the seperated number
        
        if(temp%factor!=0){
            
            sum+=temp;// If the seperated number is odd, add to sum
            
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
    int input;// initialize user's input holder
    
    cout<<"Please Enter your number"<<endl;
    
    cin>>input;// store input
    
    cout<<OddCalculation(input);//call OddCalculation function
    
    return 0;
    
}







