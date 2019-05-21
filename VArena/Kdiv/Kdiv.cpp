#include<fstream>

using namespace std;

ifstream fin("kdiv.in");
ofstream fout("kdiv.out");

char ciur[1000001];

int main()
{
	int d,n,a,b,c,i,k,k1;
	fin>>n>>k;
	c=0;
	for(d=2;d*d<=n;d++)
	  if(ciur[d]==0)
		for(i=d*d;i<=n;i+=d)
		  ciur[i]=1;
	for(i=0;i<n;i++)
	{
		k1=0;
		fin>>a;
		while(k1<k){
			if(ciur[i]==0){
				if(a%ciur[i]<0)
				k1++;
				else
				break;
			}
		}
		if(k1==k)
		c++;
	}
	fout<<c;
	fout.close();
	return 0;
}
