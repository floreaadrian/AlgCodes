#include<iostream>

using namespace std;

char c;
int a[1000][1000];

int main()
{
	int i,j,a1=8,b1=8,a2,b2,in,c1;
	for(i=1;i<=8;i++)
	for(j=1;j<=8;j++)
	{
		cin>>c;
		if(c=='B')
		a[i][j]=1;
		else if(c=='W')
		a[i][j]=2;
	}
	for(j=1;j<=8;j++)
	{
	for(i=1;i<=8;i++)
	{
	a2=0;
	if(a[i][j]==2){
		in=i-1;
	while(a[in][j]==0 && in!=1)
	{
	a2++;
	in--;
	c1=1;
	}
	a2++;
	if(a2<a1 && c && i==1)
	a1=a2;
	}
	b2=0;
	if(a[i][j]==1){
		in=i+1;
		while(a[in][j]==0 && in!=8)
		{
			in++;
			b2++;
			c1=1;
		}
		b2++;
		if(b2<b1 && in==8 && c)
		b1=b2;
	}
	}
	}
	cout<<a1;
	if(b1<a1)
	cout<<"B";else
	cout<<"A";
	return 0;
}
