#include<iostream>
#include<string.h>
using namespace std;
char st[101];
int main(){
	int a;
	cin>>a;
	for(int j=1;j<=a;j++){
		cin>>st;
		for(int i=0;i<strlen(st)/2;i+=2)
		cout<<st[i];
		cout<<"\n";
	}
	return 0;
}
