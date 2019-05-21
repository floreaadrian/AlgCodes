//https://www.pbinfo.ro/?pagina=probleme&id=1772
#include <iostream>

using namespace std;

int main ()
{
    int n,a[205][205],a1,r,cod;
    cin>>a1>>r>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            cout<<a1+r*(n*(j-1)+i-1)<<" ";//calculam termenul in functie de coloana
        cout<<"\n";
    }
    return 0;
}
