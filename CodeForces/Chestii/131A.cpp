#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	strings sir[101],sir2[101];
	int n,i;
	cin>>sir;
	i=strlen(sir)-1;
	strcpy(sir2,sir[1],i);
	cout<<sir2;
}
