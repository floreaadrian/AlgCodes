#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	if(n%2==0){
		cout<<n/2<<"\n";
		for(int i=1;i<=n/2;++i)
		cout<<"2 ";
	}else{
		cout<<n/2<<"\n";
		for(int i=1;i<n/2;++i)
		cout<<"2 ";
		cout<<"3";
	}
	return 0;
}
