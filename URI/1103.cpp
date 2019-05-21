#include<iostream>

using namespace std;

int h1,m1,h2,m2,c;

int fa()
{
	if(h1==0)
	{
		if(h1==h2)
		{
			if(m1>m2)c=1440-m1-m2;
		    else
		    c=m2-m1;
		}else
		if(m1>m2)
		{
			c=((h2-1)*60)+60-m1+m2;
		}else
		if(m2>m1)
		{
			c=h2*60+m2-m1;
		}
		if(m2==m1)
		c=60*h2;
	}
	else
	if(h2==0)
	{
		if(m1>m2)
		{
			c=((23-h1)*60)+60-m1+m2;
		}
		else
		if(m2>m1)
		{
			c=(24-h2)*60+m2-m1;
		}else
		if(m1==m2)
		c=(24-h1)*60;
	}
	if(h1==h2)
	{
		if(m1>m2)c=1380+60-m1+m2;
		else
		c=m2-m1;
	}
	else
	if(h1<h2)
	{
		if(m1>m2)
		{
			c=(h2-h1-1)*60+60-m1+m2;
		}
		else
		if(m2>m1)
		{
			c=(h2-h1)*60+m2-m1;
		}
		if(m1==m2)
		c=(h2-h1)*60;
	}else
	if(h1>h2)
	{
		if(m1>m2)
		{
			c=(23-h1+h2)*60+60-m1+m2;
		}else
		if(m1<m2)
		c=(24-h1+h2)*60+m2-m1;
		else 
		if(m1==m2)
		c=(24-h1+h2)*60;
	}
	return c;
}

int main()
{
	bool ok=true;
	while(ok)
	{
		cin>>h1>>m1>>h2>>m2;
		if(h1==0 && h2==0 && m1==0 && m2==0)break;
		fa();
		cout<<c<<"\n";
	}
	return 0;
}
