#include<iostream>
using namespace std;
template<class T>  
class stack 
{
	int top ;
	T arr[1000] ;
	public:
	stack()
	{
		top=-1 ;
	}

	void push(T);
	T pop();
	void print();
	T st_top();
	int size(); 
};
template <class T> 
void stack<T>::push(T val)
{
	if(top==1000-1)
		cout<<"\nStack is Full";
	else
	{
		arr[++top]=val ;
	}
}
template <class T> 
T stack<T>::pop()
{
	if(top==-1)
	{
		cout<<"Stack is empty" ;
		return 0 ;
	}
	else
	{
		T val=arr[top--] ;
		return val ;
	}
}
template <class T> 
void stack<T>::print()
{
	if(top==-1)
		cout<<"NO elements ";
	else
	{
	for(int i=0 ; i<=top ; i++)
	       cout<<arr[i]<<" ";	
	}
}
template <class T> 
int stack<T>::size()
{
	return top+1 ;
}
template <class T> 
T stack<T>::st_top()
{
	return arr[top] ;
}