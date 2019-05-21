#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

struct cord{
	int x;
	int y;
	int yy;
	int xx;
};

int main() {
	int n;
	scanf("%d",&n);
	struct cord dp[n+1];
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&dp[i].x,&dp[i].y,&dp[i].yy,&dp[i].xx);
	}
	long long h[n], v[n];
	long long l = 0;
	long long k = 0;
	for(int i=1;i<=n;i++){
		if(dp[i].x == dp[i].yy)
			v[l++] = i;
		else
			h[k++] = i;
	}
	long long ans[n+1];
	memset(ans,0,sizeof(ans));
	long long ctr = 0;
	for(int i=0;i<k;i++){
		for(int j=0;j<l;j++){
			if( dp[v[j]].y < dp[h[i]].y && dp[v[j]].xx > dp[h[i]].y){
				ans[h[i]] += 1;
				ans[v[j]] += 1;
				ctr += 1;
			}
		}
	}
	printf("%lld\n",ctr);
	for(int i=1;i<=n;i++)
		printf("%lld ",ans[i]);
	return 0;
}
