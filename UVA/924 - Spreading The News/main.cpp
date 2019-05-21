#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define INF 5000
#define maxN 2505

int n, d[maxN], maxsize, firstday;
vector<int> adj[maxN];

void ReadInput() {
   int m, v;
   cin>>n;
   for(int i=0;i<n;++i) {
       cin>>m;
      while (m--) {
         cin>>v;
         adj[i].push_back(v);
      }
   }
}

void BFS(int u) {
   for(int i=0;i<=n;++i) d[i] = INF;
   queue <int> q;
   q.push(u); d[u] = 0;
   while (!q.empty()) {
      u = q.front(); q.pop();
      for (int i=0; i<adj[u].size(); i++) {
         int v = adj[u][i];
         if (d[v]==INF) {
            d[v] = d[u]+1;
            q.push(v);
         }
      }
   }
}

main() {
   int m, u;
   ReadInput();
   cin>>m;
   while (m--) {
      cin>>u;
      if (adj[u].size()>0) {
         BFS(u);
         maxsize = 0; firstday = -1;
         sort(d, d+n);
         int len = 1;
         for(int i=1;i<=n;++i)
            if (d[i-1]==d[i]) len++;
            else {
               if (d[i-1]!=INF && len>maxsize) {
                  maxsize = len;
                  firstday = d[i-1];
               }
               len = 1;
            }
         if (firstday==0) firstday++;
         cout<<maxsize<<" "<<firstday<<"\n";
      }
      else cout<<"0\n";
   }
}
