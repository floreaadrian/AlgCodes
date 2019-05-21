#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
pair<double, double> p[10000];

double per;
int n, st[1000];

double dist(int x1,int x2,int y1,int y2){
	double n=(double) sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	return n;
}

inline long double crossproduct(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}
 
struct classcomp {
    inline bool operator () (const pair<double, double> &a, const pair<double, double> & b) const {
        return crossproduct(p[1], a, b) < 0;
    }
};

void inf(int n)
{
	int ind=1;
	per=0;
		for(int i = 1 ; i <= n ; ++ i) {
        cin >> p[i].first >> p[i].second;
        if(p[i] < p[ind])
            ind = i;
   		 }
    	swap(p[1], p[ind]);
    	sort(p + 2, p + n + 1, classcomp());
    	st[++ st[0]] = 1;
    	st[++ st[0]] = 2;
    	for(int i = 3 ; i <= n ; ++ i) {
        while(st[0] >= 2 && crossproduct(p[st[st[0] - 1]], p[st[st[0]]], p[i]) > 0)
            -- st[0];
        st[++ st[0]] = i;
    }
    	for(int i=st[0];i>1;--i)
		per+=dist(p[st[i-1]].first,p[st[i]].first,p[st[i-1]].second,p[st[i]].second);
		per+=dist(p[st[st[0]]].first,p[st[1]].first,p[st[st[0]]].second,p[st[1]].second);
		cout<<per<<"\n";
		for(int i=st[0];i>=1;--i)
		cout<<st[i]<<" ";
}

int main()
{
	int t,n;
	cin>>t;
	while(t--){
		int ind=1;
		cin>>n;
		inf(n);
		int i;
		for(i=0;i<=n;i++)
		{p[i].first=0;
		p[i].second=0;
		}
		int b=st[0];
		for(i=0;i<=st[0];i++)
		{
			st[i]=0;
			st[i]=0;
		}
	}
	return 0;
}
