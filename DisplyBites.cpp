//Accept number from the user and display byte.
typedef unsigned int UNIT;
#include<iostream>
using namespace std;

        
void DisplayByte(UNIT iNo)  
{
   UNIT Byte1= iNo & 0x000000FF;
   
   UNIT Byte2= iNo & 0x0000FF00;
   Byte2= Byte2>>8;
   
    UNIT Byte3= iNo & 0x00FF0000;
    Byte3= Byte2>>16;
   
    UNIT Byte4= iNo & 0xFF000000;
    Byte4= Byte2>>24;
   
    cout<<"Byte1="<<Byte1<<"\n";
    cout<<"Byte2="<<Byte2<<"\n";
    cout<<"Byte3="<<Byte3<<"\n";
    cout<<"Byte4="<<Byte4<<"\n";
   
}

int main()
{
    UNIT iValue=0;
  
    cout<<"enter the number\n";
    cin>>iValue;

    DisplayByte(iValue);
    
    
    //cout<<"Updated number:"<<iRet<<"\n";
    
    return 0;
}