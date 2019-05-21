//https://www.pbinfo.ro/?pagina=probleme&id=1749
#include <iostream>

using namespace std;

int main ()
{
    int a[205][205],n,z,s=0;
    cin>>n>>z;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(z==1 && i<j && j<n-i+1)s+=a[i][j];
            else if(z==2 && i<j && j>n-i+1)s+=a[i][j];
            else if(z==3 && i>j && j>n-i+1)s+=a[i][j];
            else if(z==4 && i>j && j<n-i+1)s+=a[i][j];
    cout<<s;
    return 0;
}
