#include<iostream>
using namespace std;
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		if(i%2!=0)
		{
			for(j=1;j<=m;++j)
			cout<<"#";
			cout<<"\n";
		}else if(i%4==0){cout<<"#";
		for(j=2;j<=m;++j)
		cout<<".";cout<<"\n";
	    }else if(i%2==0){for(j=1;j<m;++j)cout<<".";
	    cout<<"#\n";
		}
}return 0;
}
