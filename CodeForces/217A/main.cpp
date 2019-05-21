#include <iostream>

using namespace std;

int s,n,x[105],y[105];
bool viz[105];

void df(int nod){
    viz[nod]=1;
    for(int i=1;i<=n;++i)
        if(!viz[i] && (x[nod]==x[i] || y[nod]==y[i]))
        df(i);
}

int main()
{
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;++i)
        if(!viz[i])
    {
        ans++;
        df(i);
    }
    cout<<ans-1;
    return 0;
}
