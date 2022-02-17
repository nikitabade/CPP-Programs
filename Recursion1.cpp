#include<iostream>
using namespace std;

void DisplayI(int iNo)          //Iteration
{
    int iCnt=1;
    
    while(iCnt<=iNo)
    {
        cout<<"Marvellous\n";
        iCnt++;
    }
    cout<<"\n";
}

void DisplayR(int iNo)                 //Recursion
{
    static int iCnt=1;
    
    if(iCnt<=iNo)
    {
        cout<<"Marvellous\n";
        iCnt++;
        DisplayR(iNo);
    }
    cout<<"\n";
    
}

int main()
{
   int iValue=0;
   
    cout<<"Enter the number\n";
    cin>>iValue;
    DisplayI(iValue);
    DisplayR(iValue);
    return 0;
}