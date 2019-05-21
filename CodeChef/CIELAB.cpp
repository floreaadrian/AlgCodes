#include <iostream>

using namespace std;

int v[100001],l;

void tr(int n)
{
    while(n)
    {
        v[l]==n%10;
        n/=10;
        l++;
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
    int c=a-b;
    tr(c);
    l--;
    if(v[l]>1){
        cout<<v[l]-1;l--;
        for(int i=l;i>0;i--)
        {
            cout<<v[i];
        }
    }
    else {
        bool ok=true;
        for(int i=l;i>0 && ok;i--)
        {
            if(v[i]>1){v[i]--,ok=false;}
            cout<<v[i];
        }
    }
    return 0;
}
