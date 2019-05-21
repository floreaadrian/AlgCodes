#include<iostream>
using namespace std;
int main()
{
	long long int t1,t2,b;
	int t;
	cin>>t;
	for(int f=1;f<=t;f++)
	{
		cin>>b;
		t2=b/2;
  		t1=t2*t2;
 		t1=t1-t2;
 		t1=t1/2;
 		cout<<t1<<"\n";
	}
	return 0;
}
