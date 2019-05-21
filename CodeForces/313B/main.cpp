#include <iostream>

using namespace std;

int diff[100005];

void calc(string s)
{
    int n=s.size();
    for(int i=1;i<n;++i)
            diff[i]=diff[i-1]+(s[i]==s[i-1]);
}

int main()
{
    string s;
    cin>>s;
    int m;
    calc(s);
    cin>>m;
    for(int i=0;i<m;++i)
    {
        int l,r;
        cin>>l>>r;
        cout<<diff[r-1]-diff[l-1]<<"\n";
    }
    return 0;
}
