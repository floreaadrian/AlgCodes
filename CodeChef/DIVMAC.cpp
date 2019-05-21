#include <bits/stdc++.h>

using namespace std;

int a[100005],lu[1000005];
vector <int> v;
bitset <1000005> prim;

void pre(int n)
{
    int d,i;
    for(d=2;d*d<=n;d++)
        if(prim[d]==0)
        {v.push_back(d);
            for(i=d*d;i<=n;i=i+d)
                prim[i]=1;}
}

int least(int n)
{
    if(prim[n]) return n;
    else {
        int i=0,l=sqrt(n);
        while(v[i]<=l)
        {
            if(n%v[i]==0)return v[i];
            i++;
        }
        }
}

void up(int l,int r)
{
    for(int i=l;i<=r;++i)
        {
            if(!lu[a[i]])
            lu[a[i]]=least(a[i]);
            a[i]/=lu[a[i]];
        }
}

int get(int l,int r)
{
    int ma=1;
    for(int i=l;i<=r;++i)
        {
            if(!lu[a[i]])
            lu[a[i]]=least(a[i]);
            ma=max(lu[a[i]],ma);
        }
    return ma;
}

int main()
{
    int t;
    pre(1000000);
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int ty,l,r;
        while(m--)
        {
            scanf("%d%d%d",&ty,&l,&r);
            if(ty==0)up(l,r);
            else {
                int k=get(l,r);
                printf("%d ",k);
            }
        }
        printf("\n");
    }
    return 0;
}
