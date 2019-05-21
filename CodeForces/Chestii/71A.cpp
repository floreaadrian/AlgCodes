#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char sir[1001];
	int n,s;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>sir;
		s=strlen(sir);
		if(s>10)
		cout<<sir[0]<<s-2<<sir[s-1]<<"\n";
		else cout<<sir<<"\n";
	}
	return 0;
}
