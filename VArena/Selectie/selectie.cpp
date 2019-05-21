#include<fstream>

using namespace std;

ifstream fin("selectie.in");
ofstream fout("selectie.out");

int v[1000000];

int main()
{
	int n,k,i,end,begin,b,e,pivot,aux;
	fin>>n>>k;
	for(i=0;i<n;i++)
	fin>>v[i];
	fin.close();
	k--;
	begin=0;
	end=n-1;
	while(begin<end){
		b=begin;
		e=end;
		pivot=v[(b+e)/2];
		while(b<=e){
			while(v[b]<pivot)b++;
			while(v[e]>pivot)e--;
			if(b<=e){
				aux=v[b];v[b]=v[e];v[e]=aux;
				b++;e--;
			}
		}
		if(k<=e)
		end=e;
		else if(k>=b)
			begin=b;
		else
		begin=end=k;
	}
	fout<<v[k]<<"\n";
	fout.close();
	return 0;
}
