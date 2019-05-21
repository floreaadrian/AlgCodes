#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <string.h>

using namespace std;

ifstream cin("apdm.in");
ofstream cout("apdm.out");

const int oo = 0x3f3f3f3f;

int N, M, dp[4005][4005], d[4005];
vector <int> G[4005];

inline void BFs(const int &startNode) {
    queue <int> Q;
    for(Q.push(startNode), d[startNode] = 0 ; !Q.empty() ; Q.pop()) {
        int Node = Q.front();
        for(auto it: G[Node])
            if(d[it] == -1) {
            d[it] = d[Node] + 1;
            Q.push(it);
        }
    }
}
int main() {
    int N, M;
    cin>>N>>M;
    for(int i = 1 ; i <= M ; ++ i) {
        int x, y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int diameter = oo;
    for(int i = 1 ; i <= N ; ++ i) {
        memset(d, -1, sizeof(d));
        BFs(i);
        int maxDist = 0;
        for(int j = 1 ; j <= N; ++ j) {
        dp[i][j] = d[j];
        if(i != j)
        maxDist = max(maxDist, dp[i][j]);
        }
        diameter = min(diameter, 2*maxDist);
    }
    cin.close();
    cin.open("apdm.in");
    cin >> N >> M;
    for(int i = 1 ; i <= M ; ++ i) {
        int x, y;
        cin>>x>>y;
        int maxDist = 0;
        for(int j = 1 ; j <= N ; ++ j)
        maxDist = max(maxDist, min(dp[j][x], dp[j][y]));
        diameter = min(diameter, 2*maxDist+1);
    }
    cout << diameter << '\n';
    cin.close();
    cout.close();
    return 0;
}
