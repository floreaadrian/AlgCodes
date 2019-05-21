#include<iostream>
#include<cstring>
using namespace std;

int n, d[30][30][30];
double g[30][30][30];

void citire()
{
	memset(g,0,sizeof(g));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
			cin>>g[i][j][1];
			d[i][j][1]=1;
			}
		}
	}
}

void afisare(int x,int y,int p){
	if(p==0) cout<<x+1;
	else {
		afisare(x,d[x][y][p],p-1);
		cout<<" "<<y+1;
	}
}

void floyd() {
	for(int p=1;p<n;p++) {
		for (int k=0;k<n;k++) {
			for (int i=0;i<n;i++) {
				for (int j=0;j<n;j++) {
					if (g[i][k][p] * g[k][j][1] > g[i][j][p + 1] + 1e-9) {
						g[i][j][p + 1] = g[i][k][p] * g[k][j][1];
						d[i][j][p + 1] = k;
					}
				}
			}
		}

		for (int i=0;i<n;i++) {
			if (g[i][i][p + 1] > 1.01) {
				afisare(i,i,p+1);
				cout<<"\n";
				return ;
			}
		}
	}	
	cout<<"no arbitrage sequence exists\n";
}

int main()
{
	while(cin>>n){
		citire();
		floyd();
	}
	return 0;
}
