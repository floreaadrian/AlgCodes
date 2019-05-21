#include <fstream>
#include <vector>
#include <bitset>
#include <queue>

#define Sink N
#define Source 1

using namespace std;

ifstream cin("maxflow.in");
ofstream cout("maxflow.out");

const int MAXN = 1005;

typedef vector<int> Graph[MAXN];
typedef vector<int> :: iterator It;

Graph G;
int N, M, Father[MAXN], Qu[MAXN][MAXN], Flow[MAXN][MAXN], MaxFlow;
bitset<MAXN> Used;

inline bool BFs()
{
    queue<int> Q;
    Used.reset();
    for(Q.push(Source), Used[Source] = true ; !Q.empty(); Q.pop() )
    {
        int node = Q.front();
        for(It it = G[node].begin(); it != G[node].end(); ++ it)
            if(!Used[*it])
                if(Flow[node][*it] < Qu[node][*it])
                {
                    Father[*it] = node;
                    Q.push(*it);
                    Used[*it] = true;
                }
    }
    return Used[Sink];
}

int main()
{
    for(cin >> N >> M ; M ; -- M)
    {
        int x, y, z;
        cin >> x >> y >> z;
        G[x].push_back(y);
        G[y].push_back(x);
        Qu[x][y] = z;
    }
    for( ; BFs() ; )
    {
        for(int i = Source ; i < Sink ; ++ i)
            if(Flow[i][Sink] < Qu[i][Sink])
            {
                int MinFlow = Qu[i][Sink] - Flow[i][Sink];
                for(int j = i ; j != 1 ; j = Father[j])
                    MinFlow = min(MinFlow, Qu[Father[j]][j] - Flow[Father[j]][j]);
                for(int j = i ; j != 1 ; j = Father[j])
                {
                    Flow[Father[j]][j] += MinFlow;
                    Flow[j][Father[j]] -= MinFlow;
                }
                Flow[i][Sink] += MinFlow;
                Flow[Sink][i] -= MinFlow;
                MaxFlow += MinFlow;
            }
    }
    cout << MaxFlow << "\n";
    cin.close();
    cout.close();
    return 0;
}
