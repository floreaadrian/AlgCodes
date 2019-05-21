#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>
#include <string.h>
#include <math.h>

using namespace std;

const int maxn = 200005;
vector <pair<double, pair<int, int> > > edges;
int n, m, father[maxn];

double dist(int x1,int x2,int y1,int y2){
	double n=(double) sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	return n;
}
 
inline int find(int x) {
    if(father[x] != x)
        father[x] = find(father[x]);
    return father[x];
}
 
inline bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y)
        return false;
    father[x] = y;
    return true;
}
 
inline void kruskal() {
	int np=(n*(n-1))/2;
	for(int i = 1 ; i <= np ; ++ i)
        father[i] = i;
    sort(edges.begin(), edges.end());
    double total = 0;
    vector <pair<int, int> > apm;
    for(int i = 0 ; i < edges.size() ; ++ i) {
        if(unite(edges[i].second.first, edges[i].second.second)) {
            total += edges[i].first;
            apm.push_back(edges[i].second);
        }
    }
    cout << total << '\n' << np-1 << '\n';
    int nur=apm.size();
    for(int i=0;i<nur;i++)
        cout << apm[i].first << ' ' << apm[i].second << '\n';
}

void citire()
{
	int ci=0;
	double much;
	cin>>n;
	pair<int,int> p[maxn];
	for(int i=1;i<=n;i++){
		cin>>p[i].first>>p[i].second;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++)
		{
			much=dist(p[i].first,p[j].first,p[i].second,p[j].second);
			cout<<much<<"\n";
		edges.push_back(make_pair(much, make_pair(i,j)));
	}
}
}

int main()
{
	citire();
	kruskal();
	return 0;
}
