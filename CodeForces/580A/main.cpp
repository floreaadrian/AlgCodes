#include <iostream>

using namespace std;

int max(int a,int b){
    if(a>b)return a;
    return b;
}

int main()
{
    int a,b,ma=0,act=1,n;
    cin>>n;
    cin>>a;
    for(int i=1;i<n;++i)
    {
        cin>>b;
        if(b>=a)act++;
        else {
            ma=max(act,ma);
            act=1;
        }
        a=b;
    }
    ma=max(act,ma);
    cout<<ma;
    return 0;
}
