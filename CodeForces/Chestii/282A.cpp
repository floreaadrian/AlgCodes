#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int x=0,i,n;
char s[10];
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>s;
		if(s[0] == '+')
            x++;
        if(s[0] == '-')
            x--;
        if(s[2] == '+')
            x++;
        if(s[2] == '-')
            x--;
	}
	cout<<x;
}
