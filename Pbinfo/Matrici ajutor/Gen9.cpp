//https://www.pbinfo.ro/?pagina=probleme&id=218
#include <iostream>

using namespace std;

int main()
{
    int n,a[16][16];
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
    {
       if(i==1 || i==n || j==1 || j==n)
        a[i][j]=i+j;
    }
    for(int i=2;i<n;++i)
        for(int j=2;j<n;++j)
        a[i][j]=a[i-1][j]+a[i-1][j-1]+a[i-1][j+1];
    for(int i=1;i<=n;++i)
        {for(int j=1;j<=n;++j)
        cout<<a[i][j]<<" ";
    cout<<"\n";}
    return 0;
}
