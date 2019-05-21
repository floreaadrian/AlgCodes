#include <iostream>

using namespace std;

int main()
{
    int n,m,c[255],c1[255][255];
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>c[i];
        c1[i][0]=1;
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
            if(j>=c[i])
            c1[i][j]=c1[i-1][j]+c1[i][j-c[i]];
        else   c1[i][j]=c1[i-1][j];
    }
    cout<<c1[m][n];
    return 0;
}
