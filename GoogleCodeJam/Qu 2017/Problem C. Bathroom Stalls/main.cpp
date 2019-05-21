#include <bits/stdc++.h>

using namespace std;

long long n,k;
pair<int,int> ans[1000005];

priority_queue<pair<int,int>> q;

int main(){

	int t;
	//freopen("C-small-2-attempt0.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&t);
	for(int tt=1;tt<=t;++tt){
		scanf("%lli%lli",&n,&k);
		pair <int,int> now = make_pair(n/2,(n-1)/2);
		int id=1;
        q.push(now);
        while(id<=k){
            pair<int,int> x=q.top();
            q.pop();
            ans[id++]=x;
            q.push(make_pair(x.first/2,(x.first-1)/2));
            q.push(make_pair(x.second/2,(x.second-1)/2));
        }
        while(!q.empty()) {
            q.pop();
        }
		printf("Case #%d: %d %d\n",tt,ans[k].first,ans[k].second);
	}
	return 0;
}
