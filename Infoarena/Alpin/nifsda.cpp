#include<iostream>
#include<queue>
using namespace std;

int di[4]={0,0,1,-1};
int dj[4]={1,-1,0,0};
int startx,starty,stopx,stopy,ma[180][180],n,m;

queue <pair <int,int> > coada;

void citeste()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		int x,y;
		cin>>x>>y;
		ma[x][y]=-1;
	}
	cin>>startx>>starty;
	cin>>stopx>>stopy;
}

bool ok(int i,int j)
{
	if(i<1 || i>n || j<1 || j>n) return false;
	if(ma[i][j]==-1)return false;
	return true;
}
void lee()
{
	int i,j,i_urm,j_urm;
	ma[startx][starty]=1;
	coada.push(make_pair(startx,starty));
	while(!coada.empty())
	{
		i=coada.front().first;
		j=coada.front().second;
		coada.pop();
		for(int d=0;d<4;d++)
		{
			i_urm=i+di[d];
			j_urm=j+dj[d];
			if(ok(i_urm,j_urm) && ma[i_urm][j_urm] < 1)
			{
				ma[i_urm][j_urm]=ma[i][j]+1;
				coada.push(make_pair(i_urm,j_urm));
			}
		}
	}
}
int main()
{
	citeste();
	lee();
	cout<<ma[stopx][stopy];
}
