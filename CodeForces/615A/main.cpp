#include <iostream>

using namespace std;

bool a[101];

int main()
{
    int n,m,x,z;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>x;
        for(int j=1;j<=x;++j){
            cin>>z;
            a[z]=true;
        }
    }
    for(int i=1;i<=m;++i)
        if(!a[i]){
            cout<<"NO\n";
            return 0;
        }
    cout<<"YES\n";
    return 0;
}
