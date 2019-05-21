#include<vector>
#include<iostream>
#include<string.h>
using namespace std;
  
int viz[100005],n,m,cnt=0;
vector <int> A[100001];
  
void citeste_graf()
{
    int i;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        char x,y;
        cin>>x>>y;
        int x1=x-'a'+1,y1=y-'a'+1;
        A[x1].push_back(y1);
        A[y1].push_back(x1);
    }
}
  
void df(int nod)
{
    int nr_vecini,i;
    char b=nod-1+'a';
    cout<<b<<",";
    viz[nod]=1;
    nr_vecini=A[nod].size();
    for(i=0;i<nr_vecini;i++)
        if(viz[A[nod][i]]==0)
        df(A[nod][i]);
}
  
int main()
{
    int t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
    citeste_graf();
    cout<<"Case #"<<j<<":\n";
    for(int i=1;i<=n;i++)
    if(viz[i]==0)
    {
        cnt++;
        df(i);
        cout<<"\n";
    }
    cout<<cnt<<" connected components\n";
    memset(A,0,sizeof(A));
    memset(viz,0,sizeof(viz));
    cnt=0;
    }
    return 0;
}
