#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    if (s.find("1111111")==-1 &&  s.find("0000000")==-1)cout<<"NO";
    else cout<<"YES";
    return 0;
}
