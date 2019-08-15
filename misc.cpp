#include<iostream>
#include<string>
using namespace std ;

class student
{
	int roll ;
	string name ;
	int marks[5] ;
	public :
	student()
	{
		roll=0 ;
		name="No Name" ;
	}
	void StudInfo() ;
	float percentage() ;
	void printinfo() ;
};
void student::StudInfo()
{
	cout<<"Enter name : " ;
	cin>>ws ;
	getline(cin,name);
	cout<<"Enter Roll : ";
	cin>>roll ;
	cout<<"Enter marks of 5 subject : ";
	for(int i=0 ; i<5 ; i++)
		cin>>marks[i] ;
}
float student::percentage() 
{
	int sum=0 ;
	for(int i=0 ; i<5 ; i++)
		sum+=marks[i] ;
	return sum/5.0 ;
}
void student::printinfo()
{
	cout<<"\nName : "<<name ;
	cout<<"\t\tRoll : "<<roll ;
}
int main()
{
	student s1[5] ;
	int total ;	
	cout<<"\nEnter total no. of student : ";
	cin>>total ;
	for(int i=1 ; i<=total ; i++)
	{	
		cout<<"\nEnter Details of student "<<i<<"\n" ;
		s1[i].StudInfo() ;
	}	
        for(int i=1 ; i<=total ; i++)
        {	
		cout<<"\nStudent "<<i ;
                s1[i].printinfo() ;
		cout<<"\t\tPercentage : "<<s1[i].percentage() ;
        }
	cout<<"\n";
	return 0 ;
}

