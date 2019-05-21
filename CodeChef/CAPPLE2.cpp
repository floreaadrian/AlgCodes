#include<iostream>
using namespace std;
long  fr[100000];
int main()
{
	int v,w,n,i,k,x;
	cin>>w;
	for(v=1;v<=w;++v)
	{
		k=0;
		cin>>n;
		for(i=1;i<=n;++i)
		{cin>>x;
		fr[x]++;}
		
		for(i=1;i<=100000;++i)
		{if(fr[i]>0) k++;
		fr[i]=0;}
		cout<<k<<endl;
	}
	return 0;
}
