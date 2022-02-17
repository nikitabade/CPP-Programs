

//Accept two number from the user and display first number in second number of times 

#include<iostream>
using namespace std;

class Display
{
    public:
    
    void DisplayNum(int iNo, int iFrequency)
    {
	    int iCnt;
	    for(iCnt=1; iCnt<=iFrequency; iCnt++)
	    {
	    	printf("%d\t",iNo);
    	}
    }
};


int main()
{
    Display obj;
	int iValue = 0;
	int iCount = 0;
	
	cout<<"enter the number \n";
	cin>>iValue;
	
	cout<<"enter the frequency \n";
	cin>>iCount;
	
	obj.DisplayNum(iValue, iCount);
	
	return 0;
}