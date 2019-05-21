#include<iostream>
#include<iomanip>
#include<algorithm>
#define inf 100000
using namespace std;

int g[105][105];
int t,n,a,b;

int main()
{
	while(cin>>a>>b){
		if(a==0 && b==0)break;
		t++;
		for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
		if(i==j) g[i][j]=0;
		else g[i][j]=inf;
		n=0;
		do{
			n=max(max(n,a),b);
			g[a-1][b-1]=1;
			cin>>a>>b;
		}while(a!=0 && b!=0);
		for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		int p=0,sum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				if(i!=j && g[i][j]!=inf)
					{
					sum+=g[i][j];p++;
					}
		}
		double re;
		re=(float)sum/p;
		cout<<"Case "<<t<<" average length between pages = "<<fixed<<setprecision(3)<<re<<" clicks\n";
	}
	return 0;
}
