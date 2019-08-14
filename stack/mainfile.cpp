#include<iostream>
#include "stackapi.h"
#include<string>
using namespace std;
int main(){
    stack<char> s1;
    string exp ;
    cin>>exp ;
    cout<<"postfix is : " ;
    if(exp[0]!='(')
    {
        s1.push('(');
        exp=exp+')';
    }
    for(int i=0 ; i<exp.size() ; i++)
    {
        int asc=exp[i] ;
        if(exp[i]=='(')
        s1.push('(');
        else if(asc>= 65 && asc<=90 || asc>=97 && asc<=122)
        cout<<exp[i] ;
        else if(exp[i]=='+' || exp[i]=='-')
        {
            if(s1.st_top()=='(')
            s1.push(exp[i]);
            else if(s1.st_top()=='+' || s1.st_top()=='-')
            {
                while(s1.st_top()!='(')
                cout<<s1.pop() ;
                s1.push(exp[i]);
            }
            else if(s1.st_top()=='*' || s1.st_top()=='/' || s1.st_top()=='^')
            {
                while(s1.st_top()!='(')
                {
                    if(s1.st_top()=='(')
                    s1.pop() ;
                    else
                    {
                        cout<<s1.pop();
                    }
                }  
                s1.push(exp[i]);
            
            }
        }
        else if(exp[i]=='*' || exp[i]=='/')
        {
            if(s1.st_top()=='(')
            s1.push(exp[i]);
            else if(s1.st_top()=='+' || s1.st_top()=='-')
            {
                s1.push(exp[i]);
            }
            else if(s1.st_top()=='*' || s1.st_top()=='/' ||s1.st_top()=='^')
            {
                while(s1.st_top()!='(')
                cout<<s1.pop() ;
                s1.push(exp[i]);
            }
        }
        else if(exp[i]=='^')
        {
            if(s1.st_top()!='^')
            s1.push(exp[i]) ;
        }
        else if(exp[i]==')')
        {
            while(s1.st_top()!='(')
            cout<<s1.pop();
            s1.pop();
        }      
    }
    cout<<"\n" ;
    return 0;
}