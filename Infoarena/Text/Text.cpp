#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char s[1000];
	int k=0,b=1,i,t;
	cin.getline(s,1000);
	t=strlen(s);
	for(i=0;i<=t;i++)
	{
		if((s[i]>='a' & s[i]<='z') || (s[i]>='A' & s[i]<='Z'))
		k++;
		if(s[i]==' ')
		b++;
	}
	cout<<k/b;
	
	return 0;
}
