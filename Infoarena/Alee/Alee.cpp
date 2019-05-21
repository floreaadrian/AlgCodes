#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

ifstream fin("alee.in");
ofstream fout("alee.out");

int di[4]={0,0,1,-1};
int dj[4]={1,-1,0,0};

int map[180][180],n,m;
int startx,starty,stopx,stopy;

queue< pair <int , int > > coada;

void citeste()
{
	fin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		int x,y;
		fin>>x>>y; //citim coordonatele
		map[x][y]=-1; //face ca fiind nevizitate
	}
	fin>>startx>>starty; //locul de start
	fin>>stopx>>stopy; //locul de oprire
}

 bool ok(int i,int j)
 {
 	if(i<1 || i>n || j<1 ||j>n)return false; //daca nu se afla in matrice
 	if(map[i][j]==-1)return false; //daca este nevizitt
 	return true;
 }

 void lee()
 {
 	int i,j,i_urm,j_urm;
 	map[startx][starty]=1; //marcam startul cu 1
 	coada.push(make_pair(startx,starty)); //bagam in coada startul
 	while( !coada.empty() )
 	{
 		i=coada.front().first; //primul element al primului din coada
 		j=coada.front().second; //al doilea element al primului din coada
 		coada.pop();//le scoatem din coada
 		for(int dir=0 ; dir < 4 ; dir++ )
 		{
 			i_urm=i+di[dir];//urmatorul loc de i
 			j_urm=j+dj[dir];//urmatorul loc de j
 			if(ok(i_urm,j_urm) && map[i_urm][j_urm] < 1) // daca putem merge si locul e mai mic de 1
 			{
 				map[i_urm][j_urm]=map[i][j]+1; //crestem locul
 				coada.push(make_pair(i_urm,j_urm)); //bagam in coada
			 }
		 }
	 }
 }

int main()
{
	citeste();
	lee();
	fout<<map[stopx][stopy];//afixam cat de repedea am ajuns aici
}
