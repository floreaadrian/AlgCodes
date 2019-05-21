#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include<algorithm>
 
using namespace std;
 
const int maxn = 50005;
const int oo = 0x3f3f3f3f;
 
int n, m, dist[maxn],maximul,viz[maxn];;
vector <pair<int, int> > g[maxn];
 
int bf(int start)
{
	queue<int> q;
    q.push(start);
    int i,j;
    memset(viz, 0, sizeof(viz));
    memset(dist,0, sizeof(dist));
    viz[start]=1;
    while(!q.empty())
    {
    	int nod=q.front();
    	q.pop();
    	int si=g[nod].size();
    	for(int i=0;i<si;i++){
    		if(viz[g[nod][i].first]==0){
    			viz[g[nod][i].first]=1;
    			dist[g[nod][i].first]=dist[nod]+g[nod][i].second;
    			q.push(g[nod][i].first);
			}
		}
	}
    return int(max_element(dist+1,dist+n+1)-dist);
}
 
int main() {
	long long nr,start,fin;
	cin>>nr;
	while(nr--)
	{
    cin >> n;
    for(int i = 1 ; i <= n-1 ; ++ i) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }
    start=bf(1);
    maximul=bf(start);
	memset(g, 0, sizeof(g));
    cout<<dist[maximul]<<"\n";
 	}
}
