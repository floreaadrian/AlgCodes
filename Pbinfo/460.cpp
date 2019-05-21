#include<iostream>
using namespace std;
int main(){
	int h,m,x,a1,b1,b2;
	cin>>h>>m>>x;
	a1=h*60+m+x;
	b1=a1/60;
	if(b1==24)
	b1=0;
	if(b1>24)b1=b1-24;
	
	b2=a1%60;
	cout<<b1<<" "<<b2;
	return 0;
}
