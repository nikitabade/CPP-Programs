//singly circular LL

#include<iostream>
using namespace std;


template<class T>
struct node
{
    T data;
    struct node* next;
};

template<typename T>
class SinglyCL
{
    private:
        node<T>* first;
        node<T>* last;
        int size;
    
    public:
        SinglyCL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();

};

        template<class T>
        SinglyCL<T>::SinglyCL()
        {
            first=NULL;
            last=NULL;
            size=0;
        }
        
        
        template<class T>
        void SinglyCL<T>::InsertFirst(T no)
        {
            node<T>* newn= new node<T>;
            
            newn-> data=no;
            newn-> next= NULL;
            
            if((first==NULL) && (last==NULL))           //OR if(size==0)
            {
                first=newn;
                last=newn;
            }
            else
            {
                newn-> next=first;
                first= newn;
            }
            last->next=first;
            size++;
        }
        
        
        template<class T>
        void SinglyCL<T>::InsertLast(T no)
        {
            node<T>* newn= new node<T>;
            
            newn-> data=no;
            newn-> next= NULL;
            
            if((first==NULL) && (last==NULL))           //OR if(size==0)
            {
                first=newn;
                last=newn;
            }
            else
            {
                last->next=newn;
                last=newn;
                
            }
            
            last->next=first;
            size++;
        }
        
        
        template<class T>
        void SinglyCL<T>::InsertAtPos(T no, int ipos)
        {
            node<T>* temp= first;
           
            
            if((ipos<1) || (ipos>(size+1)))      //invalid position
            {
                return;
            }
            
            if(ipos==1)
            {
                InsertFirst(no);
            }
            else if(ipos==size+1)
            {
                InsertLast(no);
            }
            else
            {
                node<T>* newn= new node<T>;
                
                newn-> data=no;
                newn-> next=NULL;
                
                for(int i=1; i<ipos-1; i++)
                {
                    temp= temp->next;
                }
                newn->next=temp->next;
                temp->next=newn;
                size++;
                
            }
            
        }
        
        
        template<class T>
        void SinglyCL<T>::DeleteFirst()
        {
            if((first==NULL) && (last==NULL))     //OR if(size==0)
            {
                return;
            }
            else if(first==last)      // OR if(size==1)
            {
                delete first;
                first=NULL;
                last=NULL;
                
            }
            else
            {
                first= first->next;
                delete last->next;
                last->next=first;
            }
            size--;
        }
        
        
        template<class T>
        void SinglyCL<T>::DeleteLast()
        {
            node<T>* temp=first;
            
            if((first==NULL) && (last==NULL))     //OR if(size==0)
            {
                return;
            }
            else if(first==last)      // OR if(size==1)
            {
                delete first;
                first=NULL;
                last=NULL;
                
            }
            else
            {
                while(temp->next!=last)
                {
                    temp= temp->next;
                }
                delete last;
                last=temp;
                last->next=first;
                
            }
            size--;
        }
        
        
        template<class T>
        void SinglyCL<T>::DeleteAtPos(int ipos)
        {
             node<T>* temp= first;
             node<T>* targeted=temp->next;
            
            if((ipos<1) || (ipos>(size+1)))      //invalid position
            {
                return;
            }
            
            if(ipos==1)
            {
                DeleteFirst();
            }
            else if(ipos==size)
            {
                DeleteLast();
            }
            else
            {
               
                for(int i=1; i<ipos-1; i++)
                {
                    temp= temp->next;
                }
                temp->next=targeted->next;    // temp->next=temp->next->next;
                delete targeted;
                
                size--;
                
            }
        }
        
        template<class T>    
        void SinglyCL<T>::Display()
        {
            node<T>* temp=first;
            
            if((first==NULL) && (last==NULL))
            {
                return;
            }
            
            do
            {
                cout<<"|"<<temp->data<<"|-> ";
                temp= temp->next;
            
            }while(temp != last->next);
            
            cout<<"\n";
        }
        
        template<class T>
        int SinglyCL<T>::Count()
        {
            return size;
        }




int main()
{
    SinglyCL <int>obj;
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