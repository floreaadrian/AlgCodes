#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

const int maxk = 305;
const int oo = 0x3f3f3f3f;

int n, m, t, k, dist[maxk][maxk], dp[maxk][maxk];

int distanta(string a,string b)
{
	int n=a.size();
	int m=b.size();
	int i=0,j=0;
	while(i<n && j<m)
	{
		if(a[i]!=b[j])
		break;
		++i;
		++j;
	}
	return n+m-2*i;
}

int main()
{
	cin>>t;
	for(int tes=1;tes<=t;tes++)
	{
		cin>>n>>k;
		vector <string> v;
		memset(dp, oo, sizeof(dp));
		for(int i=1;i<=n;++i)
		{
			string x;
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		if(i!=j)
		dist[i][j]=distanta(v[i],v[j]);
		for(int i=1;i<=k;++i)
		for(int j=0;j<n;++j)
		{
			if(i == 1)
				dp[i][j] = int(v[j].size());
				else
				for(int k = 0 ; k < j ; ++ k)
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + dist[k][j]);
		}
		int ans=oo;
		for(int j = 0 ; j < n ; ++ j)
			ans = min(ans, dp[k][j] + int(v[j].size()));
		cout<<ans+k;
	}
	return 0;
}
