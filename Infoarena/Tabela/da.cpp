#include<iostream>
using namespace std;
int main()
{
	int l,c,a[20000][2000],i,j;
	cin>>l>>c;
	for(i=1;i<=l;i++)
	for(j=1;j<=c;j++)
	{
		if(i==j)
		a[i][j]=1;
	}
	cout<<a[l][c];
	return 0;
}
