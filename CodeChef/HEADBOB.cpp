#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	int t,n,i,j=1;
	char c[1001];
	cin>>t;
	for(int f=1;f<=t;++f)
	{
		cin>>n;
		cin>>c;
		j=1;
		for(i=0;i<n;i++)
		{
			if(c[i]!='N')
			{
				if(c[i]=='Y')
				j=2;
				else
				if(c[i]=='I')
				j=3;
			}
		}
		if(j==1)cout<<"NOT SURE\n";
		if(j==2)cout<<"NOT INDIAN\n";
		if(j==3)cout<<"INDIAN\n";
	}
	return 0;
}
