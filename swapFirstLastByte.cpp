//Accept number from the user and swap first and last byte
typedef unsigned int UNIT;
#include<iostream>
using namespace std;

UNIT DisplayByte(UNIT iNo)  
{
    
    UNIT iMask= 0x00ffffff00;
    UNIT iTemp = iNo & iMask;
    
    UNIT Byte1= iNo<<24;
    UNIT Byte4= iNo>>24;
    
    UNIT iResult= iTemp | Byte1 | Byte4;
    
   return iResult;
}

int main()
{
    UNIT iValue=0, iRet=0;
  
    cout<<"enter the number\n";
    cin>>iValue;

   iRet= DisplayByte(iValue);
    
    cout<<"Updated number:"<<iRet<<"\n";
    
    return 0;
}
//////////////////////////////////////////////////////////////////////////////

//Accept number from the user and swab first and last byte
typedef unsigned int UNIT;
#include<iostream>
using namespace std;

UNIT DisplayByte(UNIT iNo)  
{
   return ((iNo & 0x00ffffff00) | (iNo<<24) | (iNo>>24));
}

int main()
{
    UNIT iValue=0, iRet=0;
  
    cout<<"enter the number\n";
    cin>>iValue;

   iRet= DisplayByte(iValue);
    
    cout<<"Updated number:"<<iRet<<"\n";
    
    return 0;
}
///////////////////////////////////////////////////////////////////////////