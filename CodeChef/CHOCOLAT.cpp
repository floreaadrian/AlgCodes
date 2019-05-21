#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a==b)
            cout<<"No Winner\n";
        else if(a>b)
            cout<<"Bipin "<<a-b<<"\n";
            else cout<<"Balaji "<<b-a<<"\n";
        }
    return 0;
}
