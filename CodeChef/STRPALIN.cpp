#include<bits/stdc++.h>
using namespace std;

int main() {

char s[1000],s1[1000];
int n;
set< char > a;
set< char > b;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>s;
    cin>>s1;
    a.insert(s,s+strlen(s));
    bool ok=false;
    b.insert(s1,s1+strlen(s1));
    set< char >::iterator it;
    for(it=a.begin();it!=a.end();++it)
    {
        if(binary_search(b.begin(),b.end(), *it))
        {
            ok=true;
        }
    }
    if(ok)
        cout<<"Yes\n";
    else
    cout<<"No"<<'\n';
}

return 0;
}
