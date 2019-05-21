#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int v[6],n=6,i=0,j=0,c=1,l=6;
	for(i=1;i<=6;++i)
	cin>>v[i];
	sort(v + 1, v + n + 1);i=1;
	do
	{
		cout<<v[i]<<" "<<v[i+1]<<" "<<v[i+2]<<" "<<v[i+3]<<" "<<v[i+4]<<"\n";
		if(v[i]==v[i+1] && v[i]!=v[i+5])
		{
			c==0;j=i+2;
		}i++;l--;
	}while(c && l>1);
	if(c==0)
	{
		if(n-j==1 || (n-j==2 && v[j+1]<v[j+2]))cout<<"Bear";else cout<<"Elephant";
		
	}else cout<<"Alien";
}
