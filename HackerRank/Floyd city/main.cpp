#include <iostream>
#define oo 0x3f3f3f3f

using namespace std;

int a[405][405];

int min(int a,int b)
{
    if(a>b)return a;
    return b;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            {
                if(i==j)a[i][j]=0;
                else a[i][j]=oo;
            }
        }
    for(int i=1;i<=m;++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=z;
    }
    int k,i,j;
    for(k=1;k<=n;++k)
        for(i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
            if((a[i][j]>a[i][k]+a[k][j]))
			a[i][j]=a[i][k]+a[k][j];
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(a[x][y]==oo)cout<<"-1\n";
        else cout<<a[x][y]<<"\n";
    }
    return 0;
}
