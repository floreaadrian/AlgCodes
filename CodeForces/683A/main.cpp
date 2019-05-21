#include <iostream>

using namespace std;

int main()
{
    int a,x,y;
    cin>>a>>x>>y;
    if(x<0 || y<0)
        cout<<2;
    else{
        if((x==0) || (x==a))
            cout<<1;
        else if((y==0) || (y==a))
            cout<<1;
        else if(a>x && a>y)
            cout<<0;
    }
    return 0;
}
