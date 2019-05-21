#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
 
using namespace std;
 
const int maxn = 120005;
int kt;
int ind;
 
int n, st[maxn];
pair<double, double> p[maxn];
 
inline long double crossproduct(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}
 
struct classcomp {
    inline bool operator () (const pair<double, double> &a, const pair<double, double> & b) const {
        return crossproduct(p[1], a, b) < 0;
    }
};
 
 
void citire(int n)
 {
 	for(int i = 1 ; i <= n ; ++ i) {
        cin >> p[i].first >> p[i].second;
        if(p[i] < p[ind])
            ind = i;
    }
 }
void infasuratoare(int b,int ind)
{
    swap(p[1], p[ind]);
    sort(p + 2, p + b + 1, classcomp());
    st[++ st[0]] = 1;
    st[++ st[0]] = 2;
    for(int i = 3 ; i <= b ; ++ i) {
        while(st[0] >= 2 && crossproduct(p[st[st[0] - 1]], p[st[st[0]]], p[i]) > 0)
            -- st[0];
        st[++ st[0]] = i;
    }
}

void schimb(int a,int b)
{
	for(int i=a;i<b;i++)
	swap(p[i],p[i+1]);
}

void sterg(int nn)
{
	for(int i = st[0] ; i >= 1 ; -- i)
	{
	schimb(i,nn);
	}
}

int main() {
    int n;
    while(cin>>n && n!=0){
    	int c=1;
    	ind=1;
    	citire(n);
    	infasuratoare(n,ind);
    	sterg(n);kt=st[0];int nn=n-st[0];
    	while(nn>3){
    		infasuratoare(nn,ind);
    		sterg(nn);
			c++;
    		nn-=st[0];
		}
		cout<<c<<"\n";
	}
	return 0;
}
