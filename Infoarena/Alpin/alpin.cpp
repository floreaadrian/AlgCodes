#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

ifstream fin("alpin.in");
ofstream fout("alpin.out");

int di[4]={0,0,1,-1};
int dj[4]={1,-1,0,0};

int m[1025][1025],n,a[1025][1025],c=0,startx,starty,mi=16385,max=0;;

queue <pair <int ,int> > coada;

void citire()
{
	int i,j;
	fin>>n;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
		{
			fin>>m[i][j];
			if(m[i][j]<mi)
			{
				mi=m[i][j];startx=i;starty=j;
			}
	}
	//fout<<startx<<" "<<starty;
}
bool ok(int i,int j,int i_urm,int j_urm)
{
	if(i<1 || i>n || j<1 || j>n )return false;
	if(m[i][j]>m[i_urm][j_urm])return false;
	return true;
}

void lee()
{
	int i,j,i_urm,j_urm;
	a[startx][starty]=1;
	coada.push(make_pair(startx,starty));
	while( !coada.empty() )
 	{
 		i=coada.front().first;
 		j=coada.front().second;
 		coada.pop();
 		for(int dir=0 ; dir < 4 ; dir++ )
 		{
 			i_urm=i+di[dir];
 			j_urm=j+dj[dir];
 			if(ok(i,j,i_urm,j_urm))
 			{
 				a[i_urm][j_urm]=a[i][j]+1;
 				coada.push(make_pair(i_urm,j_urm));
			 }
		 }
	 }
	 //fout<<a[i][j];
}
int main()
{
	citire();
	lee();
    for(int i=1;i<=n;++i)
	{
	for(int j=1;j<=n;++j)
	fout<<a[i][j]<<" ";
	fout<<"\n";
	}
}
