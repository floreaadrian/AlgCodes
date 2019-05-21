#include<iostream>
using namespace std;
int main()
{
	int j,i,t,x,y,s;
	cin>>t;
	for(j=1;j<=t;j++)
	{
		cin>>x>>y;
		s=0;
		if(x%2!=0)
		{
		y=(y*2)+x;
		for(i=x;i<y;i+=2)
		s+=i;
	    }else
	    {
	    	x++;
	    	y=(y*2)+x;
	    	for(i=x;i<y;i+=2)
	    	s+=i;
		}
		cout<<s<<"\n";
	}
	return 0;
}
