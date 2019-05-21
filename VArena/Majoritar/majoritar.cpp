#include<fstream>

using namespace std;

ifstream fin("majoritar.in");
ofstream fout("majoritar.out");

int v[3000000];

int main()
{
	int n,i,nr,maj;
	fin>>n;
	for(i=0;i<n;i++)
	fin>>v[i];
	fin.close();
	maj=v[0];
	nr=1;
	for(i=1;i<n;i++)
	 if(v[i]==maj)
	 nr++;
	 else{
	 	nr--;
	 	if(nr<0){
	 		maj=v[i];
	 		nr=1;
		 }
	 }
	nr=0;
	for(i=0;i<n;i++)
	if(v[i]==maj)
	nr++;
	if(nr>n/2)
	fout<<maj<<" "<<nr;
	else
	fout<<-1;
	fout.close();
	return 0;
}
