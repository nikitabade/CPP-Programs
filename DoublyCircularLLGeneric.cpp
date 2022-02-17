
//Doubly Circular LL

#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node * prev;
    struct node* next;
    
};

template<typename T>
class DoublyCL
{
    private:
        node<T>* first;
        node<T>* last;
        int Size;
    
    public:
        DoublyCL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
        
};

//return_value class_Name :: Function_Name(Parameters)

template<class T>
DoublyCL<T>::DoublyCL()
{
    first= NULL;
    last= NULL;
    Size=0;
}


template<class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    node<T>* newn= new node<T> ;
    
    newn-> data=no;
    newn->prev=NULL;
    newn->next=NULL;
    
    if((first==NULL) && (last==NULL))
    {
        first=newn;
        last=newn;
    }
    else 
    {
        newn->next= first;
        first->prev=newn;
        first= newn;
    }
    
    last->next= first;
    first-> prev=last;
    Size++;
}


template<class T>
void DoublyCL<T> :: InsertLast(T no)
{
    node<T>* newn= new node<T> ;
    
    newn-> data=no;
    newn->prev=NULL;
    newn->next=NULL;
    
    if((first==NULL) && (last==NULL))
    {
        first=newn;
        last=newn;
    }
    else 
    {
        last->next=newn;
        newn-> prev=last;
        last=newn;
        
    }
    
    last->next= first;
    first-> prev=last;
    Size++;
}


template<class T>
void DoublyCL<T> :: DeleteFirst()
{
    if((first==NULL) && (last==NULL))
    {
        return;
    }
    else if(first==last)
    {
        delete first;
        first=NULL;
        last=NULL;
    }
    else
    {
        first=first->next;
        delete first->prev;        // delete last->next;  
        
        last->next= first;
        first-> prev=last;
    }
    
    Size--;
   
}


template<class T>
void DoublyCL<T> :: DeleteLast()
{
    if((first==NULL) && (last==NULL))
    {
        return;
    }
    else if(first==last)
    {
        delete first;
        first=NULL;
        last=NULL;
    }
    else
    {
        last=last->prev;
        delete last->next;       //delete first->prev
         
        last->next= first;
        first-> prev=last;
       
    }
   
    Size--;
}


template<class T>
void DoublyCL<T> :: InsertAtPos(T no, int ipos)
{
    if((ipos<1) || (ipos>Size+1))
    {
        return;
    }
    
    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==Size+1)
    {
        InsertLast(no);
    }
    else
    {
        node<T>* newn= new node<T> ;
        
        newn-> data=no;
        newn->prev= NULL;
        newn->next=NULL;
        
        node<T>* temp= first;
        
        for(int i=1; i<ipos-1; i++)
        {
            temp= temp->next;
        }
        
        newn->next=temp->next;
        newn->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
        
        Size++;
    }
}


template<class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
    if((ipos<1) || (ipos>Size))
    {
        return;
    }
    
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==Size)
    {
        DeleteLast();
    }
    else
    {
        node<T>* temp= first;
        
        for(int i=1; i<ipos-1; i++)
        {
            temp= temp->next;
        }
        
        temp-> next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev= temp;
        Size--;
        
    }
    
}

template<class T>
void DoublyCL<T> :: Display()
{
    node<T>* temp=first;
    
    for(int i=1; i<=Size; i++)
    {
        cout<<"|"<<temp->data<<"|->";
        temp= temp->next;
    }
    cout<<"\n";
}


template<class T>
int DoublyCL<T> :: Count()
{
    return Size;
}

 
int main()
{
    DoublyCL <int>obj;
    int iChoice=1, value=0, iRet=0, pos=0;
    
    while(iChoice !=0)
    {
        cout<<"\n______________________________________________________"<<"\n";
        cout<<"Enter the desired operation that you want to perform on linkedlist"<<"\n";
        cout<<"1: Insert the node at first position"<<"\n";
        cout<<"2: Insert the node at last position"<<"\n";
        cout<<"3: Insert the node at desired position"<<"\n";
        cout<<"4: Delete the first node"<<"\n";
        cout<<"5: Delete the Last node"<<"\n";
        cout<<"6: Delete the node at desired position"<<"\n";
        cout<<"7: Display the contents of Linkeslist"<<"\n";
        cout<<"8: Count the number from the LL"<<"\n";
        cout<<"0: Terminate the application"<<"\n";
        cin>>iChoice;
        cout<<"\n____________________________________________________"<<"\n";
    
        switch(iChoice)
        {
            case 1:
            cout<<"Enter the data to insert"<<"\n";
            cin>>value;
            obj.InsertFirst(value);
            break;
            
            case 2:
            cout<<"Enter the data to insert"<<"\n";
            cin>>value;
            obj.InsertLast(value);
            break;
            
            case 3:
            cout<<"Enter the data to insert"<<"\n";
            cin>>value;
            cout<<"Enter the position"<<"\n";
            cin>>pos;
            obj.InsertAtPos(value,pos);
            break;
            
            case 4:
            obj.DeleteFirst();
            break;
            
            case 5:
            obj.DeleteLast();
            break;
            
            case 6:
            
            cout<<"Enter the position"<<"\n";
            cin>>pos;
            obj.DeleteAtPos(pos);
            break;
            
            case 7:
            cout<<"elements of Linkeslist are"<<"\n";
            obj.Display();
            break;
            
            case 8:
            iRet= obj.Count();
            cout<<"Number of elements are:"<<iRet<<"\n";
            break;
            
            case 0:
            cout<<"Thank you for using Linkeslist"<<"\n";
            break;
            
            default:
            cout<<"Wrong choice"<<"\n";
            break;
        
        }
    }
    return 0;
}