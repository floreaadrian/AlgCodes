#include <iostream>

using namespace std;

int fr(long long n)
{
    long long c=0,p10=1;
    while(n>0)
    {
        if(n%10){
            c=c+n%10*p10;
            p10*=10;
        }
        n/=10;
    }
    return c;
}

int main()
{
    int a,b;
    long long c;
    cin>>a>>b;
    c=a+b;
    if(fr(a)+fr(b)==fr(c))cout<<"YES";
    else cout<<"NO";
    return 0;
}
