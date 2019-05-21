#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int arr[100005],n,m;
vector<int> adj[100005];

main()
{
	int t,x,y;
	scanf("%d",&t);
	while(t--){
		int ok=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)
		{
			adj[i].clear();
			arr[i]=-1;
		}
		for(int i=0;i<m;i++)
		{
            scanf("%d%d",&x,&y);
			adj[x].push_back(y);
		}
		for(int i=0;i<=n;i++)
		sort(adj[i].begin(),adj[i].end());
		if(adj[0].size()==0 or adj[0][0]!=1){
			ok=1;
		}
		else{
			arr[1]=1;
			int valore=2;
            for(int i=1;i<adj[0].size();i++)
			{
				arr[adj[0][i]]=valore++;
			}
			x=adj[0].size();
			for(int i=1;i<n;i++)
			{
				int size=adj[i].size();
				if(size==0 or adj[i][0]!=i+1){
						ok=1;
						break;
					}
				if(size==x){
					int count=0;
                    for(auto it: adj[i])
                    if(arr[it]==-1){
                        count++;
                        arr[it]=arr[i];
                    }
					if(count>1){
						ok=1;
						break;
					}
				}
				else if(size==x-1){
					int count=0;
                    for(auto it: adj[i])
                    if(arr[it]==-1){
                        count++;
                        arr[it]=arr[i];
                    }
					if(count>0){
						ok=1;
						break;
					}
					x--;
				}
				else {
					ok=1;
					break;
				}
				if(ok==1)break;
			}
		}
		if(ok==1)printf("-1\n");
		else {
			for(int i=1;i<=n;i++)
			printf("%d ",arr[i]);
			printf("\n");
		}
	}
}
