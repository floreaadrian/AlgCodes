//https://www.pbinfo.ro/?pagina=probleme&id=1894
#include <iostream>

using namespace std;

int main ()
{
    int n,a[205][205],fib=0,fib1=1;
    cin>>n;
    int l=n;
    n=n*2+1;
    for(int k=1;k<=n;++k){
        for(int i=k;i<=n-k+1;++i)
            for(int j=k;j<=n-k+1;++j)
                if(i==n-k+1 || i==k || j==n-k+1 || j==k)
                    a[i][j]=l;
        l--;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
