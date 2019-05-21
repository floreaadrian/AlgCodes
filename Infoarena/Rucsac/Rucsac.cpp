#include<fstream>
#include<algorithm>
#define maxn 5001
#define maxg 10001
 
using namespace std;

ifstream fin("rucsac.in");
ofstream fout("rucsac.out");
 
int W[maxn], P[maxn];
int Optim[maxg];

int main()
{
	int N,G,sol=0;
	fin>>N>>G;
	for(int i=1;i<=N;i++)
	fin>>W[i]>>P[i];
	Optim[0]=0;
	for(int i=1;i<=N;++i)
        for(int j=G-W[i];j>=0;--j) 
		{
            if(Optim[j+W[i]]<Optim[j]+P[i])
            {
                Optim[j+W[i]]=Optim[j]+P[i];
                if(Optim[j+W[i]]>sol)
                    sol=Optim[j+W[i]];
            }
        }
	fout<<sol;
	return 0;
}
