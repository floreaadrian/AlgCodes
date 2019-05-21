#include<iostream>

using namespace std;

int x1,x2,y1,y2;

bool ok(int x1,int y1,int x2,int y2)
{
	if((x2-x1)==(y2-y1))return 1;
	if((x2-x1)==(y1-y2))return 1;
	if((x1-x2)==(y2-y1))return 1;
	if((x1-x2)==(y1-y2))return 1;
	if((x2==x1 && y1!=y2) || (y1==y2 && x1!=x2))return 1;
	return 0;
}

void fa()
{
	int c=1;
	if(x1==x2 && y1==y2) cout<<0<<"\n";
		else
		if(ok(x1,y1,x2,y2))
		{
			cout<<1<<"\n";
		}
		else 
		{
		while(!ok(x1,y1,x2,y2))
		{   
		    if(x1==8 || y1!=8)
		    y1++;
		    else
			x1++;
			c++;
		}
		cout<<c<<"\n";
	    }
}

int main()
{
	cin>>x1>>y1>>x2>>y2;
	while(x1!=0 && y1!=0 && x2!=0 && y2!=0)
	{
		fa();
		cin>>x1>>y1>>x2>>y2;
	}
	return 0;
}
