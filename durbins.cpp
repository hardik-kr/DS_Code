#include<iostream>
void durbin(double R[],double a[],int p)
{
    double E[p+1],K[p+1],B[p+1][p+1];
    E[0]=R[0];
    for(int i=1 ; i<=p ; i++)
    {
        double temp = 0 ;
        for(int j=1 ; j<=i-1 ; j++)
        {
            temp+=B[j][i-1]*R[i-j];
        }
        K[i]=(R[i]-temp)/E[i-1] ;
        B[i][i]=K[i] ;
        for(int j=1 ; j<=i-1; j++)
        {
           B[j][i]=B[j][i-1]-K[i]*B[i-j][i-1] ;
        }
        E[i]=(1-K[i]*K[i])*E[i-1] ;
    }
    for(int i=1 ; i<=p ; i++)
    {
        a[i]=B[i][p] ;
    }
}
int main()
{
    int p=2;
    double R[p+1]={154,82,88};
    double a[p+1];
    durbin(R,a,p);
    
    for (size_t i = 1; i <= p ; i++)
    {
        std::cout<<a[i]<<" ";
    }
    return 0 ;

}