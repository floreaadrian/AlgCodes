#include <iostream>
#include <vector>

using namespace std;

int n;
long long si;
vector <int> g[100001];
bool viz[100001];

void df(int node){
    int nr;
    nr=g[node].size();
    viz[node]=true;
    for(int i=0;i<nr;++i)
        if(!viz[g[node][i]]){
            si++;
            df(g[node][i]);
        }
}

int main()
{
    int m;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    long long result = 0,sum=0;
    for(int i=0;i<n;++i)
        if(!viz[i]){
            si=1;
            df(i);
            result+=sum*si;
            sum+=si;
    }
    cout<<result<<"\n";
    return 0;
}
