#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int calc(int x1,int y1,int x2,int y2)
{
    return ceil(sqrt(pow((x2-x1),2)+pow((y2-y1),2)));
}

int main()
{
    int n,k;
    vector <int> dist;
    int x[100005],y;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",&x[i]);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&y);
        dist.push_back(calc(0,0,x[i],y));
    }
    sort(dist.begin(),dist.end());
    cout<<dist[k-1];
    return 0;
}
