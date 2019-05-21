#include<fstream>

using namespace std;

ifstream fin("case1.in");
ofstream fout("case1.out");

int placa[10001];

int main()
{
	int n,i,c,vizitate,ok,intoarceri,minint,mini,maxviz;
	fin>>n;	
	for(i=1;i<=n;i++)
	fin>>placa[i];
	fin.close();
	ok=0;
	minint=n+1;
	maxviz=0;
	mini=0;
	for(i=1;i<=n;i++)
	{
		c=i;
		vizitate=1;
		intoarceri=0;
		while(i!=placa[c]){
			vizitate++;
			if(placa[c]<c)
			intoarceri++;
			c=placa[c];
		}
		if(vizitate==1)
		ok++;
		if(vizitate>maxviz || (vizitate==maxviz && intoarceri<minint)){
			mini=i;
			maxviz=vizitate;
			minint=intoarceri;
		}
	}
	fout<<ok<<"\n"<<maxviz<<"\n"<<mini;
	fout.close();
	return 0;
}
