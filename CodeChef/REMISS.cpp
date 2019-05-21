#include<iostream>

using namespace std;

int max(int x,int y)
{
	if(x>y)return x;
	return y;
}

int main()
{
	int t,a,b,n;
	cin>>t;
	for(int f=1;f<=t;f++)
	{
		cin>>a>>b;
		n=max(a,b);
		cout<<n<<" "<<b+a<<"\n";
	}
	return 0;
}
