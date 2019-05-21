#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int v[6],n=6,i=0,j=0,c=1,l=6;
	for(i=1;i<=6;++i)
	cin>>v[i];
	sort(v + 1, v + n + 1);i=0;
	while(c<4 && l>1)
	{
		if(v[i]==v[i+1])
		{
		c++;
		}i++;j=i;l--;
	}cout<<j;
	if(c==4)
	{
		if(n-j==1 || (n-j==2 && v[j+1]<v[j+2]) || (n-j==0 && v[1]<v[2]))cout<<"Bear";else cout<<"Elephant";
		
	}else cout<<"Alien";
}
