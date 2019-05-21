#include<iostream>
#include<vector>
using namespace std;
vector <int> A[100001];
int viz[100001],n;

void df(int nod)
{
	int nr_vec,i;
	viz[nod]=1;
	nr_vec=A[nod].size();
	for(i=0;i<nr_vec;i++)
	if(viz[A[nod][i]]==0)
	df(A[nod][i]);
}

int main()
{
	int t,e,con,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n>>e;
		con=0;
		for(int i=0;i<n;i++)
		viz[i]=0;
		for(int i=0;i<n;i++)
		A[i].clear();
		for(int i=0;i<e;i++)
		{
			cin>>x>>y;
			A[x].push_back(y);
			A[y].push_back(x);
		}
		for(int i=0;i<n;i++)
		if(!viz[i]){
			df(i);
			con++;
		}
		cout<<con<<"\n";
	}
	return 0;
}
