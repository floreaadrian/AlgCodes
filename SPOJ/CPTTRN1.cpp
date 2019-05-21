#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				cout<<((i+j)%2==0 ? "*" : ".");
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
