#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;++tt)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		long long a1=b-a,b1=d-c;
		if(b==c)a1+=2,b1+=2;
		long long r=(a1/2)*b1;
		cout<<r<<"\n";
	}
	return 0;
}
