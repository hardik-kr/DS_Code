#include<iostream>
#include<algorithm>

using namespace std ;

class node
{
	int data ;
	node *lchild ;
	node *rchild ;
	public :
	
	node()
	{
		data=0 ;
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
};
class bst
{
	public :
	node *root ;
	bst()
	{
		root=NULL ;
	}
	void addnode(int);
	node * addnode(node *,int);
	bool search(int);
	node *search(node *,int);
	void delnode(int);
	int height();
	int height(node *);
	void order(int);
	void inorder(node *);
	void preorder(node *);
	void postorder(node *);
	node *delnode(node *,int);
};
void bst::addnode(int val)
{
	node *n=root ;
	root = addnode(n,val) ;	
}
node *bst::addnode(node *temp,int data)
{	
	if(temp==NULL)
	{
		node *n=new node();
		n->setdata(data);
		return n;
	}
	else
	{
		if(temp->getdata() < data)
        {
            temp->setrchild(addnode(temp->getrchild(),data)) ;
        }
        else if(temp->getdata() > data)
        {
            temp->setlchild(addnode(temp->getlchild(),data));
        }
		else
		{
			cout<<"\nAlready Present ";
		}
	}	
}
void bst::order(int check)
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
			inorder(temp) ;
		}
		else if(check==2)
		{
			preorder(temp);
		}
		else
		postorder(temp);
	}
}
void bst::inorder(node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->getlchild()) ;
		cout<<temp->getdata()<<" ";
		inorder(temp->getrchild());
	}
}
void bst::preorder(node *temp)
{
	if(temp!=NULL)
	{
		cout<<temp->getdata()<<" ";
		preorder(temp->getlchild()) ;
		preorder(temp->getrchild());
	}
}
void bst::postorder(node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->getlchild()) ;
		postorder(temp->getrchild());
		cout<<temp->getdata()<<" ";
	}
}
int bst::height()
{
	node *temp=root ;
	return height(temp);
}
int bst::height(node *temp)
{
	int r,l ;
	if(temp==NULL ||(temp->getlchild()==NULL && temp->getrchild()==NULL))
	return 0 ;
	else 
	{
		r = height(temp->getrchild()) ;
		l = height(temp->getlchild()) ;
		return (max(r,l)+1) ; 
	}
}
bool bst::search(int data)
{
	node *temp=root ;
	if(search(temp,data))
	{
		return true ;
	}
	else
	{
		return false ;
	}	
}
node* bst::search(node *temp,int data)
{
	if(temp!=NULL)
	{
		if(temp->getdata()==data)
		return temp ;
		else if(temp->getdata() > data)
		{
			search(temp->getlchild(),data) ;
		}
		else
		{
			search(temp->getrchild(),data);
		}
	}
	else return NULL ;
}
void bst::delnode(int data)
{	node *temp=root,*t2 ;
	t2=search(temp,data) ;
	if(t2==NULL)
	{
		cout<<"Element not present in BST";
	}
	else
	{	
		root = delnode(root,data);
	}
}
node *bst::delnode(node *temp,int data)
{
	if(root==NULL)
	return root ;
	else if(data > temp->getdata())
	{
		temp->setrchild(delnode(temp->getrchild(),data));
	}
	else if(data < temp->getdata())
	{
		temp->setlchild(delnode(temp->getlchild(),data));
	}
	else
	{
		if(temp->getlchild()==NULL)
		{
			node *ret=temp->getrchild();
			free(temp);
			return ret ;
		}
		else if(temp->getrchild()==NULL)
		{
			node *ret=temp->getlchild();
			free(temp);
			return ret ;
		}
		else 
		{
			node *insucc = temp ;
			insucc=insucc->getrchild();
			while(insucc->getlchild()!=NULL)
			{
				insucc=insucc->getlchild();
			}
			temp->setdata(insucc->getdata());
			temp->setrchild(delnode(temp->getrchild(),temp->getdata()));
		}
	}
	
}
int main()
{
	bst b1 ;
	int choice,data ;
	do{
	cout<<"\n\n1. AddNode\n2. SearchNode\n3. DelNode\n4. Height\n5. Inorder\n6. Preorder\n7. Postorder\n8. Exit\nEnter Choice----> ";
	cin>>choice ;
	switch (choice)
	{
	case 1 :    cout<<"\nEnter Data : ";
				cin>>data ;
				b1.addnode(data);
				break;
	case 2 :	cout<<"Enter node value fro search : ";
				cin>>data ;
				if(b1.search(data)) 
				{
					cout<<"\nData Found ";
				}
				else
				{
					cout<<"\nNot Found" ;
				}
				break;
	case 3 :	cout<<"\n Delete Data ? : ";
				cin>>data ;
				b1.delnode(data);
				break;
	case 4 :	cout<<"Height is : "<<b1.height();
				break;
	case 5 : 	cout<<"InOrder is : ";
				b1.order(1) ;
				break;
	case 6 :	cout<<"PreOrder is : ";
				b1.order(2) ;
				break;
	case 7 :	cout<<"PostOrder is : ";
				b1.order(3) ;
				break;	
	case 8 : 	cout<<"Exit" ;
				exit(0) ;
	default:
				break;
	}
	}while(1) ;
	return 0 ;
}
