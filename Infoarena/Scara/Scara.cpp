#include<fstream>
#include<iomanip>
using namespace std;

ifstream fin("scara2.in");
ofstream fout("scara2.out");

int sol[101],solmin[101],uz[101],htot;
double ef[101],efmin;
int N,H,p,M;

void Citire();
void Gen(int);
void Afisare();
double efort();

int main()
{
	Citire();
	efmin=(double)H*N+1;
	Gen(1);
	Afisare();
	return 0;
}

void Citire()
{
	fin>>H>>N>>M>>p;
	fin.close();
}

void Afisare()
{
	int i;
	fout<<fixed<<setprecision(2)<<efmin<<"\n";
	for(i=1;i<N;i++)
	   fout<<solmin[i]<<" ";
	fout<<solmin[N]<<"\n";
	fout.close();
}

double efort()
{
	int k,j;
	double x,sum;
	for(k=1;k<=N;k++)
	{
		x=sol[k]+ef[k-1];
		sum=sol[k];
		for(j=2;k-j>=0;j++)
		{
			sum+=sol[k-j+1];
			if(sum>M)break;
			if(sum/j+p+ef[k-j]<x)
			x=sum/j+ef[k-j]+p;
		}
		ef[k]=x;
	}
	return ef[N];
}

void Gen(int k)
{
	int i;
	double x;
	if(k==N+1)
	{
		if(htot==H)
		{
			x=efort();
			if(x<efmin && efmin-x>0.001)
			{
				efmin=x;
				for(i=1;i<=N;i++)solmin[i]=sol[i];
			}
		}
	}else
	for(i=1;i<=H && htot+i<=H && i<=M;i++)
	    if(!uz[i])
	    {
	    	sol[k]=i;htot+=i;uz[i]=1;
	    	Gen(k+1);
	    	uz[i]=0;htot-=i;
		}
}
