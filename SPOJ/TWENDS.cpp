#include<iostream>
using namespace std;
int v[1001],n;
long long dp1=0,dp2=0;
void rez(int n)
{
	int p,ul,i1,i2;
	i1=1;i2=n;
	while(i1<i2){
		if(v[i1]<v[i2]){
			dp1=+v[i2];i2--;
			cout<<i2<<" ";
		}else{
			dp1+=v[i1];i1++;
		}
		if(v[i1]<v[i2]){
			dp2+=v[i2];i2--;
		}else {
			dp2+=v[i1];i1++;
		}
	}
	cout<<i1<<" "<<i2;
}
int main()
{
	int i;
	cin>>n;
	while(n!=0){
		for(i=1;i<=n;i++)
		cin>>v[i];
		rez(n);
		cin>>n;
	}
	return 0;
}
