#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	string a,b;
	while(t--)
	{
		cin>>a>>b;
		int mi=0,pl=0;
		int a1[26]={0};
		int b1[26]={0};
		bool ok=false;
		int n=a.length();
		for(int i=0;i<n;i++)
		{
			if(a[i]!=b[i])
			mi++;
			else
			pl++;
			a1[a[i]-97]++;
			b1[b[i]-97]++;
		}
		if(pl==n)
		{
			printf("B\n");
			continue;
		}
		else
		{
			for(int i=0;i<26;i++)
			{
				if(a1[i]>=2 and b1[i]==0)
				ok=true;

			}
		if(ok)
		printf("A\n");
		else
		printf("B\n");
		}
	}
	return 0;
}
