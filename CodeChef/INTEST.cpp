#include <iostream>

using namespace std;

int main()
{
    long long n,k,c=0;
    int a;
    cin>>n>>k;
    while(n--)
    {
        cin>>a;
        if(a%k==0)
            c++;
    }
    cout<<c;
    return 0;
}
