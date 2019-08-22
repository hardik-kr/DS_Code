#include<iostream>
#include<algorithm>

using namespace std ;

class node
{
	int data ;
    int level ;
	node *lchild ;
	node *rchild ;
	public :
	
	node()
	{
		data=0 ;
        level= 0;
		lchild=NULL ;
		rchild=NULL ;
	}
	void setdata(int val)
	{
		data = val ;
	}
	int getdata()
	{
		return data ;
	}
	node *getlchild()
	{
		return lchild ;
	}
	node *getrchild()
	{
		return rchild ;
	}
	void setlchild(node *temp)
	{
		lchild=temp ;
	}
	void setrchild(node *temp)
	{
		rchild=temp ;
	}
    void setlevel(int lvl)
    {
        level=lvl ;
    }
    int getlevel()
    {
        return level ;
    }
};
class zz
{
	public :
	node *root ;
	zz()
	{
		root=NULL ;
	}
	void addnode(int);
	node * addnode(node *,int,int);
	void order(int);
	void inorder(node *);
	void preorder(node *);

};


void zz::addnode(int val)
{
	node *n=root ;
	root = addnode(n,val,0) ;	
}
node *zz::addnode(node *temp,int data,int l)
{	
	if(temp==NULL)
	{
		node *n=new node();
		n->setdata(data);
        n->setlevel(l+1);
		return n;
	}
	else
	{
        if(temp->getlevel()%2!=0)
        {    if(temp->getdata() < data )
            {   
                temp->setrchild(addnode(temp->getrchild(),data,temp->getlevel())) ;
            }
            else if(temp->getdata() > data)
            {
                temp->setlchild(addnode(temp->getlchild(),data,temp->getlevel()));
            }
        }
        else if(temp->getlevel()%2==0)
        {
            if(temp->getdata() < data)
            {
                temp->setlchild(addnode(temp->getlchild(),data,temp->getlevel())) ;
            }
            else if(temp->getdata() > data)
            {
                temp->setrchild(addnode(temp->getrchild(),data,temp->getlevel())) ;
            }
        }
    }		
}
void zz::order(int check)
{	
	node *temp=root ;
	if(root==NULL)
	{
		cout<<"\n\nTree is Empty" ;
	}
	else
	{
		if(check==1)
		{
			preorder(temp);
		}
		else if(check==2)
		{
			inorder(temp);
		}
	}
}
void zz::preorder(node *temp)
{
	if(temp!=NULL)
	{
		cout<<temp->getdata()<<endl;
		preorder(temp->getlchild()) ;
		preorder(temp->getrchild());
	}
}
void zz::inorder(node *temp)
{
	if(temp!=NULL)
	{
        inorder(temp->getlchild()) ;
		cout<<temp->getdata()<<endl;
		inorder(temp->getrchild());
	}
}
int main()
{
    zz z1 ;
    int data ;
    while(cin>>data)
    {
        z1.addnode(data);
    }
    z1.order(1); //pre
    cout<<endl ;
    z1.order(2);        //in

}