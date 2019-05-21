#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long l1,r1,l2,r2,k;
	cin>>l1>>r1>>l2>>r2>>k;
	l1 = max(l1,l2);
	r1 = min(r1,r2);
	if(l1>r1)
		cout<<"0\n";
	else
		cout<<r1-l1+1- (k>=l1 && k<=r1 ? 1: 0)<<"\n";
}
