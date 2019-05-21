#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 200005;

int n, m, father[maxn];

inline int find(int x) {
    if(father[x] != x)
        father[x] = find(father[x]);
    return father[x];
}

inline bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y)
        return false;
    father[x] = y;
    return true;
}

inline void kruskal() {
    vector <pair<int, pair<int, int> > > edges;
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; ++ i)
        father[i] = i;
    for(int i = 1 ; i <= m ; ++ i) {
        int x, y, z;
        scanf("%d%d%d",&x,&y,&z);
        edges.push_back(make_pair(z, make_pair(x, y)));
    }
    sort(edges.begin(), edges.end());
    int total = 0;
    for(int i = 0 ; i < edges.size() ; ++ i)
        if(unite(edges[i].second.first, edges[i].second.second))
            total += edges[i].first;
    printf("%d\n",total);
}

int main()
{
    kruskal();
    return 0;
}
