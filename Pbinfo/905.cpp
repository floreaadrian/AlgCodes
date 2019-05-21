#include<iostream>
using namespace std;
int p,u;
void detcifre(int n,int &p,int &u){
	u=n%10;
	while(n>9){
		n/=10;
	}
	p=n;
}
int main()
{
	int n;
	cin>>n;
	detcifre(n,p,u);
	cout<<u<<" "<<p;
}
