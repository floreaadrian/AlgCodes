#include<iostream>
#include<math.h>
#include<algorithm>
#define maxim(a,b) (((a)>(b))?(a):(b))
using namespace std;
double manx,v[6],a,total;
float m,w,suma;
int sum[6]={500,1000,1500,2000,2500};
int main()
{
	int i,a,sh,us;
	for(i=0;i<5;i++)
	{
	cin>>m;
	manx=(double)(1-(m/250))*sum[i];
	v[i]=manx;
	}
	for(i=0;i<5;i++)
	{
		cin>>w;
		manx=(double)50*w;
		suma=v[i]-manx;
		total+=maxim((double)0.3*sum[i],suma);
	}
	cin>>sh>>us;
	total+=(sh*100)-(us*50);
	cout<<total<<"\n";
	return 0;
}
