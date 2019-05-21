#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct tip{
	int x,y,dist;
};
queue <tip> q;
tip p1;
int x[10]={0,-1,-1,-2,-2,2,2,1,1};
int y[10]={0,-2,2,-1,1,-1,1,-2,2};
bool viz[9][9];
void goleste()
{
	for(int i=1;i<=8;i++)
	for(int j=1;j<=8;j++)
	viz[i][j]=false;
}

void bfs(int x2,int y2){
	int i,j,contor;
	q.push(p1);
	while(!q.empty()){
	i=q.front().x;
	j=q.front().y;
	if(i==x2 && j==y2){
		cout<<q.front().dist<<"\n";
		break;
	}
	contor=q.front().dist;
	for(int k=1;k<=8;k++)
	if(i+x[k]>0 && i+x[k]<=8 && j+y[k]>0 && j+y[k]<=8 && viz[i+x[k]][j+y[k]]==false){
		viz[i+x[k]][j+y[k]]=true;
		p1.x=i+x[k];
		p1.y=j+y[k];
		p1.dist=contor+1;
		q.push(p1);
	}
	q.pop();
	}
}

int main()
{
	int t,x1,x2,y1,y2;
	char c;
	cin>>t;
	for(int l=1;l<=t;l++){
	while(!q.empty())
		q.pop();
		
		cin>>c>>y1;
		x1=c-'a'+1;
		cin>>c>>y2;
		x2=c-'a'+1;
		p1.x=x1;
		p1.y=y1;
		p1.dist=0;
		goleste();
		bfs(x2,y2);
	}
	return 0;
}
