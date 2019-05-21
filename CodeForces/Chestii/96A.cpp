#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char s[101];
	int n=0,m=0,i,l;
	cin.getline(s,100);
	if(strstr(s,0000000)||strstr(s,1111111))
	cout<<"YES";else cout<<"NO";
	return 0;
}
