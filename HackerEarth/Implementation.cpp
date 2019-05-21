#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <bitset>

using namespace std;

vector <int> g[100005];
bitset <100005> viz;
int ar[100005];

int root(int i)
{
    while(ar[i]!=i)
        i=ar[i];
    return i;
}

bool fin(int a,int b)
{
    if(root(a)==root(b))
        return true;
    return false;
}

void union(int a,int b)
{
    int root_a=root(a);
    int root_b=root(b);
    arr[root_a]=root_b;
}

void dfs(int i)
{
    viz[i]=true;
    for(auto it: g[i])
        if(!viz[it])
        dfs(it);
}

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
        ar[i]=i;
    while(q--)
    {

    }
    return 0;
}
