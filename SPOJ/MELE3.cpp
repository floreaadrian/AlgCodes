#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define Floor pair<int, int>
#define cost first
#define id second

vector<pair <int,int> > g[1010];
int vis[1010];
int n,m;

int wait_time(int from, int to, int ct){
    int dis = abs(from-to)*10, rem;
    if (from<to){
        rem = ct%dis;
        return (dis-rem)%dis;
    }
    else{
        return ct%dis;
    }
}

int dijkstra(){
    priority_queue< pair<int,int> , vector<pair <int,int> >, greater<pair <int,int> > > pq;
    memset(vis, 0, sizeof vis);
    pq.push(Floor(0,1));
    while(!pq.empty()){
        Floor f = pq.top();
        pq.pop();
        if (f.id==n)
            return f.cost;
        if (vis[f.id])
            continue;
        vis[f.id] = 1;
        for (int i=0;i<g[f.id].size();i++){
            pair <int,int> f1 = g[f.id][i];
            pq.push(Floor(f.cost+wait_time(f.id,f1.id,f.cost)+f1.cost,f1.id));
        }
    }
}

int main(){
    int x,y;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>x>>y;
        g[x].push_back(make_pair((y-x)*5,y));
        g[y].push_back(make_pair((y-x)*5,x));
    }
    cout<<dijkstra()<<"\n";
}
