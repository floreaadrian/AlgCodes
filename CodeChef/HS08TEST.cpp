#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float y;
    int x;
    cin>>x>>y;
    if(x%5!=0)
        cout<<fixed<<setprecision(2)<<y;
    else {
        if(y>x+0.5)
            cout<<fixed<<setprecision(2)<<y-x-0.5;
        else cout<<fixed<<setprecision(2)<<y;
    }
    return 0;
}
