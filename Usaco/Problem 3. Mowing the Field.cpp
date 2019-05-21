#include<fstream>
#include<string.h>

using namespace std;

ifstream fin("mowing.in");
ofstream fout("mowing.out");

int m[2005][2005],me,mi=4020025,rema=1000,remb=1000;
char b[2];

void aia(int n,int rema,int remb)
{
	int i;
	if(b[0]=='N')
	{
		for(i=1;i<=n;i++)
		{
		if(m[i+rema][remb]==0)
		m[i+rema][remb]=m[i+rema-1][remb]+1;
//		else {
//			me=m[i+rema][remb]-m[i+rema-1][remb]+1;
//			if(me>mi)
//			mi=me;
//			m[i+rema][remb]=m[i+rema-1][remb]+1;
//		}
		}
		rema=rema+i;
	}
	if(b[0]=='S'){
		for(i=1;i<=n;i++)
		{
		if(m[rema-i][remb]==0)
		m[rema-i][remb]=m[rema-i+1][remb]+1;
//		else {
//			me=m[rema-i][remb]-m[rema-i+1][remb]+1;
//			if(me>mi)
//			mi=me;
//			m[rema-i][remb]=m[rema-i+1][remb]+1;
//		}
		}
		rema=rema-i;
	}
	if(b[0]=='E')
	{
		for(i=1;i<=n;i++)
		{
		if(m[rema][remb+i]==0)
		m[rema][remb+i]=m[rema][remb+i-1]+1;
//		else {
//			me=m[rema][remb+i]-m[rema][i+remb-1]+1;
//			if(me>mi)
//			mi=me;
//			m[rema][remb+i]=m[rema][remb+i-1]+1;
//		}
		}
		remb=remb+i;
	}
	if(b[0]=='W')
	{
		for(i=1;i<=n;i++)
		{
		if(m[rema][remb-i]==0)
		m[rema][remb-i]=m[rema][remb-i+1]+1;
//		else {
//			me=m[rema][remb-i]-m[rema][remb-i+1]+1;
//			if(me>mi)
//			mi=me;
//			m[rema][remb-i]=m[rema][remb-i+1]+1;
		}
//		}
		remb=remb-i;
	}
}

int main()
{
	int n,s,i;
	fin>>n;
	fin>>b[0]>>s;
	if(b[0]=='N')
	{
	for( i=1;i<=s;i++)
	m[rema+1][remb]=m[rema+i-1][remb]+1;
	rema+=i;
	}
	else if(b[0]=='S')
	{
	for( i=1;i<=s;i++);
	m[rema-i][remb]=m[rema-i+1][remb]+1;
	rema-=i;
	}
	else if(b[0]=='E')
	{
	for( i=1;i<=s;i++)
	m[rema][remb+i]=m[rema][remb+i-1]+1;
	remb+=i;
	}
	else if(b[0]=='W')
	{
	m[rema][remb-i]=m[rema][remb-i+1]+1;
	remb-=i;
	}
	for(int j=2;j<=n;j++)
	{
		fin>>b[0]>>s;
		aia(s,rema,remb);
	}
	for(i=1;i<=20;i++)
	{
		for(int j=1;j<=20;j++){
			fout<<m[i+1000][j+1000]<<" ";
		}
		fout<<"\n";
	}
	fout<<mi;
}
