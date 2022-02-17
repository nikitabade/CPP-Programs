// write the program which accept number from user and print even factors of that number
#include<iostream>
using namespace std;

class Factors
{
    
    public:
        
    void DisplayFactor(int iNo)
    {
        
    	int i=0;
	
	    if(iNo<0)
	    {
		    iNo=-iNo;
	    }
	
	    for(i=1; i<iNo; i++)
	    {
		    if(((iNo%i)==0) && ((i%2)==0))
		    {
			    printf("%d\t",i);
		    }
	    }
    }
};

int main()
{
    Factors obj;
    
	int iValue=0;

	cout<<"enter the number\n";
	cin>>iValue;
	
	obj.DisplayFactor(iValue);
	return 0;
}
