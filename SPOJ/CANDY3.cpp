#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main ()
{
   long long n,t,sum,a;
   cin>>t;
   for(int tt=1;tt<=t;++tt)
   {
   	cin>>n;
   	sum=0;
   	for(int i=1;i<=n;++i)
   		{
   			cin>>a;
   			sum+=a%n;
   		}
   	if(sum%n==0)cout<<"YES\n";
   	else cout<<"NO\n";
   }
   return 0;
}
