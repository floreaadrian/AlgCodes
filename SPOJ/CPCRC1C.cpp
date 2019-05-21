#include<iostream>
#include<math.h>
using namespace std;

int sum(long long n) { 
	if(n<10)
	return n;
	return n%10+sum(n/10);
}

long long getans(long long n){
	if (n <= 0) return 0;
	int temp = n % 10, k = (temp*(temp + 1)) / 2;
	return k + (temp + 1)*sum(n/10) + 10 * getans(n / 10 - 1) + 45 * (n/10);
}


int main()
{
	long long a,b;
	cin>>a>>b;
	while(a!=-1 && b!=-1){
		cout<<getans(b)-getans(a-1)<<"\n";
		cin>>a>>b;
	}
	return 0;
}
