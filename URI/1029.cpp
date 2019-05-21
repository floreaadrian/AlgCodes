#include<iostream>
using namespace std;
int cnt=0;
long fib(int n){
   
   cnt++;
   if(n==1)
        return 1;
   
   if(n==0) return 0;
return fib(n-1)+fib(n-2);
 
}
int main()
{
	int i,n,x;
	long y;
	  cin>>n;
	    for(i=1;i<=n;++i)
	    {
	    	cin>>x;
	    	 cnt=0;
	    	  y=fib(x);
	    	cout<<"fib("<<x<<") = "<<(cnt-1)<<" calls = "<<y<<endl;
	   
	    }
	return 0;
}
