#include <fstream>
#include <queue>
#include <vector>
#include <string.h>
#include <bitset>

using namespace std;

ifstream fin("dragoni.in");
ofstream fout("dragoni.out");

const int maxn = 805;
const int oo = 0x3f3f3f3f;

int p, n, m, dmax[maxn], dp[maxn][maxn];
vector <pair<int, int> > g[maxn];
bitset <maxn> used;

inline void first()
{
    int lim=dmax[1];
    int ans=dmax[1];
    queue <int> q;
    q.push(1);
    while(!q.empty()){
        int nod=q.front();
        q.pop();
        ans=max(ans,dmax[nod]);
        for(vector <pair <int,int> > ::iterator it=g[nod].begin();it!=g[nod].end();++it)
        if(!used[it->first] && it->second <= lim){
            used[it->first]=true;
            q.push(it->first);
        }
    }
    fout<<ans<<"\n";
}

void second(){
    priority_queue <pair<int,pair<int,int> > > q;
    memset(dp,oo,sizeof(dp));
    dp[1][1]=0;
    q.push(make_pair(0, make_pair(1, 1)));
    while(!q.empty()) {
        int cost = -q.top().first;
        int node = q.top().second.first;
        int dragon = q.top().second.second;
        q.pop();
        if(dp[node][dragon] != cost)
            continue;
        if(node == n) {
            fout << cost << '\n';
            return ;
        }
        for(vector <pair<int, int> > :: iterator it = g[node].begin() ; it != g[node].end() ; ++ it) {
            if(dp[it->first][dragon] > cost + it->second && it->second <= dmax[dragon]) {
                dp[it->first][dragon] = cost + it->second;
                dp[it->first][it->first] = cost + it->second;
                q.push(make_pair(-dp[it->first][dragon], make_pair(it->first, dragon)));
                q.push(make_pair(-dp[it->first][it->first], make_pair(it->first, it->first)));
            }
        }
    }
}

int main()
{
    fin>>p>>n>>m;
    for(int i=1;i<=n;++i)
        fin>>dmax[i];
    for(int i=1;i<=m;++i){
        int x,y,z;
        fin>>x>>y>>z;
        g[x].push_back(make_pair(y,z));
        g[y].push_back(make_pair(x,z));
    }
    if(p==1)first();
    else second();
    return 0;
}
