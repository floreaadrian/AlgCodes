#include <bits/stdc++.h>

using namespace std;

ifstream fin("base3.in");
ofstream fout("base3.out");

const int MAXN = 16005;
const int oo = 0x3f3f3f3f;

typedef vector<int> Graph[MAXN];
typedef vector<int> :: iterator It;

const inline void Get_min(int &a, const int b)    { if( a > b ) a = b; }

char A[MAXN], B[MAXN], C[MAXN];
int dp[(MAXN << 1)], LA, LB, LC;
priority_queue <pair<int, int> , vector <pair<int, int> > , greater < pair<int, int> > > Q;

inline int myAbs(const int &value) {
    if(value < 0) return -value;
    return value;
}

inline void buildDp(const char *X, const int LX) {
    for(int i = 0 ; i < LX ; ++ i)
        if(X[i] == '1')
            Get_min(dp[myAbs(i - (LX - i - 1))], LX);
}

inline void send(const int &cost, const int &Node, const int &LX) {
    if(Node + LX < (MAXN << 1) && dp[Node + LX] > cost + LX) {
        Q.push(make_pair(cost + LX, Node + LX));
        dp[Node + LX] = cost + LX;
    }
    if(myAbs(Node - LX) < (MAXN << 1) && dp[myAbs(Node - LX)] > cost + LX) {
        Q.push(make_pair(cost + LX, myAbs(Node - LX)));
        dp[myAbs(Node - LX)] = cost + LX;
    }
}

inline void Dijkstra() {
    while(!Q.empty()) {
        int cost = Q.top().first;
        int Node = Q.top().second;
        Q.pop();
        if(cost > dp[Node])
            continue;
        if(Node == 0)
            return;
        send(cost, Node, LA);
        send(cost, Node, LB);
        send(cost, Node, LC);
    }
}

int main() {
    fin.getline(A, MAXN);
    fin.getline(B, MAXN);
    fin.getline(C, MAXN);
    LA = strlen(A);
    LB = strlen(B);
    LC = strlen(C);
    memset(dp, oo, sizeof(dp));
    buildDp(A, LA);
    buildDp(B, LB);
    buildDp(C, LC);
    for(int i = 0 ; i < (MAXN << 1) ; ++ i)
        if(dp[i] != oo)
            Q.push(make_pair(dp[i], i));
    Dijkstra();
    fout << ((dp[0] == oo) ? 0 : dp[0]) << '\n';
    fin.close();
    fout.close();
    return 0;
}
