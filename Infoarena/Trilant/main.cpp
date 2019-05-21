#include <bits/stdc++.h>

using namespace std;

ifstream fin("trilant.in");
ofstream fout("trilant.out");

const int MAXN = 100010;
const long long oo = (1LL<<60)-1;

vector < pair<int,int> > G[MAXN];
int pathA[MAXN], pathB[MAXN], pathC[MAXN], N, M, A, B, C;
long long minTime = oo;
int minNode;
vector<long long> dA(MAXN, oo), dB(MAXN, oo), dC(MAXN, oo);

priority_queue< pair<long long, int> , vector<pair<long long, int> >, greater<pair<long long, int> > > Q;

inline void Dijkstra(int Source, vector<long long> &d , int f[MAXN]){
    for(Q.push(make_pair(0, Source)), d[Source] = 0, f[Source] = -1 ; !Q.empty() ; Q.pop() ){
        int Node = Q.top().second;
        for(auto it: G[Node])
            if(d[it.first] > d[Node] + it.second){
                d[it.first] = d[Node] + it.second;
                Q.push(make_pair(d[it.first], it.first));
                f[it.first] = Node;
            }
    }
}

void constr(int minNodem,int path[MAXN],int pc)
{
    vector<int>sol;
    for(int x = minNode ; x != path[pc] ; x = path[x])
        sol.push_back(x);
        fout << sol.size() << " ";
    for(auto it: sol)
        fout << it << " ";
    fout<<"\n";
}

int main() {
    fin >> N >> M;
    fin >> A >> B >> C;
    for(int i = 1 ; i <= M ; ++ i){
        int x, y, z;
        fin >> x >> y >> z;
        G[x].push_back(make_pair(y, z));
        G[y].push_back(make_pair(x, z));
    }
    Dijkstra(A, dA, pathA);
    Dijkstra(B, dB, pathB);
    Dijkstra(C, dC, pathC);
    for(int i = 1 ; i <= N ; ++ i)
        if(minTime > dA[i] + dB[i] + dC[i])
            minTime = dA[i] + dB[i] + dC[i],
            minNode = i;
    fout << minTime << "\n";
    constr(minNode,pathA,A);
    constr(minNode,pathB,B);
    constr(minNode,pathC,C);
    fin.close();
    fout.close();
    return 0;
}
