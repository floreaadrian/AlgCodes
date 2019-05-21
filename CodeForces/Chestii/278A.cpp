#include<iostream>
using namespace std;
int s,t;
void change()
{
	int aux=0;
	aux=s;
	s=t;
	t=aux;
}
int main()
{
	int a[101],n,i,j,s1=0,s2=0;
	cin>>n;
	for(i=1;i<=n;++i)
	cin>>a[i];
	cin>>s>>t;
	if(s>t)
	change();
	for(i=s;i<=t;++i)
		s1+=a[i];
	for(i=t;i>=s;--i)
		s2+=a[i];
	if(s1<s2)cout<<s1;
	else cout<<s2;
}
