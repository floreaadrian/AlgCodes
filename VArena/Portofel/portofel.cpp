#include<fstream>

using namespace std;

ifstream fin("portofel.in");
ofstream fout("portofel.out");

int premiu[100000],portofel[100000],apar[100001];

int main()
{
	int m,n,i,j,max,ins;
	fin>>m;
	for(i=0;i<m;i++)
	{
		fin>>portofel[i];
		apar[portofel[i]]++;
	}
	fin>>n;
	for(i=0;i<n;i++)
	{
		fin>>premiu[i];
		apar[premiu[i]]++;
	}
	fin.close();
	max=apar[0];
	for(i=0;i<100001;i++)
		if(apar[i]>max)
		max=apar[i];
	i=0;
	j=0;
	ins=0;
	while(j<n){
		while(i<m && premiu[j]>=portofel[i])
		i++;
		if(i==m)
		j=n;
		else
		while(j<n && premiu[j]<=portofel[i])
		j++;
		ins++;
	}
	fout<<max<<"\n"<<ins;
	fout.close();
	return 0;
}
