#include<iostream>
#include<algorithm>
#define MAX 10

using namespace std ;

class stq
{
    int arr[MAX] ;
    int top ;
    int head ;
    int tail ;
    public :
    stq()
    {
        top=-1 ;
        head=-1 ;
        tail=-1 ;
    }
    void create(int);
    void addElement(int);
    void deleteElement();
    int count();
    void display();
};
void stq::create(int val)
{
        arr[++top]=val ;
        head++ ;  
        tail++ ; 
}
void stq::addElement(int val)
{
    if(top==MAX-1)
    cout<<"\nStack_Queue is full";
    else
    {
        arr[++top]=val ;
        head++ ;
    }    
}
void stq::deleteElement()
{   
    int del ;
    if(top==-1)
    cout<<"\nStack_Queue is empty" ;
    else if(tail==head)
    {   
        del=arr[head];
        tail=-1 ;
        head=-1 ;
        top =-1 ;
        cout<<"\nSUCCESS" ;
    }
    else
    {
        if(count()<4)
        {
            del=arr[top] ;
            top-- ;
            head-- ;
            cout<<"\nSUCCESS";
        }
        else
        {
            del=arr[tail];
            tail++ ;
            cout<<"\nSUCCESS" ;
        }
        
    }
}

void stq::display()
{   
    cout<<"\n";
    if(top==-1)
    {
        cout<<"\nStack_Queue is empty" ;
    }
    else
    {
        for(int i=tail ; i<=head ; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
}
int stq::count()
{
    int ct=0,i=tail ;
    while(i!=head)
    {
        ct++ ;
        i++ ;
    } 
    return ct ;
}


int main()
{
    stq sq ;
    int choice,val ;
    while(1)
    {
        cout<<"\n\n1. Create(For 1st element only)\n2. Add Element\n3. Delete Element\n4. Display Elements\n5. Exit\nChoice------->";
        cin>>choice ;
        switch(choice)
        {
            case 1 :    cout<<"\nEnter value : ";
                        cin>>val ;
                        sq.create(val);
                        break ;
            case 2 :    cout<<"\nEnter value : ";
                        cin>>val ;
                        sq.addElement(val);
                        break ;
            case 3 :    sq.deleteElement();
                        break ;
            case 4 :    sq.display() ;
                        break ;
            case 5 :    exit(0) ;
                        break ;
            default :   cout<<"\nWrong Choice" ; 
        }
    }
return 0;
}