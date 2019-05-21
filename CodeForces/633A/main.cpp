#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(c%a==0 || b%c==0){
        cout<<"Yes\n";
        return 0;
    }
    if(c%a==b || c%b==a){
        cout<<"Yes\n";
        return 0;
    }
    cout<<"No";
    return 0;
}
