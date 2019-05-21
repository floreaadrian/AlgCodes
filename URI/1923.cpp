#include <bits/stdc++.h>
#define oo 0x3f3f3f3f

using namespace std;

map  <string,int> nume;
vector <string> pr;
vector <int> g[1005];
string nm[1005];
int n,d[1005],k;

void bfs(int node)
{
    memset(d,oo,sizeof(d));
    queue <int> q;
    q.push(node);
    d[node]=0;
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        for(auto it: g[node])
        if(d[it]==oo){
            d[it]=d[node]+1;
            if(d[it]<=k)
                pr.push_back(nm[it]);
            q.push(it);
        }
    }
}

int main()
{
    int cnt=1;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
    {
        string a,b;
        cin>>a>>b;
        if(!nume[a]){
            nm[cnt]=a;
            nume[a]=cnt++;
        }
        if(!nume[b]){
            nm[cnt]=b;
            nume[b]=cnt++;
        }
        int l=nume[a],p=nume[b];
        g[l].push_back(p);
        g[p].push_back(l);
    }
    bfs(nume["Rerisson"]);
    sort(pr.begin(),pr.end());
    printf("%d\n",pr.size());
    for(auto it: pr)
        cout<<it<<"\n";
    return 0;
}
