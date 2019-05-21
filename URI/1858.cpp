#include <iostream>

using namespace std;

int main()
{
    int n,mi=105,c=0;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        if(a<mi){
            mi=a;
            c=i;
        }
    }
    cout<<c<<"\n";
    return 0;
}
