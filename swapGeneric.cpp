#include<iostream>
using namespace std;

//Specific Function
void Swap(char*p, char*q)
{
    char temp;
    
    temp=*p;
    *p=*q;
    *q=temp;
    
}

//Generic Function

template<class T>
void SwapX(T *p, T *q)
{
    T temp;
    
    temp=*p;
    *p=*q;
    *q=temp;
    
}

int main()
{
    char X='\0', Y='\0';
    
    cout<<"Enter First Character\n";
    cin>>X;
    
    cout<<"Enter Second Character\n";
    cin>>Y;
    
    SwapX(&X, &Y);
    
    cout<<"Value of X become:"<<X<<"\n";
    cout<<"Value of Y become:"<<Y<<"\n";
    
    return 0;
}