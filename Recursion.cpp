#include<iostream>
using namespace std;

void DisplayI()          //Iteration
{
    int iCnt=1;
    
    while(iCnt<=4)
    {
        cout<<"Marvellous\n";
        iCnt++;
    }
    cout<<"\n";
}

void DisplayR()                 //Recursion
{
   static int iCnt=1;          //static is imp
   
    if(iCnt<=4)
    {
        cout<<"Marvellous\n";
        iCnt++;
        DisplayR();
    }
    
}

int main()
{
    DisplayI();
    DisplayR();
    return 0;
}

