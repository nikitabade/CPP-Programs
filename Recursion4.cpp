//Accept N number from user and return Addition of that numbers

#include<iostream>
using namespace std;

int SumF(int Arr[], int iSize)    //for loop
{
    int iSum=0, i=0;
    
    for(i=0; i<iSize; i++)
    {
        iSum= iSum+Arr[i];
    }
    
    return iSum;
    
}

int SumW(int Arr[], int iSize)          //while loop
{
    int iSum=0, i=0;
    
    while(i<iSize)
    {
        iSum=iSum+Arr[i];
        i++;
    }
    return iSum;
    
}

int SumR(int Arr[], int iSize)          //Recursion
{
    static int iSum=0, i=0;
   
    if(i<iSize)
    {
        iSum=iSum+Arr[i];
        i++;
        SumR(Arr, iSize);
    }
    return iSum;
}

int main()
{
   int iLength=0, i=0, iRet=0;
   int *p= NULL;
   
   cout<<"Number of elements\n";
   cin>>iLength;
   
   p=new int[iLength];
   
   cout<<"Enter the elements\n";
   
   for(i-0; i<iLength; i++)
   {
       cin>>p[i];
   }
   
   iRet= SumR(p,iLength);
   
   cout<<"Addition is:"<<iRet<<"\n";
   delete []p;
   
    return 0;
}
