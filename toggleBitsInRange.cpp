// Accept no. from user and toggle bits in given range 
typedef unsigned int UNIT;
#include<iostream>
using namespace std;

        
UNIT ToggleRange(UNIT iNo, int iStart, int iEnd)  
{
    UNIT iResult=0;
    UNIT  iMask1= 0xFFFFFFFF,iMask2= 0xFFFFFFFF, iMask= 0;
    
    iMask1= iMask1<<(iStart-1);
    iMask2= iMask2>>(32-iEnd);
    
    iMask= iMask1 & iMask2;
    
    iResult= iMask ^ iNo;
    
    return iResult;
}

int main()
{
    UNIT iValue=0;
    UNIT iRet=0, i=0, j=0;
    
    cout<<"enter the number\n";
    cin>>iValue;
    
    cout<<"enter Starting position\n";
    cin>>i;
    
    cout<<"enter ending  position\n";
    cin>>j;
    
    iRet= ToggleRange(iValue, i, j);
    
    
    cout<<"Updated number:"<<iRet<<"\n";
    
    return 0;
}