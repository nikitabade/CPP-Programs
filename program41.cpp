
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
using namespace std;

class Marvellousfile
{
    public:
    char fname[30];
    int fd;
    
    Marvellousfile(char*Name) //constructer
    {
        strcpy(fname, Name);
        fd= open(fname,O_RDWR);
    }
    
    ~Marvellousfile()
    {
       close(fd);
    }
   
    void Display()
    {
       int iRet=0;
       char Buffer[10];
       lseek(fd,0,0);
       cout<<"data from the file is\n";
       
       while((iRet= read(fd, Buffer,10))!=0)
       {
           write(1, Buffer, iRet);
       }
    }
   
    int CountCapital()
    {
       int i=0, iRet=0, iCnt=0;
       char Buffer[10];
       lseek(fd,0,0);
       
         while((iRet= read(fd,Buffer,10))!=0)
         {
                 for(i=0; i<iRet; i++)
                 {
                     if((Buffer[i]>='A') && (Buffer[i]<='Z'))
                     {
                        iCnt++;
                     }
                 }
        }
        return iCnt;
    }
   
    int CountSmall()
    {
       int i=0, iRet=0, iCnt=0;
       char Buffer[10];
       lseek(fd,0,0);
       
         while((iRet= read(fd,Buffer,10))!=0)
         {
                 for(i=0; i<iRet; i++)
                 {
                     if((Buffer[i]>='a') && (Buffer[i]<='z'))
                     {
                        iCnt++;
                     }
                 }
        }
        return iCnt;
    }
   
    int CountDigit()
    {
       int i=0, iRet=0, iCnt=0;
       char Buffer[10];
       lseek(fd,0,0);
       
         while((iRet= read(fd,Buffer,10))!=0)
         {
                 for(i=0; i<iRet; i++)
                 {
                     if((Buffer[i]>='0') && (Buffer[i]<='9'))
                     {
                        iCnt++;
                     }
                 }
        }
        return iCnt;
    }
   
   
    int CountWhiteSpaces()
    {
       int i=0, iRet=0, iCnt=0;
       char Buffer[10];
       lseek(fd,0,0);
       
         while((iRet= read(fd,Buffer,10))!=0)
         {
                 for(i=0; i<iRet; i++)
                 {
                     if(Buffer[i]==' ')
                     {
                        iCnt++;
                     }
                 }
        }
        return iCnt;
    }
   
    int FileSize()
    {
        int iSize=0;
      
        fd=open(fname,O_RDWR);
    
        iSize= lseek(fd,0,2);
        return iSize;
    
    }
   
};

int main()
{
    char Name[30];
    int iCnt=0, iRet=0;

    cout<<"Enter the file name\n";
    cin>>Name;

     Marvellousfile obj(Name);
     
     obj.Display();
     
     iRet= obj.CountCapital();
     cout<<"Capital letters are\n:"<<iRet<<"\n";
     
     iRet= obj.CountSmall();
     cout<<"Small letters are\n:"<<iRet<<"\n";
     
     iRet= obj.CountDigit();
     cout<<"Digits are\n:"<<iRet<<"\n";
     
     iRet= obj.CountWhiteSpaces();
     cout<<"White spaces are\n:"<<iRet<<"\n";
     
     iRet= obj.FileSize();
     cout<<" file size is\n:"<<iRet<<"\n";
     
    return 0;
}