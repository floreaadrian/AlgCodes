#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
vector<long long>v[100000];
map<int,int>mp;
map<int,int>visit;
map<int,int>dif;
queue<int>q;
long long nc,i,pair1,pair2,node,ttl,number,l,x,diff,cs=1,a,b;

using namespace std;
int main()
{
    while(cin>>nc && nc)
    {
        diff=0;
        dif.clear();
        for(i=0;i<99900;i++)
        v[i].clear();
        mp.clear();
        for(i=0;i<nc;i++)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
            if(dif[a]!=1)
            {
                dif[a]=1;
                diff++;
            }
            if(dif[b]!=1)
            {
                dif[b]=1;
                diff++;
            }
        }
        while(cin>>node>>ttl && node!=0 && ttl!=0)
        {
            number=0;
            visit.clear();
            visit[node]=1;
            

        cout<<"Case "<<cs<<": "<<diff-number-1<<" nodes not reachable from node "<<node<<" with TTL = "<<ttl<<".\n";
        cs++;
        }
    }
    return 0;
}
