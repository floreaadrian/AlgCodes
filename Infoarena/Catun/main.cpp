#include <fstream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

ifstream fin("catun.in");
ofstream fout("catun.out");

const int MAXN = 36005;
const int oo = 0x3f3f3f3f;

typedef pair<int, int > edge;
typedef vector<edge> Graph[MAXN];
typedef vector<edge> :: iterator It;

int N, M, K;
bitset<MAXN> Catun;
vector<int> d(MAXN, oo), C(MAXN);
queue<int> Q;
Graph G;

inline void Dijkstra() {
    for( ; !Q.empty() ; Q.pop() ) {
        int Node = Q.front();
        for(It it = G[Node].begin(), fin = G[Node].end(); it != fin ; ++ it)
            if(d[it->first] > d[Node] + it->second || (d[it->first] == d[Node] + it->second && C[it->first] > C[Node])) {
                C[it->first] = C[Node];
                d[it->first] = d[Node] + it->second;
                Q.push(it->first);
            }
    }
}

int main() {
    fin >> N >> M >> K;
    for(int i = 1 ; i <= K ; ++ i) {
        int x;
        fin >> x;
        Catun[x] = true;
        C[x] = x;
        d[x] = 0;
        Q.push(x);
    }
    for(int i = 1 ; i <= M ; ++ i) {
        int x, y, z;
        fin >> x >> y >> z;
        G[x].push_back(make_pair(y, z));
        G[y].push_back(make_pair(x, z));
    }
    Dijkstra();
    for(int i = 1 ; i <= N ; ++ i)
        if(C[i] == i)
            fout << "0 ";
        else fout << C[i] << ' ';
    return 0;
}
