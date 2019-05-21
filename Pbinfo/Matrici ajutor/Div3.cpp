//https://www.pbinfo.ro/?pagina=probleme&id=786
#include <iostream>

using namespace std;

int main ()
{
    int a[105][105],b[105][105],n,z,s=0;
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            b[j][i]=a[i][j];
    for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            cout<<b[i][j]<<" ";
            cout<<"\n";
        }
    return 0;
}
