#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

set <string> key;
vector <int> g;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b,c;
        cin>>a>>b>>c;
        key.insert(a);
        key.insert(b);
        key.insert(c);
        int a1=find(key.begin(),key.end(),a),b1=find(key.begin(),key.end(),b),c1=find(key.begin(),key.end(),c);
        g[a1].push_back(b1);
        g[a1].push_back(c1);
        g[b1].push_back(a1);
        g[b1].push_back(c1);
        g[c1].push_back(a1);
        g[c1].push_back(b1);
    }
    for(int i=1;i<=key.size();++i)
    {for(auto it: g[i])
        cout<<key[it]<<" ";
        cout<<"\n";
        }
    return 0;
}
