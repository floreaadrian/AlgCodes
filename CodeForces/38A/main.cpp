#include <iostream>

using namespace std;

int main()
{
    int n,v[102],a,b,s=0;
    cin>>n;
    for(int i=1;i<n;++i)
        cin>>v[i];
    cin>>a>>b;
    for(int i=a;i<b;++i)
        s+=v[i];
    cout<<s;
    return 0;
}
