//Queue

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
}NODE, *PNODE;

class Queue          //Singly Linear LL
{
    private:
    PNODE first;
    int size;
    
    public:
    Queue()
    {
        first= NULL;
        size=0;
    }
    
    void Enqueue(int no)
    {
       
        PNODE newn= new NODE;    
        
        newn-> data=no;
        newn-> next= NULL;
        
        if(first==NULL)   //OR  if(size==0)
        {
            first= newn;
        }
        else
        {
           PNODE temp= first;
           while(temp-> next!= NULL)
           {
               temp= temp-> next;
           }
           temp-> next= newn;
        }
        
        size++;
    }
    
    int Dequeue()
    {
        PNODE temp= first;
        int no=0;
        
        if(first==NULL)     //OR (size==0)
        {
            cout<<"Queue is empty\n";
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
    
    /*void Display()
    {
        PNODE temp= first;
        
        while(temp!=NULL)
        {
            cout<<"|"<<temp->data<<"|"<<"\n";
            temp= temp-> next;
        }
        cout<<"\n";
    }*/
    
    void Display()
    {
        PNODE temp=first;
        for(int i=1;  i<=size; i++, temp=temp->next)
        {
             cout<<"|"<<temp->data<<"|"<<"\n";
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
    Queue obj;
    int iRet=0;
    
    obj.Enqueue(11);
    obj.Enqueue(21);
    obj.Enqueue(51);
    obj.Enqueue(101);
    
    obj.Display();
    
    iRet=obj.Count();
    cout<<"size of Queue is:"<<iRet<<"\n";
    
    iRet= obj.Dequeue();
    cout<<"Removed element from queue is:"<<iRet<<"\n";
    
    obj.Display();
    
    iRet=obj.Count();
    cout<<"size of Queue is:"<<iRet<<"\n";
    
    return 0;
    
}