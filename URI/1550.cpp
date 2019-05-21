#include <bits/stdc++.h>

using namespace std;

int rev(int x)
{
    int r,rev=0;
    while(x>0){
        r=x%10;
        x/=10;
        rev=rev*10+r;
    }
    return rev;
}

bitset <100006> viz;
int fin;

int re(int x)
{
    int ans=0;
    queue <pair<int,int> > q;
    q.push(make_pair(x,0));
    while(!q.empty())
    {
        pair <int,int> node = q.front();
        viz[node.first]=true;
        int a=node.first+1,b=rev(node.first);
        if(a==fin || b==fin)
            return node.second +1;
        if(!viz[a])
            q.push(make_pair(a,node.second+1));
        if(!viz[b])
            q.push(make_pair(b,node.second+1));
        q.pop();
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        viz.reset();
        int x;
        scanf("%d%d",&x,&fin);
        printf("%d\n",re(x));
    }
    return 0;
}
