//Accept number from user and perform the addition of its digits

#include<iostream>
using namespace std;

/*int DigitAdditionI(int iNo)
{
    int iSum=0;
    
    while(iNo!=0)
    {
        iSum= iSum+(iNo%10);
        iNo= iNo/10;
    }
    
    return iSum;
}
*/
int DigitAdditionR(int iNo)
{
    static int iSum=0;
    
    if(iNo!=0)
    {
        iSum= iSum+(iNo%10);
        iNo= iNo/10;
        
        DigitAdditionR(iNo);
    }
    
    return iSum;
}

int main()
{
    int x=0, iRet=0;
    
    cout<<"Enter the number\n";
    cin>>x;
    
    //iRet=DigitAdditionI(x);
    
    //cout<<"Addition of digits is:"<<iRet<<"\n";
    
    iRet=DigitAdditionR(x);
    
    cout<<"Addition of digits is:"<<iRet<<"\n";
    return 0;
}