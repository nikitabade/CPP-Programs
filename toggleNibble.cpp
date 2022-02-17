// Accept no. from user and toggle first 4 bits and last 4 bits (or toggle ist nibble and last nibble)
// to tally: give the no. which is result of previous no.   we get same no. which we give first

typedef unsigned int UNIT;
#include<iostream>
using namespace std;

        
UNIT ToggleBit(UNIT iNo)  
{
    UNIT iResult=0;
    UNIT  iMask= 0xF000000F;   // hexadecimal of 1111 is F
    
    
    iResult= iMask ^ iNo;
    
    return iResult;
    
}
int main()
{
    UNIT iValue=0;
    UNIT iRet=0;
    
    cout<<"enter the number\n";
    cin>>iValue;
    
    iRet= ToggleBit(iValue);
    
    cout<<"Updated number:"<<iRet<<"\n";
    
    return 0;
}