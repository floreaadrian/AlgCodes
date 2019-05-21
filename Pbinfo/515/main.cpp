#include <iostream>
#include <algorithm>
using namespace std;
void citire(int A[], int &n)
{
	cin>>n;
	for(int i=1;i<=n;++i)
        cin>>A[i];
}
int sum_div(int n)
{
    int s=0;
    for(int d=1;d<=n;d++)
        if(n%d==0) s=s+d;
    return s;
}
void ordonare(int A[],int n)
{
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            {
                int suma=sum_div(A[i]),sumb=sum_div(A[j]);
                if(suma>sumb)
            {
                swap(A[i],A[j]);
            }else if(suma==sumb)
            {
                if(A[i]>A[j])
                swap(A[i],A[j]);
            }
            }
}
void afisare(int A[], int &n)
{
	for(int i=1;i<=n;++i)
      cout<<A[i]<<" ";
}
int main()
{
    int n,A[1001];
    citire(A,n);
    ordonare(A,n);
    afisare(A,n);
    return 0;
}
