#include<iostream>
using namespace std;
int fr[10];
int main(){
	int a,ok=1,n;
	cin>>n;
	int i=1;
	while(ok==1 || i<n){
		cin>>a;
		while(a>0){
		if(fr[a%10]>0) ok=0;
		fr[a%10]++;
		a/=10;
		}
		for(int j=0;j<=9;j++)
		fr[j]=0;
		i++;
	}
	if(ok)cout<<"DA";
	else cout<<"NU";
}
