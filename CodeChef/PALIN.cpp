#include<stdio.h>
#include<string.h>
#include<iostream>

char c[100000009];

using namespace std;
 
int main()
{
	int i,j,k,l,t,x,s,f,m,n,car;
	cin>>t;
	while(t--)
	{
		cin>>c;
		f=0;
		for(i=0;i<strlen(c);i++)
		{
			if(c[i]!=9+48)
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			cout<<"1";
			for(i=0;i<strlen(c)-1;i++)
			{
				cout<<"0";
			}
			cout<<"1\n";
			continue;
		}
		k=strlen(c)/2;
		if(strlen(c)%2==0)
		{
			i=k-1;
			j=k;
		}
		else
		{
			i=j=k;
		}
		m=i;
		n=j;
		while(m>=0 && c[m]==c[n] && n<strlen(c))
		{
			m--;n++;
		}
		if(m==-1)
		{
			car=1;
			for(m=i;m>=0;m--)
			{
				s=c[m]-48+car;
				x=s%10;
				car=s/10;
				c[m]=x+48;
				/*if(!car)
				{
					break;
				}*/
			}
			m=0;
			for(n=strlen(c)-1;n>=j;n--)
			{
				c[n]=c[m++];
			}
			cout<<c<<"\n";
		}
		else if(c[m]>c[n])
		{
			while(m>=0)
			{
				c[n++]=c[m--];
			}
			cout<<c<<"\n";
		}
		else
		{
			car=1;
			m=i;
			while(m>=0)
			{
				s=c[m]-48+car;
				x=s%10;
				car=s/10;
				c[m]=x+48;
				m--;
			}
			m=0;
			n=strlen(c)-1;
			while(n>=j)
			{
				c[n--]=c[m++];
			}
			cout<<c<<"\n";
		}
	}
	return 0;
}
