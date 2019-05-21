#include<bits/stdc++.h>

using namespace std;

vector <pair <int,int> > v[100005];
bitset <100005> seen;
set <int> tree;
int di[100005],fi[100005];

void df(int node){
    seen[node]=true;
    for(auto it: v[node])
        if(!seen[it.first])
    {
        di[it.first]=max(di[it.first],di[node]+it.second);
        df(it.first);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
     int n;
     cin>>n;
     for(int i=1;i<n;++i){int a,b,c;
     cin>>a>>b>>c;
     v[b].push_back(make_pair(a,c));
     v[a].push_back(make_pair(b,c));
     tree.insert(a);
     }
     for(int i=1;i<=n;++i)
     {
         di(i);
         seen.reset;
         cout<<di[i]<<" ";
     }
    }
    return 0;
}
