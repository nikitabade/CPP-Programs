//Queue Generic

#include<iostream>
using namespace std;


template<class T5> 
struct node5
{
    T5 data;
    struct node5 * next;
};

template<typename T5>
class Queue          //Singly Linear LL
{
    private:
    node5<T5>* first;
    int size;
    
    public:
    Queue();
    void Enqueue(T5);
    int Dequeue();
    void Display();
    int Count();
    
    
};


template<class T5> 
Queue<T5>::Queue()
{
    first= NULL;
    size=0;
}
    
    
template<class T5> 
void Queue<T5>::Enqueue(T5 no)
{
       
    node5<T5>* newn= new node5<T5>;    
        
    newn-> data=no;
    newn-> next= NULL;
        
    if(first==NULL)   //OR  if(size==0)
    {
        first= newn;
    }
    else
    {
        node5<T5>* temp= first;
        while(temp-> next!= NULL)
        {
            temp= temp-> next;
        }
           temp-> next= newn;
    }
        
    size++;
}
    
    
    
template<class T5> 
int Queue<T5>::Dequeue()
{
    node5<T5>* temp= first;
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
    
/*template<class T5>
void Queue<T5>::Display()
{
    node5<T5>* temp= first;
        
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|"<<"\n";
        temp= temp-> next;
    }
    cout<<"\n";
}*/
    
    
template<class T5> 
void Queue<T5>::Display()
{
    node5<T5>* temp=first;
    for(int i=1;  i<=size; i++, temp=temp->next)
    {
        cout<<"|"<<temp->data<<"|"<<"\n";
    }
    cout<<"\n";
}
    
    
template<class T5> 
int Queue<T5>::Count()
{
    return size;
}


int main()
{
    Queue <int>obj;
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

