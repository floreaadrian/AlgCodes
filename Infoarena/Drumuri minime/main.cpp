#include <fstream>
#include <vector>
#include <cmath>
#include <queue>
#include <bitset>
#include <string.h>

#define MOD 104659
#define eps 1e-9
#define na 1505
#define oo 0x3f3f3f3f

using namespace std;

ifstream fin("dmin.in");
ofstream fout("dmin.out");

double d[na];
int n,m,nr[na];

bitset <na> viz;
vector < pair <int,double> > v[na];

struct CMP{ bool operator ()(int a,int b){
    return d[a]>d[b];}};

priority_queue <int, vector<int>, CMP> q;

int main()
{
    fin>>n>>m;
    for(int i=2;i<=n;++i)
        d[i]=oo;
    double cost;
    for(int i=1;i<=m;++i){
        int a,b;
        double c;
        fin>>a>>b>>c;
        cost=log(c);
        v[a].push_back(make_pair(b,cost));
        v[b].push_back(make_pair(a,cost));
    }
    q.push(1);
    nr[1]=1;
    for(int i,nod;!q.empty();){
        i=q.top();
        q.pop();
        if(viz[i])
            continue;
        viz[i]=1;
        for(int j=0;j<v[i].size();++j){
            nod=v[i][j].first;
            cost=v[i][j].second;
            if(fabs(d[nod]-d[i]-cost) < eps)
                nr[nod]=(nr[nod]+nr[i])%MOD;
            else if(d[nod]>d[i]+cost){
                nr[nod]=nr[i];
                d[nod]=d[i]+cost;
                q.push(nod);
            }
        }
    }
    for(int i=2;i<=n;++i)
        fout<<nr[i]<<" ";
    return 0;
}
