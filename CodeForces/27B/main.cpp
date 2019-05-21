#include <iostream>

using namespace std;

int a[51];

int min(int a,int b){
    if(a<b)return a;
    return b;
}

int max(int a,int b){
    if(a>b)return a;
    return b;
}

int main()
{
    int n,x,y,u=0,v=0;
    cin>>n;
    for(int i=1;i<n;++i)
    for(int j=i+1;j<=n;++j){
        u+=i;
        v+=j;
    }
    for(int i=0;i<n*(n-1)/2-1;i++){
        cin>>x>>y;
        a[x]++;
        u-=min(x,y);
        v-=max(x,y);
    }
    if(a[u]>a[v])cout<<u<<" "<<v<<"\n";
    else cout<<v<<" "<<u<<"\n";
    return 0;
}
