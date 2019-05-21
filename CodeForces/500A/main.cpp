#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bitset <30005> visited;
vector <int> a[30005];

void df(int n)
{
    int nr=a[n].size();
    visited[n]=true;
    for(int i=0;i<nr;++i)
        if(!visited[a[n][i]]){
            df(a[n][i]);
        }
}

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<n;++i)
    {
        int x;
        cin>>x;
        a[i].push_back(x+i);
    }
    df(1);
    if(visited[k])
        cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
