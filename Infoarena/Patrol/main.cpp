#include <fstream>
#include <vector>
#include <bitset>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>

using namespace std;

ifstream fin("patrol.in");
ofstream fout("patrol.out");

const int MAXN = 1030;
const int MAXP = 520;
const int oo = 0x3f3f3f3f;

int N, M, P, T, cost[MAXN], L[MAXP], dp[MAXN][MAXP];
vector <int> G[MAXN];
vector <int> Path[MAXN], Enter[MAXN][MAXP];
bitset <MAXP> gardian[MAXN];

inline int cmmdc(int a, int b) {
    if(b == 0)
        return a;
    return cmmdc(b, a % b);
}

inline int cmmmc(int a, int b) {
    if(a == 0 || b == 0)
        return a * b;
    return a * b / cmmdc(a, b);
}

inline void Dijkstra() {
    priority_queue<pair<int, pair<int, int> >, vector <pair<int, pair<int, int> > > , greater <pair<int, pair<int, int> > > > Q;
    memset(dp, oo, sizeof(dp));
    Q.push(make_pair(cost[1], make_pair(1, 1)));
    dp[1][1] = cost[1];
    while(!Q.empty()) {
        int cst = Q.top().first;
        int Node = Q.top().second.first;
        int time = Q.top().second.second;
        Q.pop();
        if(dp[Node][time] < cst)
            continue;
        int newTime = time + 1;
        for(vector<int> :: iterator it = G[Node].begin(), fin = G[Node].end(); it != fin ; ++ it)
            if(dp[*it][newTime] > cst + cost[*it] && !gardian[*it][newTime]) {
                if(find(Enter[Node][newTime].begin(), Enter[Node][newTime].end(), *it) != Enter[Node][newTime].end())
                    continue;
                dp[*it][newTime] = cst + cost[*it];
                Q.push(make_pair(dp[*it][newTime], make_pair(*it, newTime)));
            }
    }
}

int main() {
    fin>>N>>M>>P;
    for(int i = 1 ; i <= N ; ++ i)
        fin>>cost[i];
    for(int i = 1 ; i <= M ; ++ i) {
        int x, y;
        fin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i = 1 ; i <= P ; ++ i) {
        int x;
        fin>>L[i];
        if(!T)
            T = 2 * L[i] - 2;
        else T = cmmmc(T, 2 * L[i] - 2);
        Path[i].push_back(0);
        for(int j = 1 ; j <= L[i] ; ++ j) {
            fin>>x;
            Path[i].push_back(x);
        }
    }
    for(int i = 1 ; i <= P ; ++ i) {
        vector <int> :: iterator it = Path[i].begin();
        int ok = 1;
        int k = 1;
        int last = 0;
        for(int j = 1 ; j <= T ; ++ j) {
            gardian[Path[i][k]][j] = 1;
            if(last)
                Enter[Path[i][k]][j].push_back(last);
            last = Path[i][k];
            k += ok;
            if(!(1 <= k && k <= L[i])) {
                k -= ok;
                ok *= -1;
                k += ok;
            }
        }
    }
    Dijkstra();
    int Ans = oo;
    if(!T)
        T = MAXP - 1;
    for(int i = 1 ; i <= T ; ++ i)
        Ans = min(Ans, dp[N][i]);
    fout<<Ans;
    return 0;
}
