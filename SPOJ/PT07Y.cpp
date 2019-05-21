#include<iostream>
#include<vector>
using namespace std;
vector <int> A[10001];
int n,m,viz[10001];

void citire_graf()
{
	int i,x,y;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		A[x].push_back(y);
		A[y].push_back(x);
	}
}

void dfs(int nod)
{
	int i,nr_vec;
	viz[nod]=1;
	nr_vec=A[nod].size();
	for(i=0;i<nr_vec;i++)
	if(!viz[A[nod][i]])
	dfs(A[nod][i]);
}

int main()
{
	int i,ok=1;
	citire_graf();
	dfs(1);
	for(i=1;i<=n;i++)
	{
		if(viz[i]==0)
		ok=0;
	}
	if(ok && m==n-1)cout<<"YES";
	else cout<<"NO";
	return 0;
}
