//stack Generic

#include<iostream>
using namespace std;

template<class T6>
struct node6
{
    T6 data;
    struct node6 * next;
};

template<typename T6>
class Stack          //Singly Linear LL
{
    private:
    node6<T6>* first;
    int size;
    
    public:
    Stack();
    void push(T6);
    int pop();
    void Display();
    int Count();
    
    
};


template<class T6>
Stack<T6>::Stack()
{
    first= NULL;
    size=0;
}
    
    
template<class T6>
void Stack<T6>::push(T6 no)    //Insert first
{
    node6<T6>* newn= new node6<T6>;     
        
    newn-> data=no;
    newn-> next= NULL;
        
    if(first==NULL)
    {
        first= newn;
    }
    else
    {
        newn-> next=first;
        first=newn;
    }
        
    size++;
}
    
    
template<class T6>
int Stack<T6>::pop()
{
    node6<T6>* temp= first;
    int no=0;
        
    if(first==NULL)     //OR (size==0)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    if(first->next==NULL)   //OR (size==1)
    {
        no= first->data;
        delete first;
        first=NULL;
    }
    else
    {
        no= first->data;
        first= first->next;
        delete temp;
    }
    size--;
    return no;
}
    
    
template<class T6>
void Stack<T6>::Display()
{
    node6<T6>* temp= first;
        
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|"<<"\n";
        temp= temp-> next;
    }
    cout<<"\n";
}


int main()
{
    Stack <int>obj;
    int iRet=0;
    
    obj.push(11);
    obj.push(21);
    obj.push(51);
    obj.push(101);
    
    cout<<"elements of stack are:\n";
    obj.Display();
     
    iRet=obj.Count();
    cout<<"size of Stack is:"<<iRet<<"\n";
    
    
    iRet= obj.pop();
    cout<<"poped element is:"<<iRet<<"\n";
    
    cout<<"elements of stack are:\n";
    obj.Display();
    
    iRet=obj.Count();
    cout<<"size of Stack is:"<<iRet<<"\n";
    
    return 0;
}