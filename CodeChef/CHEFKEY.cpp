#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
	int mini,maxi,i,t,n,m,c;
	scanf("%d",&t);
	while(t--)
	{int cnt=0,a,b;
		scanf("%d%d%d",&n,&m,&c);
		mini=n<m?n:m;
		maxi=n>m?n:m;
		for(i=1;i<=sqrt(c);i++)
		{
			if(c%i!=0)continue;
			b=c/i;
		    if(i<=mini&&b<=maxi)
		    {
		    	cnt++;
		    	if(i<=maxi&&b<=mini&&i!=b)
		    	{cnt++;}
		    }
		}
		printf("%d\n",cnt);
	}
	return 0;
}
