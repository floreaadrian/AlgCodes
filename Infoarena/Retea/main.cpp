#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <string.h>
#include <iomanip>

using namespace std;

ifstream fin("retea.in");
ofstream fout("retea.out");

const int MAXN = 1005;
const int MAXK = 12;
const long long oo = 0x3f3f3f3f;

int N, M, K;
long long dp[MAXN][MAXK], Ans = oo;
priority_queue < pair<int, pair<int, int> >, vector <pair<int, pair<int, int> > > , greater <pair<int, pair<int, int> > > > Q;
vector< pair<int, long long> > G[MAXN];

inline void Dijkstra() {
    memset(dp, oo, sizeof(dp));
    for(int i = 0 ; i <= K ; ++ i)
        dp[1][i] = 0;
    Q.push(make_pair(0, make_pair(1, 0)));
    while(!Q.empty()) {
        int Node = Q.top().second.first;
        int k = Q.top().second.second;
        int actCost = Q.top().first;
        Q.pop();
        if(dp[Node][k] < actCost)
            continue;
        if(Node == N) {
            fout << fixed << setprecision(5) << (double)dp[Node][k] / (1 << 10) << "\n";
            return ;
        }
        for(vector< pair<int, long long> > :: iterator it = G[Node].begin(), fin = G[Node].end(); it != fin ; ++ it) {
            for(int newk = 0 ; newk + k <= K ; ++ newk) {
                if(dp[it->first][k + newk] > actCost + (it->second >> newk)) {
                    dp[it->first][k + newk] = actCost + (it->second >> newk);
                    Q.push(make_pair(dp[it->first][k + newk], make_pair(it->first, newk + k)));
                }
            }
        }
    }
}

int main() {
    fin >> N >> M >> K;
    for(int i = 1 ; i <= M ; ++ i) {
        int x, y, z;
        fin >> x >> y >> z;
        z = (z << 10);
        G[x].push_back(make_pair(y, z));
        G[y].push_back(make_pair(x, z));
    }
    Dijkstra();
    fin.close();
    fout.close();
    return 0;
}
