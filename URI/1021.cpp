#include <iostream>

using namespace std;

int main()
{
    float l;
    cin>>l;
    int n=l*100+1;
    cout<<"NOTAS\n";
    cout<<n/10000<<" nota(s) de R$ 100.00\n";
    n=n-(n/10000)*10000;
    cout<<n/5000<<" nota(s) de R$ 50.00\n";
    n=n-(n/5000)*1000;
    cout<<n/2000<<" nota(s) de R$ 20.00\n";
    n=n-(n/2000)*1000;
    cout<<n/1000<<" nota(s) de R$ 10.00\n";
    n=n-(n/1000)*1000;
    cout<<n/500<<" nota(s) de R$ 5.00\n";
    n=n-(n/500)*100;
    cout<<n/200<<" nota(s) de R$ 5.00\n";
    n=n-(n/200)*100;
    return 0;
}
