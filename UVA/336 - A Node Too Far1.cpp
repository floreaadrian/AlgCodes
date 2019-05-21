#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;
int viz[10000];
vector <int> a[100001];
set <int> cs;

void BFS(int s)
{
    queue< int >q;
    q.push(s);
    viz[s] = 0;
    while(!q.empty())
    {
        int top = q.front();
        for(int i=0; i<a[top].size(); i++)
        {
           int n = a[top][i];
           if(!viz[n])
           {
               viz[n] = viz[top] + 1;
               q.push(n);
           }
        }
        q.pop();
    }
}



int main()
{
    int edges, cases=0;
    while(cin>>edges && edges!=0)
    {
        for(int i=0; i<edges; i++)
        {
            int x, y;
            cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
            cs.insert(x);
            cs.insert(y);
        }
        int ttl, source;
        while(cin>>source && cin>>ttl && source && ttl)
        {
            memset(viz,0,sizeof(viz));
            BFS(source);
            int count=0;
            for(set<int>::iterator it=cs.begin(); it!=cs.end(); ++it)
            if(viz[*it]>ttl)
            count++;
            cout<<"Case "<<++cases<<": "<<count<<" nodes not reachable from node "<<source<<" with TTL = "<<ttl<<"\n";
        }
        memset(a,0,sizeof(a));
        cs.clear();
    }
    return 0;
}
