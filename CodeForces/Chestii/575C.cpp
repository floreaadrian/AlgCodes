#include<iostream>

using namespace std;

int fr1[20],fr2[20];

int main()
{
	int a[42][42],n,m,i,j,s,u,p,max,n2;
	cin>>n;
	for(i=0;i<n*2;i++)
	for(j=0;j<n;j++)
	cin>>a[i][j];
	m=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		if(fr1[i]<a[i][j])
		fr1[i]=a[i][j];
	}
	n2=n*2;
	for(i=n;i<n2;i++)
	{
		for(j=0;j<n;j++)
		if(fr2[m]<a[i][j])
		fr2[m]=a[i][j];
		m++;
	}
	for(u=n-1;u>0;u--){ 
  	max=fr1[0];
  	p=0;                      
  	for(i=1;i<=u;i++)
    if (fr1[i]>max){        
      max=fr1[i];
      p=i;
    }
  	fr1[p]=fr1[u];
  	fr1[u]=max;
	}
	for(u=m-1;u>0;u--){ 
  	max=fr2[0];
  	p=0;                      
  	for(i=1;i<=u;i++)
    if (fr2[i]>max){        
      max=fr2[i];
      p=i;
    }
  	fr2[p]=fr2[u];
  	fr2[u]=max;
	}
	s=0;
	i=m-1;
	while(i>=m/2)
	{
		s+=fr1[i];
		s+=fr2[i];
		i--;
	}
	cout<<s;
	return 0;
}
