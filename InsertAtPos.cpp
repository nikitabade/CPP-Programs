#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node* next;
}NODE, *PNODE;

class SinglyLL
{
    private:
        PNODE first;
        int size;
        
    public:

        SinglyLL();
        void InsertAtPos(int No, int pos);
        void Display();
        int Count();
       
};

    SinglyLL::SinglyLL()
        {
            first=NULL;
            size=0;
        }
        
    void SinglyLL::InsertAtPos(int No, int pos)
    {
        PNODE newn= new NODE;
        PNODE temp= first;
        
        
        newn-> data= No;
        newn-> next= NULL;
        
        if((pos<1) || (pos>size+1))
        {
            cout<<"Invalid position\n";
            return ;
        }
        
        if(pos==1)
        {
            if(first==NULL)
            {
                first=newn;
            }
            else
            {
                newn-> next= first;
                first= newn;
            }
            
            
        }
        else if(pos==size+1)
        {
            if(first==NULL)
            {
                first=newn;
            }
            else
            {
                while(temp->next!=NULL)
                {
                    temp= temp->next;
                }
                
                temp->next= newn;
            }
           
        }
        else
        {
            for(int i=1; i<pos-1; i++)
            {
                temp= temp-> next;
            }
            newn->next=temp->next;
            temp->next= newn;
            
        }
        size++;
        
    }
    
    void SinglyLL:: Display()
    {
        while(first!= NULL)
        {
            cout<<"|"<<first->data<<"|"<<"->";
            first= first->next;
        }
        cout<<"\n";
    }
    
    int SinglyLL:: Count()
    {
        return size;
    }
    
    
int main()
{
    SinglyLL obj;
    int iRet=0;
    
    obj.InsertAtPos(10,1);
    obj.InsertAtPos(20,2);
    obj.InsertAtPos(40,3);
    obj.InsertAtPos(30,3);
    obj.InsertAtPos(50,5);
    obj.InsertAtPos(25,3);
    
    obj.Display();
    
    iRet= obj.Count();
    
    cout<<"Number of elements are:"<<iRet<<"\n";
    
    return 0;
}