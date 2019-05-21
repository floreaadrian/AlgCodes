#include<iostream>
using namespace std;
int max(int n,int l)
{
	if(n>=l)return n;
	return l;
}
int main()
{
	int a,b,c,d,p,t,r1=0,r2=0;
	cin>>a>>b>>c>>d;
	r1=max((3*a)/10,(a-((a/250)*c)));
	r2=max((3*b)/10,(b-((b/250)*d)));
	if(r1>r2)cout<<"Misha";else
	if(r1<r2)cout<<"Vasya";else
	if(r1==r2)cout<<"Tie";
	return 0;
}
