#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b && a!=-1 && b!=-1){
		int sum=a+b;
		if(a==1||b==1)cout<<a<<"+"<<b<<"="<<a+b<<"\n";
		else cout<<a<<"+"<<b<<"!="<<a+b<<"\n";
	}
	return 0;
}
