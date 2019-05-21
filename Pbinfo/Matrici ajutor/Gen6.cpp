//https://www.pbinfo.ro/?pagina=probleme&id=215
#include <iostream>

using namespace std;

int main ()
{
    int n;
    cin>>n;
    int a[100],c=0,v[100][100]={0};
    while(n){
        c++;
        a[c]=n%10;
        n/=10;
    }
    c++;
    for(int i=1;i<=c;++i){
        for(int j=i+1;j<=c;++j)
            v[i][j]=v[j][i]=a[i];
    }
    for(int i=1;i<=c;++i)
    {
        for(int j=1;j<=c;++j)
            cout<<v[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
