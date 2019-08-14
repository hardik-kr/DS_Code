#include<iostream>

using namespace std ;

class node
{
    int data ;
    node *next ;
    
    public :
    node()
    {
        data=0 ;
        next=NULL ;
    }
    void setdata(int val)
    {
        data = val ;
    }
    void setnext(node *n)
    {
        next = n ;
    }
    int getdata()
    {
        return data ;
    }
    node *getnext()
    {
        return next ;
    }
};
class CLL
{
    node *start ;
    int count();
    int shortDist(node *);

    public :
    CLL()
    {
        start=NULL ;
    }
    void create() ;
    void addBeg(int);
    void addEnd(int);
    bool search(int);   
    void display();
};

void CLL::create()
{
    node *N=new node();
    start=NULL ;
}
void CLL::addBeg(int val)
{
    if(start==NULL)
    {
        node *N=new node();
        N->setdata(val) ;
        N->setnext(N) ;
        start=N ;
    }
    else
    {   
        node *temp=start ;
        do
        {
            temp=temp->getnext() ;
        }while(temp->getnext()!=start);
        node *N=new node();
        N->setdata(val);
        N->setnext(start) ;
        temp->setnext(N) ;
        start=N ;
    }
    
}
void CLL::addEnd(int val)
{
    if(start==NULL)
    {
        node *N=new node();
        N->setdata(val) ;
        N->setnext(N) ;
        start=N ;
    }
    else
    {
        node *temp=start ;
        do
        {
            temp=temp->getnext() ;
        }while(temp->getnext()!=start);
        node *N=new node();
        N->setdata(val);
        temp->setnext(N);
        N->setnext(start);
    }
    
}
void CLL::display()
{
    node *temp=start ;
    do
    {
        cout<<temp->getdata()<<" ";
        temp=temp->getnext() ;
    }while(temp!=start);   
} 
int CLL::count()
{
    int ct=0 ;
    node *temp=start ;
    do
    {
        ct++ ;
        temp=temp->getnext() ;
    }while(temp!=start);
    return ct ;
}
bool CLL::search(int val)
{
    node *temp=start ;
    
    if(temp==NULL)
    {
        return false ;
    }
    else
    {     
        do
        {
            if(temp->getdata()==val)
            {  
                cout<<"\n"<<shortDist(temp);
                return true;
            }
            else
            {   
                temp=temp->getnext() ;
            }
        }while(temp!=start);     
    }
    return false ;
}
int CLL::shortDist(node *temp)
{
    int ct1=0,ct2=0 ;
    node *temp2=start ;
    while(temp2!=temp)
    {
        ct1++ ;
        temp2=temp2->getnext();
    }
    while(temp!=start)
    {
        ct2++ ;
        temp=temp->getnext();
    }
    return min(ct1,ct2) ;
}

int main()
{
    CLL c1 ;
    int choice,data,pos ;
    while(cin>>choice)
    {
       
        switch (choice)
        {
        case 1 :    c1.create();
                    //cout<<"Success Creation ";
                    break;
        case 2 :    //cout<<"\nEnter data : ";
                    cin>>data ;
                    c1.addBeg(data);
                    break ;
        case 3 :    //cout<<"\nEnter data : ";
                    cin>>data ;
                    c1.addEnd(data);
                    break ;
        case 4 :    //cout<<"\nSearch : ";
                    cin>>data ;
                    if(!c1.search(data))
                    {
                        cout<<"-1" ;
                    }
                   
                    break ;
                    
        case 5 :    c1.display();
                    break ;

        case 6 :    exit(0) ;
                    break ;
        default:    cout<<"Wrong choice";
                    break;
        }

    }
    return 0;
}


