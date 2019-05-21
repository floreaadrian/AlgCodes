#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int c=0,i;
	char s[100];
	cin>>s;
	for(i=0;i<=strlen(s);i++)
	{
		if(s[i]==57 || s[i]==72 || s[i]==82)
		{
			cout<<"YES";
			c=1;
			break;
		}
	}
	if(c!=1)
	cout<<"NO";
	return 0	;
}
