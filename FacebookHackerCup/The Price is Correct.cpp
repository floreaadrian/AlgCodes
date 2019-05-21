#include<fstream>
using namespace std;
ofstream fout("text.in");
ifstream fin("the_price_is_correct.txt");
int main()
{
	int a,sum,c,n,t,p;
	long long v[100001];
	fin>>t;
	for(int jj=1;jj<=t;jj++)
	{
		c=0;
		fout<<"Case #"<<jj<<": ";
		fin>>n>>p;
		for(int i=1;i<=n;i++)
		{
			fin>>v[i];
			if(v[i]<=p)
			c++;
		}
		for(int i=1;i<=n;i++)
		{
			sum=v[i];
			int j=i+1;
			while(j<=n && sum<p){
				j++;
				sum+=v[j];
				if(sum<=p)
				c++;
			}
		}
		fout<<c<<"\n";
	}
	return 0;
}
