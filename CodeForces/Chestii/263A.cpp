#include<iostream>
using namespace std;
int a[5][5];
int main()
{
	int n=0,j,i,l,c,k=0;
	for(i=1;i<=5;++i)
	for(j=1;j<=5;++j)
	{
		cin>>a[i][j];
		if(a[i][j]==1)
		{
			l=i;c=j;
		}
	}
	if(l<=3 && c<=3)
	n=3-l+3-c;else
    if(l<=3 && c>=3)
	n=3-l+c-3;else
	if(l>=3 && c<=3) 
	n=l-3+3-l;else
	if(l>=3 && c>=3)
	n=l-3+c-3;
	cout<<n;
}
