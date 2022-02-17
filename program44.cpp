//Accept number from the user and count the ON bits without using % and / operator
#include<iostream>
using namespace std;

int CountBit(int iNo)  
{
    int iMask=0x00000001;
    int iResult=0, i=0, iCnt=0;
    
    for(i=1; i<32; i++, iMask= iMask<<1)
    {
         if((iNo & iMask)==iMask)
         {
             iCnt++;
         }
    }
    
    return iCnt;

}

int main()
{
    int iValue=0, iRet=0;
    
    cout<<"enter the number\n";
    cin>>iValue;
    
    iRet= CountBit(iValue);
    
    cout<<"Number of ON bits:"<<iRet<<"\n";
    
    return 0;
}