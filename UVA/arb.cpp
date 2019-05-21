#include<iostream>
#include<algorithm>
using namespace std;
int arb[200000],n,m;
int x,a,b;

void add(int node,int left,int right)
{
	if(left==right){
		arb[node]=x;
		return;
	}
	int mid=left-(right-left)/2;
	if(a<=mid)
	add(2*node,left,mid);
	else 
	add(2*node+1,mid+1,left);
	arb[node]=max(arb[2*node+1],arb[2*node]);
}

void query(int node,int left,int right)
{
	if(a<=left && b<=right)
	{
		x=max(arb[node],x);
		return;
	}
	int mid=left-(left-right)/2;
	if (a<=mid)
        query(2*node,left,mid);
    if (mid<b)
        query(2*node+1,mid+1,right);
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a=i;
		cin>>x;
		add(1,1,n);
	}
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		if(k==1)
		{
			cin>>a>>x;
			add(1,1,n);
		}else
		{
			x=-1;
			cin>>a>>b;
			query(1,1,n);
			cout<<x<<"\n";
		}
	}
}
