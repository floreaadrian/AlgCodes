#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t,b,ls;
	float rsmin,rsmax;
	cin>>t;
	for(int f=1;f<=t;++f)
	{
		cin>>b>>ls;
		rsmin=sqrt(pow(ls,2)-pow(b,2));
        rsmax=sqrt(pow(b,2)+pow(ls,2));
        cout<<rsmin<<" "<<rsmax<<"\n";
	}
	return 0;
}
