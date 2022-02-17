#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
}NODE, *PNODE;

class Stack          //Singly Linear LL
{
    private:
    PNODE first;
    int size;
    
    public:
    Stack()
    {
        first= NULL;
        size=0;
    }
    
    void push(int no)    //Insert first
    {
        PNODE newn= new NODE;     
        
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
    
    int pop()
    {
        PNODE temp= first;
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
    
    void Display()
    {
        PNODE temp= first;
        
        while(temp!=NULL)
        {
            cout<<"|"<<temp->data<<"|"<<"\n";
            temp= temp-> next;
        }
        cout<<"\n";
    }
    
    int Count()
    {
        return size;
    }

};

int main()
{
    Stack obj;
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