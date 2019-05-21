#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        int s=0;
        while(n--){
            s=(d*(d+1))/2;
            d=s;
        }
        cout<<s<<"\n";
    }
    return 0;
}
