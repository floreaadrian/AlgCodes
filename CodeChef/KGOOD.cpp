#include<iostream>
using namespace std;

int main()
{
	int t,i;
	long A[30],j,k,min=0,B,counter=0;
	char a[100000];
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>a;
		cin>>k;
		for(j=0;j<26;j++)
			A[j]=0;
		for(j=0;a[j]!='\0';j++)
		{
			A[a[j]-'a'+1]++;
		}
    min=100000;
	for(j=1;j<26;j++)
	{
		if((A[j]<min)&&(A[j]>0))
			min=A[j];
	}
	B=min+k;
			counter=0;
			for(j=0;j<25;j++)
			{
				if(A[j]>B)
				{
					counter=counter+(A[j]-B);
				}
			}

		cout<<counter<<"\n";
	}
}
