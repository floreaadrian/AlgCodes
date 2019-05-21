#include <iostream>

using namespace std;

int ma[5001][5001];

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    while(k--){
        int op,r,a;
        cin>>op>>r>>a;
        if(op==1){
            for(int j=1;j<=m;++j)
                ma[r][j]=a;
        }
        else for(int j=1;j<=n;++j)
            ma[j][r]=a;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            cout<<ma[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
