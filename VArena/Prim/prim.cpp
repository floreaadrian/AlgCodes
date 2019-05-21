#include<fstream>

using namespace std;

ifstream fin("prim.in");
ofstream fout("prim.out");

int prime[5000];
char ciur[10001];

int main()
{
	int n,k,d,i,np,a,b;
	fin>>n>>k;
	fin.close();
	for(d=2;d*d<=n;d++)
	  if(ciur[d]==0)
	    for(i=d*d;i<=n;i+=d)
	      ciur[i]=1;
	np=0;
	for(d=2;d<=n;d++)
	if(ciur[d]==0){
		prime[np]=d;
		np++;
	}
	a=(np-2*k+np%2)/2;
    b=a+2*k-np%2;
    if(a<0){
    a=0;
    b=np;
    }
    for(i=a;i<b;i++)
    fout<<prime[i]<<" ";
    fout<<"\n";
	return 0;
}
