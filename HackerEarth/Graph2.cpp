#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <bitset>
#define mod 1000000007
#define oo 0x3f3f3f3f

using namespace std;

int dist[10005][10005],n;
vector <string> s;

int get(string l)
{
    for(int i=0;i<n;++i)
        if(s[i]==l)
        return i+1;
}

int main()
{
    int m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        string l;
        cin>>l;
        s.push_back(l);
    }
    for(int i=1;i<=m;++i)
    {
        int c;
        string s1,s2;
        cin>>s1>>s2>>c;
        int a=get(s1),b=get(s2);
        dist[a][b]=dist[b][a]=c;
    }
    for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
        }
    }
    }
    int q;
    scanf("%d",&q);
    for(int qq=1;qq<=q;++qq)
    {
        string s1,s2;
        cin>>s1>>s2;
        printf("%d\n",dist[get(s1)][get(s2)]);
    }
    return 0;
}
