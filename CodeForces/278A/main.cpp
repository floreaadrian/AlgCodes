#include <iostream>

using namespace std;

void swap(int &a,int &b)
{
    int aux;
    aux=a;
    a=b;
    b=aux;
}

int main()
{
    int n,a,b,v[105];
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    cin>>a>>b;
    if(b<a) swap(a,b);
    int mi=0,ma=0;
    for(int i=a;i<b;++i)mi+=v[i];
    for(int i=b;i<=n;++i)ma+=v[i];
    for(int i=1;i<a;++i)ma+=v[i];
    if(ma<mi)cout<<ma;
    else cout<<mi;
    return 0;
}
