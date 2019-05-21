#include <bitset>
#include <vector>
#include <math.h>
#include <queue>
#include <string.h>
#include <iostream>

using namespace std;

const int MAXN = 105;
const int oo = 0x3f3f3f3f;

typedef vector<int> Graph[MAXN];
typedef vector<int> :: iterator It;

int N, M, C[MAXN][MAXN], Father[MAXN];
int Source, Sink;
bitset <MAXN> Used;
queue <int> Q;
Graph G;


inline bool BFs(int Source, int Sink) {
    Used.reset();
    Q.push(Source);
    Used[Source] = 1;
    while(!Q.empty()) {
        int Node = Q.front();
        Q.pop();
        if(Node == Sink)
            continue;
        for(It it = G[Node].begin(), fin = G[Node].end(); it != fin ; ++ it)
            if(!Used[*it] && C[Node][*it] > 0) {
                Used[*it] = 1;
                Father[*it] = Node;
                Q.push(*it);
            }
    }
    return Used[Sink];
}

inline int getMaxFlow(Graph &G, int Source, int Sink) {
    int maxFlow = 0;
    while(BFs(Source, Sink))
    for(It it = G[Sink].begin(), fin = G[Sink].end(); it != fin ; ++ it) {
        if(!Used[*it] || C[*it][Sink] <= 0)
            continue;
        Father[Sink] = *it;
        int bottleNeck = oo;
        for(int i = Sink ; i != Source ; i = Father[i])
            bottleNeck = min(bottleNeck, C[Father[i]][i]);
        for(int i = Sink ; i != Source ; i = Father[i]) {
            C[Father[i]][i] -= bottleNeck;
            C[i][Father[i]] += bottleNeck;
        }
        maxFlow += bottleNeck;
    }
    return maxFlow;
}

int main() {
    while(cin >> N >> M) {
        if(!N && !M)
            return 0;
        Source = 0;
        Sink = 2 * N + 1;
        for(int i = 2 ; i < N ; ++ i) {
            int x, cost;
            cin >> x >> cost;
            G[x].push_back(N+x);
            G[N+x].push_back(x);
            C[x][N+x] = cost;
        }
        for(int i = 1 ; i <= M ; ++ i) {
            int x, y, z;
            cin >> x >> y >> z;
            G[N+x].push_back(y);
            G[y].push_back(N+x);
            G[N+y].push_back(x);
            G[x].push_back(N+y);
            C[N+x][y] = z;
            C[N+y][x] = z;
        }
        cout << getMaxFlow(G, N+(1), N) << '\n';
        for(int i = Source ; i <= Sink ; ++ i)
            vector <int> ().swap(G[i]);
        memset(C, 0, sizeof(C));
    }
    return 0;
}
