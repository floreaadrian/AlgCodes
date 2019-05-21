#include<fstream>
#include<iostream>
using namespace std;

ifstream fin("euro2.in");
ofstream fout("euro2.out");

int main()
{
	int n,i,j,i_1,indice;
	float a[100000],ma=0;
	long lung[100000],urm[100000],maxim=0,minim=0;
	fin>>n;
	for(i=1;i<=n;++i)
	{
	fin>>a[i];
    if((float)a[i]>ma){
	ma=a[i];i_1=i;
	}
	}
	for(i=i_1;i>=1;--i){
		//urm[i]=-1;
			lung[i]=1;
		
		for( j=n;j>i;--j ){
			if( a[i] < a[j] )
			if( lung[i] < lung[j]+1 ){
				cout<<lung[i]<<" ";
				lung[i]=lung[j]+1;
				if(lung[i]>maxim){
				 maxim=lung[i];
			     }
			}
		}
	}
    for(i=i_1;i<=n;i++){
			lung[i]=1;
		for( j=i-1;j<=n;j++ ){
			if(a[i]>a[j])
			if( lung[i]<lung[j]+1 ){
				lung[i]=lung[j]+1;
				if(lung[i]>minim)
				{
				 minim=lung[i];
			     }
			}
		}
	}
	//fout<<maxim+minim;
}
