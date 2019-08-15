#include<iostream>
#include<algorithm>

using namespace std ;

class node
{
    int data ;
    node *left ;
    node *right ;
    public :
    node()
    {
        data = 0 ;
        left = NULL ;
        right = NULL ;
    }
    void setLeft(node *n)
    {
        left = n ;
    }
    void setRight(node *n)
    {
        right = n ;
    }
    void setData(int val)
    {
        data = val ;
    }
    node *getLeft()
    {
        return left ;   
    }
    node *getRight()
    {
        return right ;   
    }
    int getdata()
    {
        return data ;
    }
};

class dll
{
    public :
    node *start ;
    dll()
    {
        start = NULL ;
    }
    void create();
    bool addBeg(int);
    bool addPos(int,int);
    bool addEnd(int);
    bool search(int);
    void deleteBeg();
    void deletePos(int);
    void deleteEnd();
    void traverse();
    int countNode();
};
void dll::create()
{
    node *N = new node();
    start=NULL ;
}
bool dll::addBeg(int val)
{
    if(start==NULL)
    {
        node *N=new node();
        N->setData(val);
        start=N ;
    }
    else
    {
        node *N=new node();
        N->setData(val);
        N->setLeft(start);
        start->setRight(N) ;
        start=N ;
    }
    return true ;
}
bool dll::addEnd(int val)
{
    if(start==NULL)
    {
        node *N=new node();
        N->setData(val);
        start=N ;
    }
    else
    {   node *temp=start ;
        node *N=new node();
        N->setData(val);
        while(temp->getLeft()!=NULL)
        temp=temp->getLeft();
        N->setRight(temp);
        temp->setLeft(N) ;
        N->setLeft(NULL);
    }
    return true ;
}
bool dll::addPos(int val,int pos)
{
    node *temp=start ;
    if(pos==1)
    addBeg(val);
    else if(pos>countNode()+1)
    {
        cout<<"Not Possible  ";
        return false ;
    }
    else if(pos==countNode()+1)
    addEnd(val);
    else
    {   
        node *N=new node();
        pos--;
        while(--pos)
        {
            temp=temp->getLeft();
        }        
        N->setData(val);
        (temp->getLeft())->setRight(N);
        N->setLeft(temp->getLeft());
        N->setRight(temp);
        temp->setLeft(N);
    }
}
int dll::countNode()
{
    int ct=0 ;
    node *temp=start ;
    while(temp)
    {
        ct++ ;
        temp=temp->getLeft();
    }
    return ct ;
}
void dll::traverse()
{
    node *temp=start ;
    cout<<"\nList is : ";
    while (temp!=NULL)
    {
        cout<<temp->getdata()<<" ";
        temp=temp->getLeft();
    }
}
void dll::deleteBeg()
{
    node *N=start ;
    start=start->getLeft();
    start->setRight(NULL);
    delete N ;
    N=NULL ;
}
void dll::deleteEnd()
{
    node *N=start ;
    while(N->getLeft()!=NULL)
    {
        N=N->getLeft();
    }
    (N->getRight())->setLeft(NULL);
    delete N;
    N=NULL ;
}
void dll::deletePos(int pos)
{
    node *N=start ;
    if(pos==1)
    deleteBeg();
    else if(pos==countNode()+1)
    deleteEnd();
    else
    {
        while(--pos)
        {
            N=N->getLeft();
        } 
        (N->getLeft())->setRight(N->getRight());
        (N->getRight())->setLeft(N->getLeft());
        delete N ;
        N=NULL ;
    }
}

int main()
{
    dll d1 ;
    int choice,data,pos ;
    while(1)
    {
        cout<<"\n1. Create\n2. Add Beg\n3. Add Pos\n4. Add End\n5. Delete Beg\n6. Delete Pos\n7. Delete End\n8. Traverse\n9. Exit\n";
        cout<<"Choice----> : ";
        cin>>choice ;
        switch (choice)
        {
        case 1 :    d1.create();
                    cout<<"Success Creation ";                    
                    break;
        case 2 :    cout<<"\nEnter data : ";
                    cin>>data ;
                    d1.addBeg(data);
                    break ;
        case 3 :    cout<<"\nEnter data & pos: ";
                    cin>>data>>pos ;
                    d1.addPos(data,pos);
                    break ;
        case 4 :    cout<<"\nEnter data : ";
                    cin>>data ;
                    d1.addEnd(data);
                    break ;
        case 5 :    d1.deleteBeg();
                    break ;
        case 6 :    cout<<"\nEnter pos : ";
                    cin>>pos ;
                    d1.deletePos(pos);
                    break ;
        case 7 :    d1.deleteEnd();
                    break ;
        case 8 :    d1.traverse();
                    break ;
        case 9 :    exit(0) ;
                    break ;
        default:    cout<<"Wrong choice";
                    break;
        }

    }
    return 0;
}