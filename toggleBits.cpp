// Accept 2 position from the user and toggle that 2 bits
#include<iostream>
using namespace std;

        
int ToggleBit(int iNo, int iPos1, int iPos2)  
{
    int iResult=0;
    int  iMask1= 0x00000001,  iMask2= 0x00000001,  iMask= 0;
    
    iMask1= iMask1<<iPos1-1;
    iMask2= iMask2<<iPos2-1;
    
    iMask= iMask1 | iMask2;
    
    iResult= iMask ^ iNo;
    
    return iResult;
    
}
int main()
{
    int iValue=0, iRet=0, i=0, j=0;
    
    cout<<"enter the number\n";
    cin>>iValue;
    
    cout<<"Enter the first position of bit\n";
    cin>>i;
    
     cout<<"Enter the Second position of bit\n";
    cin>>j;
    
    iRet= ToggleBit(iValue, i, j);
    
    cout<<"Updated number:"<<iRet<<"\n";
    
    return 0;
}