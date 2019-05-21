#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,mark[100001];
vector <int> A[10001];
queue <int> q;

void citire_graf()
{
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		A[x].push_back(y);
		A[y].push_back(x);
	}
}

bool bf()
{
	int flag=0;
	int list[n],i;
	for(i=0;i<=n;i++)
	list[i]=2;
	int nr_vec,nod;
	for(i=1;i<=n;i++)
	{
	if(mark[i]==0)
	{
	q.push(i);
	list[i]=1;
	while(q.size()!=0)
	{
		nod=q.front();
		nr_vec=A[nod].size();
		for(int j=0;j<nr_vec;j++){
			if(list[A[nod][j]]==2)
			list[A[nod][j]]=!list[nod];
			else if(list[A[nod][j]]==list[nod]){
				flag=1;
				break;
			}
			if(mark[A[nod][j]]==0)
			q.push(A[nod][j]);
		}
		q.pop();
		mark[nod]=1;
		if(flag==1)
		break;
	  }
	  }
	  if(flag==1)
	  break;
	}
	if(flag==1)
	cout<<"Suspicious bugs found!\n";
	else cout<<"No suspicious bugs found!\n";
}

int main()
{
	int a;
	cin>>a;
	for(int i=1;i<=a;i++){
	cout<<"Scenario #"<<i<<":\n";
	citire_graf();
	bf();
	}
	return 0;
}
