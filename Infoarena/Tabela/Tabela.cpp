#include<iostream>
using namespace std;
int main()
{
	int l,c,i,j,a[2000000][2000000],ln=0,cn=0;
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
