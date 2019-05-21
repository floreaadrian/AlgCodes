#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char s[100],t[100];
	int l;
	cin>>s;
	cin>>t;
	
	if(((s[0]-96)%2==0 && (t[0]-96)&2==0) || ((s[0]-96)%2==0 && (t[0]-96)%2!=0) || ((s[0]-96)%2!=0 && (t[0]-96)%2==0))
	{
		l=((s[0]-96)+(t[0]-96))/2;
		for(int i=0;i<strlen(s);++i)
		{
			cout<<s[i]+l;
		}
	}
	else
	if(s[0]==t[0])
	cout<<"No such string";
	return 0;
}
