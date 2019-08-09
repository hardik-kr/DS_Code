#include<iostream>
#include<algorithm>

using namespace std ;

class node
{
	int data ;
    int height ;
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
        height=0 ;

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
    void setheight(int ht)
    {
        height=ht ;
    }
    int getheight()
    {
        return height ;
    }
	
};
class AVL
{
    node *root ;
    
    //PRIVATE member function
    node *addnode(node *,int);
    node *search(node *,int);
    int height(node *);
    void inorder(node *);
	void preorder(node *);
	void postorder(node *);
    int bal_fact(node *);
    node *delnode(node *,int);

    public :
    AVL()
    {
        root=NULL ;
    }
    void addnode(int);
    //bool search(int);
    //void delnode(int);
    //int height();   
    void order(int);

};

void AVL::addnode(int data)
{
    node *temp=root ;
    root = addnode(temp,data);
}
node *AVL::addnode(node *temp,int data)
{
    if(temp==NULL)
    {
        node *N=new node();
        N->setdata(data);
        return N ;
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
        
    }
    
}
void AVL::order(int check)
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
void AVL::inorder(node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->getlchild()) ;
		cout<<temp->getdata()<<" ";
		inorder(temp->getrchild());
	}
}
void AVL::preorder(node *temp)
{
	if(temp!=NULL)
	{
		cout<<temp->getdata()<<" ";
		preorder(temp->getlchild()) ;
		preorder(temp->getrchild());
	}
}
void AVL::postorder(node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->getlchild()) ;
		postorder(temp->getrchild());
		cout<<temp->getdata()<<" ";
	}
}


int main()
{
    AVL a1 ;
    int choice,data ;
    
    while (1)
    {
        cout<<"\n\n1. AddNode\n2. SearchNode\n3. DelNode\n4. Height\n5. Inorder\n6. Preorder\n7. Postorder\n8. Exit\nEnter Choice----> ";
	    cin>>choice ;

        switch (choice)
        {
        case 1 :    cout<<"\nEnter Data : ";
		    		cin>>data ;
			    	a1.addnode(data);
				    break;
	    case 2 :	cout<<"Enter node value fro search : ";
		    		cin>>data ;
			    /*/	if(a1.search(data)) 
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
			    	a1.delnode(data);
				    break;
	    case 4 :	cout<<"Height is : "<<a1.height();
		    		break;*/
	    case 5 : 	cout<<"InOrder is : ";
	    			a1.order(1) ;
		    		break;
	    case 6 :	cout<<"PreOrder is : ";
		    		a1.order(2) ;
			    	break;
	    case 7 :	cout<<"PostOrder is : ";
		    		a1.order(3) ;
			    	break;	
	    case 8 : 	cout<<"Exit" ;
		    		exit(0) ;
	    default:    cout<<"Wrong choice";
				    break;
        }
    }
    
	
}