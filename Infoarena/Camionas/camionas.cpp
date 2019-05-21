#include <fstream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

ifstream fin("camionas.in");
ofstream fout("camionas.out");

const int MAXN = 50005;
const int oo = 0x3f3f3f3f;
typedef vector< pair<int, int> > Graph[MAXN];
typedef vector< pair<int, int> > :: iterator It;
Graph G;
int N, M, dp[MAXN], g;

priority_queue <pair <int, int >, vector<pair<int, int> > , greater <pair<int, int> > > Q;

inline void BFs() {
    memset(dp, oo, sizeof(dp));
    dp[1] = 0;
    Q.push(make_pair(0, 1));
    while(!Q.empty()) {
        int Node = Q.top().second;
        if(Node == N) {
            fout << dp[N] << '\n';
            return;
        }
        Q.pop();
        for(It it = G[Node].begin(), fin = G[Node].end(); it != fin ; ++ it) {
            int actNode = it->first;
            bool cost = it->second < g;
            if(dp[actNode] > dp[Node] + (cost)) {
                dp[actNode] = dp[Node] + (cost);
                Q.push(make_pair(dp[actNode], actNode));
            }
        }
    }
    fout << dp[N]<< '\n';
}
int main() {
    fin >> N >> M >> g;
    for(int i = 1 ; i <= M ; ++ i) {
        int x, y, z;
        fin >> x >> y >> z;
        G[x].push_back(make_pair(y, z));
        G[y].push_back(make_pair(x, z));
    }
    BFs();
    fin.close();
    fout.close();
    return 0;
}
