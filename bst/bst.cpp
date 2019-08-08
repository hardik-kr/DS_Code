#include<iostream>
#include<algorithm>

using namespace std ;

class node
{
	int data ;
	node *lchild ;
	node *rchild ;
	node *parent ;
	public :
	
	node()
	{
		data=0 ;
		lchild=NULL ;
		rchild=NULL ;
		parent=NULL ;

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
	node *getparent()
	{
		return parent ;
	}
	void setlchild(node *temp)
	{
		lchild=temp ;
	}
	void setrchild(node *temp)
	{
		rchild=temp ;
	}
	void setparent(node *temp)
	{
		parent=temp ;
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
	void addnode(node *,int);
	bool search(int);
	node *search(node *,int);
	void delnode(int);
	int height();
	int height(node *);
	void order(int);
	void inorder(node *);
	void preorder(node *);
	void postorder(node *);
	void leafnode(node *,node *);
	void onechild(node *,node *);
	void bothchild(node *,node *);
};
void bst::addnode(int val)
{
	
	if(root==NULL)
	{	
		node *n=new node();
		n->setdata(val) ;
		root = n ;
	}
	else
	{
		node *temp = root ;
		addnode(temp,val) ;
	}	
}
void bst::addnode(node *temp,int data)
{	
	if(temp->getdata() < data)
	{
		if(temp->getrchild()!=NULL)
		addnode(temp->getrchild(),data);
		else
		{
			node *n=new node();
			temp->setrchild(n) ;
			n->setdata(data);
			n->setparent(temp);
		}
		
	}
	else
	{
		if(temp->getlchild()!=NULL)
		addnode(temp->getlchild(),data);
		else
		{
			node *n=new node();
			temp->setlchild(n);
			n->setdata(data);
			n->setparent(temp);
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
	height(temp);
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
		if(t2->getlchild()==NULL && t2->getrchild()==NULL)
		leafnode(t2,t2->getparent());
		else if(t2->getlchild()==NULL || t2->getrchild()==NULL)
		onechild(t2,t2->getparent());
		else
		bothchild(t2,t2->getparent());		
	}
}
void bst::leafnode(node *del,node *par)
{	
	if(par==NULL)
	{	root=NULL ;
		del=NULL ;
	}
	else if(del->getdata()>par->getdata())
	{
		par->setrchild(NULL) ;
		delete del ;
		del=NULL ;
	}
	else
	{
		par->setlchild(NULL) ;
		delete del ;
		del=NULL ;
	}
}
void bst::onechild(node *del,node *par)
{	node *pred=root,*succ=root ;
	if(par==NULL)
	{
		if(del->getlchild()==NULL)
		{	
			succ=succ->getrchild();
			while(succ->getlchild()!=NULL)
				succ=succ->getlchild();
			(succ->getparent())->setlchild(NULL) ;
			succ->setrchild(root->getrchild());
			delete root ;
			root = succ ;
			root->setparent(NULL);
		}
		else  //RightChild NULL
		{
			pred=pred->getlchild() ;
			while(pred->getrchild()!=NULL)
			(pred->getparent())->setrchild(NULL);
			pred->setlchild(root->getlchild());
			delete root ;
			root=pred ;
			root->setparent(NULL);
		}
	}
	else if(par->getdata()>del->getdata())
	{
		if(del->getlchild()==NULL)
		{
			par->setlchild(del->getrchild());
			delete del ;
			del=NULL ;
		}
		else
		{
			par->setlchild(del->getlchild());
			delete del ;
			del = NULL ;
		}
	}
	else
	{
		if(del->getlchild()==NULL)
		{
			par->setrchild(del->getrchild()) ;
			delete del ;
			del = NULL ;
		}
		else
		{
			par->setrchild(del->getlchild());
			delete del ;
			del = NULL ;
		}
		
	}
	
}
void bst::bothchild(node *del,node *par)
{	
	if(par==NULL)
	{	node *succ=root ;
		succ=succ->getrchild();
		while(succ->getlchild()!=NULL)
		{
			succ=succ->getlchild() ;
		}
		root->setdata(succ->getdata());
		(succ->getparent())->setlchild(NULL);
		delete succ ;
		succ=NULL ;
	}
	else 
	{
		node *nodesucc=del ;
		nodesucc=nodesucc->getrchild();
		while(nodesucc->getlchild()!=NULL)
		{
			nodesucc=nodesucc->getlchild() ;
		}
		del->setdata(nodesucc->getdata());
		if(nodesucc->getdata() < (nodesucc->getparent())->getdata())
		{
			(nodesucc->getparent())->setlchild(NULL);
			delete nodesucc ;
			nodesucc=NULL ;
		}
		else
		{
			(del->getparent())->setrchild(nodesucc->getrchild()) ;
			delete del ;
			del=NULL ;
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
