#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
    unsigned long long int t,n,m,s,cain[105][105],i,j,pas;
    cin>>t;
    while(t--){
	cin>>n>>m>>s;
	for(i=0;i<=m;i++){
		for(j=1;j<=n;j++){
			cain[i][j]=0;
		}
	}
	cain[0][s]=1;
	for(i=0;i<m;i++){
		cin>>pas;
		for (j=1;j<=n;++j){
			if(cain[i][j]>0){
				if(j-pas>0){
					cain[i+1][j-pas]++;
				}
				if(j+pas<=n){
					cain[i+1][j+pas]++;
				}
				if((j-pas<0)&&(j+pas>n)){
					cain[i+1][j]++;
				}
			}
		}
	}
	for(j=1;j<=n;j++)
        cout<<cain[m][j]%mod<<" ";
	cout<<"\n";
}
    return 0;
}
