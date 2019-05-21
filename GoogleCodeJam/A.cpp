#include<fstream>
using namespace std;
ifstream fin("A-small-attempt0.in.");
ofstream fout("A-small-attempt0.out.");
int t1[101];
int main()
{
	int v[1001],i,i1,j,n,t,s,sum,c;
	fin>>t;
	for(i1=1;i1<=t;++i1)
	{
		c=0;
		fin>>n>>s;
		for(i=n+1;i>=1;i--)
		{
			v[i]=s%10;
			s/=10;
		}
		if(v[1]==0)
		{
		v[1]=1;t1[i1]=1;
		}
		sum=v[1];
		for(i=2;i<=n;++i)
		{
			if(sum<i-1 && v[i]!=0)
			{
			    t1[i1]+=(i-sum-1);
				sum+=(i-sum-1);
			}
			sum+=v[i];
		}
	}
	for(i=1;i<=t;++i)
	fout<<"Case #"<<i<<": "<<t1[i]<<"\n";
	return 0;
}
