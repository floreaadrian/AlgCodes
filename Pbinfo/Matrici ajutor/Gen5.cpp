//https://www.pbinfo.ro/?pagina=probleme&id=214
#include <iostream>

using namespace std;

int main ()
{
    int n;
    cin>>n;
    int a[100],c=0;
    while(n){
        c++;
        a[c]=n%10;
        n/=10;
    }
    for(int i=1;i<=c;++i){
        for(int j=1;j<=c;++j)
            cout<<a[j]<<" ";
        cout<<"\n";
    }
    return 0;
}
