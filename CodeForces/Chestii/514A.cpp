#include<iostream>
using namespace std;
int main()
{
	int a[100],n,i=1,j;
	cin>>n;
	while(n>0)
	{
		a[i]=n%10;
		i++;
		n=n/10;
	}
	if(a[i]==9)cout<<"9";else if(a[i]>=5)
	cout<<9-a[i]; else if(a[i]<5)cout<<a[i];
	for(j=i;j>2;++j)
	if(a[j]>=5)cout<<9-a[j];else
	cout<<a[j];
	return 0;
}
