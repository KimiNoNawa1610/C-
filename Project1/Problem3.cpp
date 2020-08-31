//Nhan Vo and Ian Lee
// CECS 282 LAB 1-Problem 3
#include <cmath>
#include<iostream>
#include<fstream>
#include <iomanip>
using namespace std;
/*
inputRainfall function:
The function reads the monthly rainfall from the file rainFall.txt and stores them in the array rainFall
*/
void inputRainfall(int rainFall[], int size){
    
    //Open the file
    ifstream inputFile;
    
    inputFile.open("rainfall.txt");
    
    //Initialize month counter
    int month = 0; //first month
    
    //Read the monthly rainfall in the file
    while(size!=0){
        
        size--;// decrement the size of 
        
        inputFile >> rainFall[month];// store the number from file into the array 
        
        month++;// increment the month
        
    }
    inputFile.close();//close the file
    
}

/*
calculateAverageRainFall function:
Return the average monthly rainfall (rounded to the nearest millimeter).
*/

int calculateAverageRainFall(int rainFall[],int size){
    
    int i=0;
    int temp=size;
    double sum;
    double ave=0.0;
    
    
    //Find the sum of the total rain fall
    while(temp!=0){
        
        temp--;
        
        sum+=rainFall[i];
        
        i++;
        
    }
    
    ave=sum/size;// Divide the sum by the 
    
    return int(round(ave));
    
}

/*
classifyAndDisplayRainfall function:
Display the average monthly rainfall, the month with the highest rainfall, and the month with the lowest rainfall.
Also classify each month as average, rainy, or dry.
*/

void classifyAndDisplayRainfall(int rainFall[], int months){
    //Create the string array monthsName 
    string monthsName[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    string Classification[12];//Initialize the Classification (drainy or dry or neither) 
    int diff=1;
    int min;
    int max;
    int maxMonth;
    int minMonth;
    
    double ave=calculateAverageRainFall(rainFall,months);
    
    max=min=rainFall[0];// Initialize min and max rain fall value
    
    minMonth=maxMonth=0;// Initialize the min and max rain fall months
    
    for(int i=0;i<months;i++){
        
       if(rainFall[i]<min){// find min rain fall month
           min=rainFall[i];
           minMonth=i;
       } 
       
       else if(rainFall[i]>max){// find max rain fall month
           max=rainFall[i];
           maxMonth=i;
       }
       
       if(rainFall[i]<(ave*0.75)){// categorize each month as dry, rainy or average
           Classification[i]="Dry";
       }
       
       else if(rainFall[i]>(ave*1.2)){
           Classification[i]="Rainy";
       }
       
       else{
           Classification[i]="Average";
       }
       
    }
    // Out put the value
    cout<<"The year's average monthly rainfall was "<<ave<<" mm."<<endl;// Average rain fall in a year
    
    cout<<monthsName[maxMonth]<<" has the highest rainfall ("<<max<<" mm)."<<endl;// highest rain fall in a year
    
    cout<<monthsName[minMonth]<<" has the lowest rainfall ("<<min<<" mm)."<<endl;// lowest rain fall in a year
    
    cout<<endl;
    
    cout<<"Month"<<setw(20)<<"Rainfall(mm)"<<setw(20)<<"Classification"<<endl;// Output rain fall table for each month.
    
    cout<<"-----"<<setw(20)<<"------------"<<setw(20)<<"--------------"<<endl;
    
    for(int i=0;i<months;i++){
        // output rainfall for each month
        cout<<setw(2)<<i+diff<<setw(18)<<rainFall[i]<<setw(20)<<Classification[i]<<endl;
        
    }
    
}

/*
Driver:
Create an array to store the value from input file
Call for the classifyAndDisplayRainfall and output the result.
*/

int main()
{
    int rainFall[12];
    
    int n=sizeof(rainFall)/sizeof(rainFall[0]);// Size of the array
    
    inputRainfall(rainFall,n);
    
    classifyAndDisplayRainfall(rainFall,n);
    
    return 0;
}
