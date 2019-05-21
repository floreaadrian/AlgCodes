#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#define mp make_pair
using namespace std;

const int mod=1000000007;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		long long sum[100005];
		long long rez[100005];
		memset(rez,0,sizeof(rez));
		memset(sum,0,sizeof(sum));
		pair<int,int> p[100005];
		vector<int> a1,a2;
		for(int i=1;i<=m;i++)
		{
			int p1,x,y;
			scanf("%d %d %d",&p1,&x,&y);
			p[i]=mp(x,y);
			if(p1==1)
			a1.push_back(i);
			else
			a2.push_back(i);
			sum[i]=1;
		}
		int l=a2.size();
		for(int i=0;i<l;i++)
		{
			int s=l-1-i;
			int j=a2[l-2-i];
			for(int k=s;k<l;k++)
			{
				if(j>=p[a2[k]].first&&j<=p[a2[k]].second)
				{
					sum[j]+=sum[a2[k]];
				}
			}
		}
		int ll=a1.size();
		for(auto it1: a1)
		{
			int j=it1;
			for(auto it2: a2)
			{
				if(j>=p[it2].first && j<=p[it2].second)
				sum[j]=(sum[j]+sum[it2])%mod;
			}
			rez[p[j].first-1]=(rez[p[j]. first-1]+sum[j])%mod;
			if(p[j].second<n)
			rez[p[j].second]=(rez[p[j].second]-sum[j]+mod)%mod;
		}
		for(int i=1;i<n;i++)
		{
			rez[i]=(rez[i-1]+rez[i])%mod;
		}
		for(int i=0;i<n;i++){
		printf("%lld ",rez[i]);
	    }
		printf("\n");
	}
}
