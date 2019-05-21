#include <iostream>
#include <algorithm>
using namespace std;

pair <int,int> d[] = {{1,0},{0,1},{-1,0},{0,-1}};

char a[55][55];

bool verf(int idx,int x,int y,string seq)
{
    if(idx==seq.size())return false;
    int pomx = d[seq[idx]-'0'].first;
    int pomy = d[seq[idx]-'0'].second;
    x += pomx;
    y += pomy;
    if(a[x][y]!='E' && a[x][y]!='.' && a[x][y]!='S')return false;
    if(a[x][y]=='E')return true;
    return verf(idx+1,x,y,seq);
}


int main() {
    int n,m,si,sj;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j) {
            cin >> a[i][j];
            if(a[i][j]=='S'){
                si=i;
                sj=j;
            }
        }
    string s;
    cin>>s;
    sort(d,d+4);
    int r=0;
    do
    {
        r+=verf(0,si,sj,s);
    }while(next_permutation(d,d+4));
    cout << r;
    return 0;
}