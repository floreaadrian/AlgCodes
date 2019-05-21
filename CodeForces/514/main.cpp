#include<iostream>

using namespace std;

int x[1000];
int y[1000];

int main()
{
  int res=0;
  int i,j,n,a,b;
  cin>>n>>a>>b;
  for(i=0;i<n;i++)
  {
    cin>>x[i]>>y[i];
    x[i]-=a;
    y[i]-=b;
    for(j=0;j<i;j++)
        if(x[i]*y[j]==x[j]*y[i])break;
    if(j==i)res++;
  }
  cout<<res;
}
