#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
        int z,u;
        z=0,u=0;
        string a;
        cin>>a;
        int l=a.length();
        for(int i=0;i<l;++i)
            if(a[i]=='1')u++;
        else z++;
        if(z==1 || u==1) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
