#include <iostream>

using namespace std;

int min(int a,int b)
{
    if(a<b)return a;
    return b;
}

int n,a[25][25],m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        {for(int j=1;j<=m;++j)

       a[i][j]=min(i,j);
    }
    for(int i=1;i<=n;++i)
        {for(int j=1;j<=m;++j)
        cout<<a[i][j]<<" ";
    cout<<"\n";}
    return 0;
}
