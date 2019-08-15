#include<iostream>
#define MAX 5 
using namespace std ;
 
class stack
{
	int top ;
	int arr[MAX] ;
	public :
	stack()
	{
		top=-1 ;
	}
	void push(int);
	int pop();
	void print();
	int size(); 
};
void stack::push(int val)
{
	if(top==MAX-1)
		cout<<"\nStack is Full";
	else
	{
		arr[++top]=val ;
	}
}
int stack::pop()
{
	if(top==-1)
	{
		cout<<"Stack is empty" ;
		return 0 ;
	}
	else
	{
		int val=arr[top--] ;
		return val ;
	}
}
void stack::print()
{
	if(top==-1)
		cout<<"NO elements ";
	else
	{
	for(int i=0 ; i<=top ; i++)
	       cout<<arr[i]<<" ";	
	}
}
int stack::size()
{
	return top+1 ;
}
int main()
{ 
	stack s ;
	char ch;
	int choice,data ;
	do{
	system("clear");
	cout<<"\n1. Push\n2. Pop\n3. Print\n4. Size of Stack\n5. Exit------>";
	cin>>choice ;
	switch(choice)
	{
		case 1 : cout<<"\nPush Data : ";
			 cin>>data ;
			 s.push(data);
			 break ;
		case 2 : cout<<"\nPop data is : "<<s.pop() ;
			 break ;
		case 3 : cout<<"\nElements are as follows : ";
			 s.print() ;
			 break ;
		case 4 : cout<<"Size is :"<<s.size() ;
			 break ;
		case 5 : exit(0) ;
		default : cout<<"\nWrong Choice ";
	}
	}
	while(1);
	
	return 0 ;

}







