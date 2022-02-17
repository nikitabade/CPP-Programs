//Binary Search Tree

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node* lChild;
    struct node* rChild;
}NODE, *PNODE, **PPNODE;

void Insert(PPNODE head, int no)
{
    PNODE newn= new NODE;
    
    newn-> data= no;
    newn-> lChild= NULL;
    newn-> rChild= NULL;
    
    if(*head==NULL)
    {
        *head= newn;
    }
    else
    {
        PNODE temp= *head;
        
        while(1)       //Unconditional loop     1 for TRUE      for( ; ; )
        {
            if(temp->data==no)
            {
                cout<<"Doublicate node\n";
                
                delete newn;
                break;
            }
            else if(no < (temp->data))     //if data is small
            {
                if(temp->lChild==NULL)
                {
                    temp->lChild= newn;
                    break;
                }
                
                temp= temp->lChild;
                
            }
            else if(no > (temp->data))       //if data is large
            {
                if(temp->rChild==NULL)
                {
                    temp->rChild= newn;
                    break;
                }
                
                temp= temp->rChild;
            }
        }
    }
    
}

bool Search(PNODE head, int no)
{
    
    
    if(head==NULL)        //if tree is empty
    {
        return false;
    }
    else              //tree contains atleast one node
    {
        while(head!=NULL)
        {
            if(head->data==no)        //node sapdla
            {
               
                break;
            }
            else if(no > (head->data))
            {
                head= head->rChild;
            }
            else if(no < (head->data))
            {
                head= head->lChild;
            }
            
        }
        
        if(head==NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}


void Display(PNODE head)
{
    
}

int main()
{
    PNODE first=NULL;
    bool bRet= false;
    int no=0;
    
    
    Insert(&first,51);
    Insert(&first,21);
    Insert(&first,101);
    Insert(&first,55);
    
    Display(first);
    
    cout<<"Enter the number which we have to search\n";
    cin>>no;
    
    bRet=Search(first,no);
    if(bRet==true)
    {
        cout<<"Data is there\n";
    }
    else
    {
        cout<<"Data is not there\n";
    }
    
    return 0;
}

