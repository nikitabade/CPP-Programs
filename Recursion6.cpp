//Accept string from the user and count the capital character

#include<iostream>
using namespace std;

int CountCapI(char *str)          //while
{
    int iCnt=0;
    
    while(*str != '\0')
    {
        if((*str>='A') && (*str<='Z'))
        {
            iCnt++;
        }    
        str++;
    }
    return iCnt;
}

int CountCapR(char *str)          //Recursion
{
    static int iCnt=0;
    
    if(*str != '\0')
    {
        if((*str>='A') && (*str<='Z'))
        {
            iCnt++;
        }    
        str++;
        
        CountCapR(str);
    }
    return iCnt;
}


int main()
{

    char Arr[20];
    int iRet=0;
    
    cout<<"Enter the string\n";
    scanf("%[^'\n']s",Arr);
    
    iRet= CountCapR(Arr);
    
    cout<<"Capital letters are:"<<iRet<<"\n";
    return 0;
}