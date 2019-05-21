#include <bits/stdc++.h>

using namespace std;

ofstream fout("mine.out");

const int oo = (1<<31)-1;
typedef vector< pair<int, int> > :: iterator It;

struct ClassComp {
    inline bool operator () (const pair<int, int> &a, const pair<int, int> &b) const {
        return a.second > b.second;
    }
};

priority_queue <pair<int, int> , vector < pair<int, int> > , ClassComp > H;
bitset<100005> Vis;
vector< pair<int, int> > G[100005];
int Ans;
int N, M, W;
vector<int> V;

#define DIM 10000
char buff[DIM];
int poz=0;

int parse()
{
     int numar = 0;
     while (buff[poz] < '0' || buff[poz] > '9')
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     }
     return numar;
}

int main() {
    freopen("mine.in", "r", stdin);
    N = (parse());
    M = (parse());
    for(int i = 1 ; i <= M ; ++ i) {
        int x(parse()), y(parse()), z(parse());
        G[x].push_back(make_pair(y, z));
        G[y].push_back(make_pair(x, z));
    }
    Vis[1] = true;
    for(It it = G[1].begin(), fin = G[1].end() ; it != fin ; ++ it)
        H.push(*it);
    W = (parse());
    for(int i = 1 ; i <= W ; ++ i) {
        int x(parse());
        V.clear();
        while(H.top().second <= x && !H.empty()) {
            int Node = H.top().first;
            H.pop();
            if(Node == N) {
                fout << i << '\n';
                return 0;
            }
            Vis[Node] = true;
            V.push_back(Node);
        }
        for(int j = 0 ; j < V.size() ; ++ j)
            for(It it = G[V[j]].begin(), fin = G[V[j]].end(); it != fin ; ++ it)
                if(!Vis[it->first])
                    H.push(*it);
    }
    fout << "-1\n";
    fout.close();
    return 0;
}
