#include<fstream>
#include<math.h>

using namespace std;

ifstream fin("lascoala.in");
ofstream fout("lascoala.out");

int main()
{
	int k,i,a;
	float n;
	fin>>a;
	n=a-1;
	while(sqrt(n)!=floor(sqrt(n)))
	{
		n--;
	}
	fout<<a-n<<"\n";
	k=sqrt(n);
	for(i=n;i>=1;)
	{
		for(int j=1;j<=k;j++)
		{
			fout<<i<<" ";i--;
		}
		fout<<"\n";
	}
	return 0;
}
