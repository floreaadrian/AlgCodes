#include <iostream>
#include <stdio.h>

using namespace std;

int k[300005];

int main() {
	int a[300005],n;
	long long s=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
	    scanf("%d",&a[i]);
        if(i>2)k[i]=k[i-1]+(a[i]+a[i-1]+a[i-2])/(a[i]*a[i-1]*a[i-2]);
    }
	printf("%lli",s);
	return 0;
}
