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
//Accept string from the user and return the length

#include<iostream>
using namespace std;

int StrlenI(char *str)          //while
{
    int iCnt=0;
    
    while(*str != '\0')
    {
        iCnt++;
        str++;
    }
    return iCnt;
}

int StrlenR(char *str)         //recursion
{
    static int iCnt=0;
    
    if(*str != '\0')
    {
        iCnt++;
        str++;
        StrlenR(str);
    }
    return iCnt;
}

int main()
{

    char Arr[20];
    int iRet=0;
    
    cout<<"Enter the string\n";
    scanf("%[^'\n']s",Arr);
    
    iRet= StrlenR(Arr);
    
    cout<<"Length of string is:"<<iRet<<"\n";
    return 0;
}