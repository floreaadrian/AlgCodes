#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int v[101],b[101],ma=-0x3f3f3f3f,po=1,ra;
        for(int i=1;i<=n;++i)
            cin>>v[i];
        for(int i=1;i<=n;++i)
            cin>>b[i];
        for(int i=1;i<=n;++i)
        if(v[i]*b[i]>ma){
            ma=v[i]*b[i];
            po=i;
            ra=b[i];
        }else if(v[i]*b[i]==ma && b[i]>ra)
                po=i,ra=b[i];
        cout<<po<<"\n";
    }
    return 0;
}
