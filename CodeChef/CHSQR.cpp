#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int a[402];

void func(int n)
{
    for(int i=n;i>1;i--)
        swap(a[i],a[i-1]);
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			a[i]=n-i+1;
        int k=n;
		while(k--)
		{
			for(int i=1;i<=n;++i)
			printf("%d ",a[i]);
			printf("\n");
			func(n);
		}
		memset(a,0,sizeof(a));
	}
	return 0;
}
