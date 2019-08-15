#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data ;
    struct node *next ;
}*start=NULL;
void add(int val)
{
    struct node *temp ;
    if(start==NULL)
    {
        temp=(struct node *)malloc(sizeof(struct node)) ;
        temp->data =val ;  
        temp->next=temp ;
        start=temp ;     
    }
    else
    {
        struct node *temp=start,*new ;
        do
        {
            temp=temp->next ;
        }
        while(temp->next!=start);
        new=(struct node *)malloc(sizeof(struct node)) ;
        temp->next=new ;
        new->data=val ;
        new->next=start ;
    
    }
    
}
void del(struct node *d)
{
struct node *d1=start ;
if(d!=start)   
{  
   while(d1->next!=d) 
   {
       d1=d1->next ; ;
       
   } 
   d1->next=d->next ;
   free(d) ;
   d=NULL;
}
else
{
   struct node *d1=start,*d2=start ;
   do
   {
       d1=d1->next ;
   } while(d1->next!=start);
    start=start->next ;
    d1->next = start ;
    free(d2);
    d2=NULL ;
}
}
void display(struct node *temp)
{
  do
  {
    printf("%d ",temp->data);
    temp=temp->next ;
  } while (temp!=start); 
}
int count()
{    
        int ct=0;
       struct node *temp=start;
        do
        {
            ct=ct+1;
            temp=temp->next ;
        }while(temp!=start) ;
        return ct;
}
int startpos(int m,int o)
{
    int x=o ;

    struct node *temp=start,*store ;
    while(--m)
    {
        temp=temp->next ;
    }
    
    while(count()!=1)
    {   
        while(x--)
        {
            store=temp ;
            temp=store->next ;

        }
        
    
        del(temp) ;
        x=o ;
        temp=store ;
    }
    return start->data ;
    

}
void main()
{
    int i,n,m,o,x,t;
    //scanf("%d",&t);
    //while(t--)
    {
        scanf("%d %d %d",&n,&m,&o);
        for(i=1;i<=n;i++)
        {
            add(i);
        }
        x=startpos(m,o) ;
        printf("\n%d",x);
    }
}