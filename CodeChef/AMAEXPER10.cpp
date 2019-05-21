#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c,n,mi=0x3f3f3f3f;
        cin>>n;
        for(int i=1;i<n;++i)
        {
            cin>>a>>b>>c;
            mi=min(c,mi);
        }
        cout<<mi<<"\n";
        for(int i=1;i<n;++i)
            cout<<"0\n";
    }
    return 0;
}
