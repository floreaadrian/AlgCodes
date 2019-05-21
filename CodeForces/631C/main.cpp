#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction (int i,int j) { return (i>j); }
bool myfunction1 (int i,int j) { return (i<j); }

int v[200001];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    cin>>v[i];
    for(int i=1;i<=m;++i){
        int op,cat;
        cin>>op>>cat;
        if(op==1)   sort(v, v + cat);
        else sort(v,v+cat,myfunction);
    }
    for(int i=0;i<n;++i)
        cout<<v[i]<<" ";
    return 0;
}
