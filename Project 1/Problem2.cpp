//Nhan Vo And Ian Lee
// CECS 282 LAB 1-Problem 2
#include<iostream>
using namespace std;
/*
bin2Dec function:
Take a reference of a string as parameter
if the char in the string is not 0, add to sum 
implement the power.
*/
int bin2Dec(const string& binaryString){
    
    int power=1;
    int sum=0;
    int factor=2;
    
    //Iterate through the binary string
    for(int i=binaryString.length()-1;i>-1;i--){// Start from the right most of the binary string
    
        if(binaryString[i]!='0'){//If the binary string character is not 0
        
            sum+=power;// start increment into sum
            
        }
        
        power*=factor;// increment power by the factor of 2
        
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
    string input;//Initialize the user's input holder
    
    cout<<"Please enter your binary number"<<endl;
    
    cin>>input;//store the input
    
    cout<<"Binary Conversion: "<<bin2Dec(input)<<endl;// call bin2Dec function and output result.
    
    return 0;
}









