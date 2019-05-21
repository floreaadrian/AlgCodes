#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool mi (int i,int j) { return (i>j); }

int v[100005];
vector <int> g;

int pe(int f,int e)
{
    int s=0;
    for(int i=f;i<=e;++i)
        s+=v[i];
    return s;
}

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    cin>>v[i],g.push_back(v[i]);
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
          if(i!=j)
          g.push_back(pe(i,j));
    sort(g.begin(),g.end(),mi);
    int i=0;
    while(i<k)
    cout<<g[i]<<" ",i++;
    return 0;
}
