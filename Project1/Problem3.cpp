//Nhan Vo and Ian Lee
// CECS 282 LAB 1-Problem 3
#include <stdio.h>
#include<iostream>
#include<fstream>
#include <iomanip>
using namespace std;
void inputRainfall(int rainFall[], int size){
    
    //Open the file
    ifstream inputFile;
    
    inputFile.open("rainfall.txt");
    
    //Initialize month counter
    int month = 0; //first month
    
    //Read the monthly rainfall in the file
    while(size!=0){
        
        size--;
        
        inputFile >> rainFall[month];
        
        month++;
        
    }
    
}

int calculateAverageRainFall(int rainFall[],int size){
    
    int i=0,temp=size;
    
    float ave=0.0,sum=0.0,diff=0.5;
    
    while(temp!=0){
        
        temp--;
        
        sum+=rainFall[i];
        
        i++;
        
    }
    
    ave=sum/size;
    
    ave=ave+diff;//rounding the average rain fall;
    
    return int(ave);
    
}



void classifyAndDisplayRainfall(int rainFall[], int months){
    
    string monthsName[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    string Classification[12];
    
    int min, max,maxMonth,minMonth, ave=calculateAverageRainFall(rainFall,months);
    
    max=min=rainFall[0];
    
    minMonth=maxMonth=0;
    
    for(int i=0;i<months;i++){
        
       if(rainFall[i]<min){
           min=rainFall[i];
           minMonth=i;
       } 
       
       else if(rainFall[i]>max){
           max=rainFall[i];
           maxMonth=i;
       }
       
       if(rainFall[i]<(ave*0.75)){
           Classification[i]="Dry";
       }
       
       else if(rainFall[i]>(ave*1.2)){
           Classification[i]="Rainy";
       }
       
       else{
           Classification[i]="Average";
       }
       
    }
    
    cout<<"The year's average monthly rainfall was "<<ave<<" mm."<<endl;
    
    cout<<monthsName[maxMonth]<<" has the highest rainfall ("<<max<<" mm)."<<endl;
    
    cout<<monthsName[minMonth]<<" has the lowest rainfall ("<<min<<" mm)."<<endl;
    
    cout<<endl;
    
    cout<<"Month"<<setw(20)<<"Rainfall(mm)"<<setw(20)<<"Classification"<<endl;
    
    cout<<"-----"<<setw(20)<<"------------"<<setw(20)<<"--------------"<<endl;
    
    for(int i=0;i<months;i++){
        
        cout<<setw(2)<<i+1<<setw(18)<<rainFall[i]<<setw(20)<<Classification[i]<<endl;
        
    }
    
}

int main()
{
    int rainFall[12];
    
    int n=sizeof(rainFall)/sizeof(rainFall[0]);
    
    inputRainfall(rainFall,n);
    
    classifyAndDisplayRainfall(rainFall,n);
    
    return 0;
}
