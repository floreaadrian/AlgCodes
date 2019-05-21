#include <bits/stdc++.h>

using namespace std;

vector <pair<int,string>> g[31205];

ifstream fin("ninjago.in");
ofstream fout("ninjago.out");

int n, m, father[31205], c=0;

inline bool verf(string s)
{
    for(int i=0;i<4;++i)
    if(s[i]=='E')return false;
    return true;
}

inline int find(int x) {
    if(father[x] != x)
        father[x] = find(father[x]);
    return father[x];
}

inline bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y)
        return false;
    father[x] = y;
    return true;
}

bitset <31205> viz;

void df(int node)
{
    viz[node]=true;
    c++;
    for(auto it: g[node])
    if(!viz[it.first] && verf(it.second))
    df(it.first);
}

int main()
{
    int p;
    fin>>p;
    if (p==1) {
      fin>>n>>m;
      for(int i=1;i<=m;++i)
      {
        int x,y;
        string z;
        fin>>x>>y;
        fin>>z;
        g[x].push_back(make_pair(y,z));
        g[y].push_back(make_pair(x,z));
      }
      df(1);
      fout<<c<<"\n";
    }else if(p==2){
    fin>>n>>m;
    vector <pair<int, pair<int, int> > > edges;
    for(int i=1;i<=m;++i){
        int x,y,z=0;
        string s;
        fin>>x>>y;
        fin>>s;
        for(int i=0;i<4;++i)
            if(s[i]=='E')z++;
        edges.push_back(make_pair(z, make_pair(x, y)));
    }
    for(int i = 1 ; i <= n ; ++ i)
        father[i] = i;
    sort(edges.begin(), edges.end());
    int total = 0;
    for(int i = 0 ; i < edges.size() ; ++ i) {
        if(unite(edges[i].second.first, edges[i].second.second)) {
            total += edges[i].first;
            if(edges[i].first>0)
            c++;
        }
    }
    fout<<c<<"\n"<<total<<"\n";
  }else{
    fin>>n>>m;
    //vector <pair<int, pair<int, pair<int,int> > >
    vector <pair<int, pair<int, pair<int,int> > > >edges;
    for(int i=1;i<=m;++i){
        int x,y,z=0;
        string s;
        fin>>x>>y;
        fin>>s;
        int cost=0,p5=1;
        for(int i=0;i<4;++i)
            {
              if(s[i]=='A')cost=cost+p5*1;
              else if(s[i]=='B')cost=cost+p5*2;
              else if(s[i]=='C')cost=cost+p5*3;
              else if(s[i]=='D')cost=cost+p5*4;
              else if(s[i]=='E')z++;
              p5*=5;
          }
        edges.push_back(make_pair(z,make_pair(cost,make_pair(x, y))));
    }
    for(int i = 1 ; i <= n ; ++ i)
        father[i] = i;
    sort(edges.begin(), edges.end());
    int total = 0;
    for(int i = 0 ; i < edges.size() ; ++ i) {
        if(unite(edges[i].second.second.first, edges[i].second.second.second))
            total += edges[i].second.first;
      }
      fout<<total<<"\n";
    }
    return 0;
}
