//Singly linear LinkList (Generic)

#include<iostream>
using namespace std;

template<class T>          //template header
struct node
{
    T data;
    struct node * next;
};


template<typename T>
class SinglyLL
{
  private:
    node<T>* first;
    int size;
  
  public:
    SinglyLL();
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
    SinglyLL<T>::SinglyLL()
      {
        first= NULL;
        size=0;
      }
     
    template<class T>  
    void SinglyLL<T>::InsertFirst(T no)
    {
         node<T>* newn= new node<T> ;     //newn= (PNODE)malloc(sizeof(NODE))
        
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
    
    
    template<class T>
    void SinglyLL<T>::InsertLast(T no)
    {
         node<T>* newn= new node<T> ;     //newn= (PNODE)malloc(sizeof(NODE))
        
        newn-> data=no;
        newn-> next= NULL;
        
        if(first==NULL)
        {
            first= newn;
        }
        else
        {
            node<T>* temp= first;
           while(temp-> next!= NULL)
           {
               temp= temp-> next;
           }
           temp-> next= newn;
        }
        
        size++;
    }
    
    
    template<class T>
    void SinglyLL<T>::InsertAtPos(T no, int pos)
    {
         node<T>* newn=NULL;
         node<T>* temp= first;
        int i=0;
        
        if((pos<1) || (pos>size+1))
        {
            cout<<"Invalid position"<<"\n";
            return;
        }
        if(pos==1)
        {
            InsertFirst(no);
        }
        else if(pos==size+1)
        {
            InsertLast(no);
        }
        else
        {
             node<T>* newn= new node<T> ;
            
            newn->data= no;
            newn->next=NULL;
            
            for(i=1; i<pos-1; i++)
            {
                temp= temp->next;
            }
            
            newn->next=temp-> next;
            temp->next=newn;
            size++;
        }
    }
    
    
    template<class T>
    void SinglyLL<T>::DeleteFirst()
    {
         node<T>* temp= first;
        
        if(first!=NULL)
        {
            first= first-> next;
            delete temp;
            
            size--;
        }
    }
    
    
    template<class T>
    void SinglyLL<T>::DeleteLast()
    {
         node<T>* temp= first;
        
        if(first==NULL)
        {
            return;
        }
        else if(first->next==NULL)
        {
            delete first;
            first= NULL;
            size--;
        }
        else
        {
            while(temp-> next-> next!= NULL)
            {
                temp=temp-> next; 
            }
            
            delete temp-> next;
            temp-> next= NULL;
            size--;
            
        }
    }
    
    
    template<class T>
    void SinglyLL<T>::DeleteAtPos(int pos)
    {
         node<T>* temp= first;
         node<T>* targeted=NULL;
        int i=0;
        
        if((pos<1) || (pos>size))
        {
            cout<<"Invalid position"<<"\n";
            return;
        }
        if(pos==1)
        {
            DeleteFirst();
        }
        else if(pos==size)
        {
            DeleteLast();
        }
        else
        {
            
            for(i=1; i<pos-1; i++)
            {
                temp= temp->next;
            }
            
            targeted=temp->next;
            temp-> next=targeted->next;
            delete targeted;
            
            size--;
        }
    }
    
    
    template<class T>
    void SinglyLL<T>::Display()
    {
         node<T>* temp= first;
        
        while(temp!=NULL)
        {
            cout<<"|"<<temp->data<<"|->";
            temp= temp-> next;
        }
        cout<<"NULL\n";
    }
    
    
    template<class T>
    int SinglyLL<T>::Count()
    {
        return size;
    }
 

int main()
{
   
    int iChoiceDataType=1;
    
    
    while(iChoiceDataType!=0)
    {
        cout<<"\n______________________________________________________"<<"\n";
        cout<<"\nenter the data type for LL"<<"\n";
        cout<<"1: int"<<"\n";
        cout<<"2: float"<<"\n";
        cout<<"3: char"<<"\n";
        cout<<"4: double"<<"\n";
        cin>>iChoiceDataType;
        cout<<"\n______________________________________________________"<<"\n";
        
        switch(iChoiceDataType)
          {
            case 1:
            {

                   SinglyLL <int>obj;
                   int iChoice=1, iRet=0;
                   int ivalue=0, pos=0;
                   
                   
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
                            cin>>ivalue;
                            obj.InsertFirst(ivalue);
                            break;
                        
                            case 2:
                            cout<<"Enter the data to insert"<<"\n";
                            cin>>ivalue;
                            obj.InsertLast(ivalue);
                            break;
                        
                            case 3:
                            cout<<"Enter the data to insert"<<"\n";
                            cin>>ivalue;
                            cout<<"Enter the position"<<"\n";
                            cin>>pos;
                            obj.InsertAtPos(ivalue,pos);
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
            }
            break;
            
            case 2:
            {
                    SinglyLL <float>fobj;
                    int fChoice=1, fRet=0,  pos=0;
                    float fvalue=0;
                    
                    while(fChoice !=0)
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
                        cin>>fChoice;
                        cout<<"\n____________________________________________________"<<"\n";
            
                        switch(fChoice)
                        {
                            case 1:
                            cout<<"Enter the data to insert"<<"\n";
                            cin>>fvalue;
                            fobj.InsertFirst(fvalue);
                            break;
                        
                            case 2:
                            cout<<"Enter the data to insert"<<"\n";
                            cin>>fvalue;
                            fobj.InsertLast(fvalue);
                            break;
                        
                            case 3:
                            cout<<"Enter the data to insert"<<"\n";
                            cin>>fvalue;
                            cout<<"Enter the position"<<"\n";
                            cin>>pos;
                            fobj.InsertAtPos(fvalue,pos);
                            break;
                        
                            case 4:
                            fobj.DeleteFirst();
                            break;
                        
                            case 5:
                            fobj.DeleteLast();
                            break;
                        
                            case 6:
                            cout<<"Enter the position"<<"\n";
                            cin>>pos;
                            fobj.DeleteAtPos(pos);
                            break;
                        
                            case 7:
                            cout<<"elements of Linkeslist are"<<"\n";
                            fobj.Display();
                            break;
                        
                            case 8:
                            fRet= fobj.Count();
                            cout<<"Number of elements are:"<<fRet<<"\n";
                            break;
                        
                            case 0:
                            cout<<"Thank you for using Linkeslist"<<"\n";
                            break;
                        
                            default:
                            cout<<"Wrong choice"<<"\n";
                            break;
                        }    
                    }
            }
            break;
            
            case 3:
            {
          
                    SinglyLL <char>cobj;
                    int chChoice=1,   pos=0;
                    char cvalue='\0', cRet=0;
                    
                    while(chChoice !=0)
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
                        cin>>chChoice;
                        cout<<"\n____________________________________________________"<<"\n";
            
                        switch(chChoice)
                        {
                            case 1:
                            cout<<"Enter the data to insert"<<"\n";
                            cin>>cvalue;
                            cobj.InsertFirst(cvalue);
                            break;
                        
                            case 2:
                            cout<<"Enter the data to insert"<<"\n";
                            cin>>cvalue;
                            cobj.InsertLast(cvalue);
                            break;
                        
                            case 3:
                            cout<<"Enter the data to insert"<<"\n";
                            cin>>cvalue;
                            cout<<"Enter the position"<<"\n";
                            cin>>pos;
                            cobj.InsertAtPos(cvalue,pos);
                            break;
                        
                            case 4:
                            cobj.DeleteFirst();
                            break;
                        
                            case 5:
                            cobj.DeleteLast();
                            break;
                        
                            case 6:
                            cout<<"Enter the position"<<"\n";
                            cin>>pos;
                            cobj.DeleteAtPos(pos);
                            break;
                        
                            case 7:
                            cout<<"elements of Linkeslist are"<<"\n";
                            cobj.Display();
                            break;
                        
                            case 8:
                            cRet= cobj.Count();
                            cout<<"Number of elements are:"<<cRet<<"\n";
                            break;
                        
                            case 0:
                            cout<<"Thank you for using Linkeslist"<<"\n";
                            break;
                        
                            default:
                            cout<<"Wrong choice"<<"\n";
                            break;
                        }
                    }
            }    
            break;
            
            case 4:
            {
            
                    SinglyLL <double>dobj;
                    int dChoice=1, dRet=0,  pos=0;
                    double dvalue=0;
                    while(dChoice !=0)
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
                        cin>>dChoice;
                        cout<<"\n____________________________________________________"<<"\n";
            
                        switch(dChoice)
                        {
                            case 1:
                            cout<<"Enter the data to insert"<<"\n";
                            cin>>dvalue;
                            dobj.InsertFirst(dvalue);
                            break;
                        
                            case 2:
                            cout<<"Enter the data to insert"<<"\n";
                            cin>>dvalue;
                            dobj.InsertLast(dvalue);
                            break;
                        
                            case 3:
                            cout<<"Enter the data to insert"<<"\n";
                            cin>>dvalue;
                            cout<<"Enter the position"<<"\n";
                            cin>>pos;
                            dobj.InsertAtPos(dvalue,pos);
                            break;
                        
                            case 4:
                            dobj.DeleteFirst();
                            break;
                        
                            case 5:
                            dobj.DeleteLast();
                            break;
                        
                            case 6:
                            cout<<"Enter the position"<<"\n";
                            cin>>pos;
                            dobj.DeleteAtPos(pos);
                            break;
                        
                            case 7:
                            cout<<"elements of Linkeslist are"<<"\n";
                            dobj.Display();
                            break;
                        
                            case 8:
                            dRet= dobj.Count();
                            cout<<"Number of elements are:"<<dRet<<"\n";
                            break;
                        
                            case 0:
                            cout<<"Thank you for using Linkeslist"<<"\n";
                            break;
                        
                            default:
                            cout<<"Wrong choice"<<"\n";
                            break;
                        }
                    }
            }    
            
            break;
            
            default:
            {
                cout<<"wrong choice\n";
            }
            break;
    
          }
        
            
    }
}