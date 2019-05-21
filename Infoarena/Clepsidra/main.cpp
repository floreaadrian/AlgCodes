#include <bits/stdc++.h>

using namespace std;

ifstream fin("clepsidra.in");
ofstream fout("clepsidra.out");

const int oo = 0x3f3f3f3f;

int n, m;
int dflevel[200005];
int lwl[200005];
stack <pair <int, int> > st;
vector <int> G[200005];
int bcc[200005];
int pow2[200005];
bitset <200005> critic;

const int lim = (1 << 20);
char buff[lim];
int pos;

inline void extractBCC(int x, int y) {
    int Tx, Ty;
    set<int> actBCC;
    do {
        Tx = st.top().first;
        Ty = st.top().second;
        st.pop();
        actBCC.insert(Tx);
        actBCC.insert(Ty);
    } while(x != Tx || y != Ty);
    for(set <int> :: iterator it = actBCC.begin(), fin = actBCC.end() ; it != fin ; ++ it)
        ++ bcc[*it];
}

void dfs(int node, int tata, int actlevel) {
    dflevel[node] = lwl[node] = actlevel;
    int sons = 0;
    bool critical = false;
    for(auto it: G[node]) {
        if(it == tata)
            continue;
        if(!dflevel[it]) {
            ++ sons;
            st.push(make_pair(node, it));
            dfs(it, node, actlevel + 1);
            lwl[node] = min(lwl[node], lwl[it]);
            if(lwl[it] >= dflevel[node]) {
                extractBCC(node, it);
                critical = true;
            }
        }
        else
            lwl[node] = min(lwl[node], dflevel[it]);
    }
    if(tata == -1)
        if(sons < 2)
            critical = false;
        else critical = true;
    critic[node] = critical;
}

int main() {
    fin >> n >> m;
    for(int i = 1 ; i <= m ; i ++ ) {
        int x, y;
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, -1, 1);
    pow2[0] = 1;
    for(int i = 1 ; i <= n ; i ++ )
        pow2[i] = (pow2[i - 1] * 2) % 666013;
    for(int i = 1 ; i <= n ; i ++ )
        if(!critic[i])
            fout << "0\n";
        else
            fout << pow2[bcc[i]] - 2 << '\n';
    return 0;
}
