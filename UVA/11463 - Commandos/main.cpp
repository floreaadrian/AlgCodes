#include <iostream>
#include <string.h>
#define oo 0x3f3f3f3f
using namespace std;

int min(int a,int b)
{
    if(a<b) return a;
    return b;
}

int max(int a,int b)
{
    if(a>b)return a;
    return b;
}
int main()
{
    int t;
    cin>>t;
    for(int tes=1;tes<=t;++tes)
    {
        int n,r,a[105][105];
        cin>>n>>r;
        memset(a,oo,sizeof(a));
        for(int i=0;i<n;++i)
            a[i][i]=0;
        for(int i=0;i<r;++i){
            int u,v;
            cin>>u>>v;
            a[u][v]=1;
            a[v][u]=1;
        }
        for(int k=0;k<n;++k)
            for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
            a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        int s,d;
        cin>>s>>d;
        int mintime=0;
        for(int i=0;i<n;++i)
            if(a[s][i]!=oo && a[i][d]!=oo)
                mintime=max(mintime,a[s][i]+a[i][d]);
            cout<<"Case "<<tes<<": "<<mintime<<"\n";
    }
    return 0;
}
