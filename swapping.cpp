#include<iostream>
using namespace std;

void Swap(int*p, int*q)
{
    int temp;
    
    temp=*p;
    *p=*q;
    *q=temp;
    
}

int main()
{
    int X=0, Y=0;
    
    cout<<"Enter First number\n";
    cin>>X;
    
    cout<<"Enter Second number\n";
    cin>>Y;
    
    Swap(&X, &Y);
    
    cout<<"Value of X become:"<<X<<"\n";
    cout<<"Value of Y become:"<<Y<<"\n";
    
    return 0;
}