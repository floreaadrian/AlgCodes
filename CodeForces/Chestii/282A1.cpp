#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int x=0,i,n;
	char s[3];
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>s;
		if(s[1]=='+')
		x++;else x--;
	}
	cout<<x;
}
