#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int No)
{
    PNODE newn=NULL;
    
    newn= (PNODE)malloc(sizeof(NODE));
    
    newn->data=No;
    newn-> next= NULL;
    
    if(*Head==NULL)
    {
        *Head=newn;
    }
    else
    {
        newn->next= *Head;
        *Head=newn;
    }
    
}

void Display(PNODE Head)
{
    while(Head!= NULL)
    {
        printf("|%d|->", Head-> data);
        Head= Head->next;
    }
    printf("\n");
}

void DisplayR(PNODE Head)
{
    if(Head!= NULL)
    {
        printf("|%d|->", Head-> data);
        Head= Head->next;
        DisplayR(Head);
    }
    printf("\n");
}

int Count(PNODE Head)
{
    int iCnt=0;
    
    while(Head!= NULL)
    {
        iCnt++;
        Head= Head->next;
    }
    return iCnt;
}

int CountR(PNODE Head)
{
    static int iCnt=0;
    
    if(Head!= NULL)
    {
        iCnt++;
        Head= Head->next;
        CountR(Head);
    }
    return iCnt;
}

int main()
{
    PNODE first=NULL;
    int iRet=0;
    
    
    InsertFirst(&first,10);
    InsertFirst(&first,20);
    InsertFirst(&first,30);
    
    DisplayR(first);
   
    iRet= CountR(first);
    printf("Number of elements are:%d\n", iRet);
    return 0;
}