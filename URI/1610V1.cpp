#include<fstream>
#include<iostream>
#include<set>
#include<vector>
#include<string.h>
using namespace std;
int n,m,k,i,j,parinte[1250],vizitat[1250],nod,x,y,c=0;
set <pair <int,int> > muchii;
vector <int> a[1250];
 
void scrieciclu(int k,int i)
{nod=k;
 while(i!=nod) 
 {
 muchii.insert(make_pair(nod,parinte[nod]));
 nod=parinte[nod];
 }
}
 
void identificare_ciclu(int k)
{vizitat[k]=1;
int nr=a[k].size();
 for(i=0;i<nr;i++)
  {
   if(vizitat[a[k][i]]==0)
   {parinte[a[k][i]]=k;
   identificare_ciclu(a[k][i]);}
   else if(a[k][i]!=parinte[k]) {scrieciclu(k,a[k][i]);break;}
}
}
 
int main()
{
    while(!cin.eof())
    {
    cin>>n>>m;
    for(i=1;i<=m;i++) {cin>>x>>y; a[x].push_back(y);
	a[y].push_back(x);}
    identificare_ciclu(1);
    for(int i=1;i<=n;i++){
    	int nr=a[i].size();
    for(int j=0;j<nr;j++){
            pair <int,int> per;
            per.first=i;per.second=a[i][j];
            if(muchii.count(per))c++;
        }
    }
    cout<<m-c<<"\n";
    muchii.clear();
    memset(parinte,0,sizeof(parinte));
    memset(vizitat,0,sizeof(vizitat));
    memset(a,0,sizeof(a));
    c=0;
    }
     return 0;
}
