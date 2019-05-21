#include <stdio.h>
#include <vector>

using namespace std;

const int mod = 666013;
const int oo = 0x3f3f3f3f;

int n, s, v[1000005];
vector <int> g[1000005], _hash[2*mod];

inline void _insert(int value) {
    int key = value % mod + mod;
    _hash[key].push_back(value);
}

inline void _erase(int value) {
    int key = value % mod + mod;
    for(vector <int> :: iterator it = _hash[key].begin() ; it != _hash[key].end() ; ++ it)
        if(*it == value) {
            _hash[key].erase(it);
            return ;
        }
}

inline int _count(int value) {
    int key = value % mod + mod, ret = 0;
    for(auto it: _hash[key])
        if(it == value)
            ++ ret;
    return ret;
}

long long ans = 0;

inline void dfs(int node, int sum) {
    ans += _count(sum - s);
    _insert(sum);
    for(auto it: g[node])
        dfs(it, sum + v[it]);
    _erase(sum);
}

int main() {
    freopen("arbore3.in","r",stdin);
    freopen("arbore3.out","w",stdout);
    scanf("%d%d",&n,&s);
    for(int i = 1 ; i <= n ; ++ i) {
        int x;
        scanf("%d%d",&x,&v[i]);
        g[x].push_back(i);
    }
    _insert(0);
    dfs(1, v[1]);
    printf("%lli\n",ans);
    return 0;
}
