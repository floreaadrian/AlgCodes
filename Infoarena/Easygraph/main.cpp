#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <string.h>
#include <cassert>
#include <set>

using namespace std;

const long long oo = 0x3f3f3f3f;

set<int> G[15005];
int n,m;
long long v[15005];
long long ans = -oo;
long long dp[15005];
bitset <15005> Used;

void DFs(const int &node) {
    if(Used[node])
        return;
    Used[node] = true;
    long long aux = 0;
    for(auto it: G[node]) {
        DFs(it);
        aux = max(aux, dp[it]); //cel mai mare nod vecin
    }
    dp[node] += aux; //crestem acel drum cu aux
    ans = max(ans,dp[node]); // maximul drumului
}

inline void Clear() {
    for(int i = 1 ; i <= n ; ++ i)
        G[i].clear();
    Used.reset();
    ans = -oo;
}

int main() {
    FILE *fin,*fout;
    fin = fopen("easygraph.in","r");
    fout = fopen("easygraph.out","w");
    int t;
    fscanf(fin,"%d",&t);
    while(t--) {
        fscanf(fin,"%d%d",&n,&m);
        for(int i = 1 ; i <= n ;  ++ i)
        fscanf(fin,"%lli",&v[i]);
        for(int i = 1 ; i <= m ; ++ i) {
        int x, y;
        fscanf(fin,"%d%d",&x,&y);
        if(G[x].find(y) == G[x].end())
            G[x].insert(y); //daca gasim ca y e ultimul nod vecin
        }
        for(int i = 1 ; i <= n ; ++ i)
            dp[i] = v[i]; //dp
        for(int i = 1 ; i <= n ; ++ i)
            if(!Used[i])
                DFs(i); //cam ca si la componente conexe
        fprintf(fout,"%lli\n",ans);
            Clear();
    }
    return 0;
}
