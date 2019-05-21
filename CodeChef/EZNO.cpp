#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int t[100005];
    for(int i=1;i<=n;++i)
        cin>>t[i];
    int op=n;
    int still;
    int rem=still=0;
    for(int i=1;i<=n;++i){
        t[i]-=2;
        if(t[i]<0)
            rem+=(-1*t[i]);
        else if(t[i]>0)
            still+=t[i];
    }
    if(still>rem)
        {still-=rem;
    if(still%2==0)
        op+=still/2;
    else op+=still/2 + 1;}
    cout<<op;
}
