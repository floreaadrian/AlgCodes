#include<iostream>
#include<math.h>
#include<queue>
#include<string.h>
using namespace std;
int n;
bool ver[1001][1001];

void bf()
{
	 queue< pair<int,pair<string,int> > >q;
	 for(int i=1;i<=9;i++){
	 	string sr="";
        sr=(char)(48+i);
        q.push((make_pair(i,make_pair(sr,i%n))));
        ver[i][i%n]=false;
	 }
	 while(!q.empty())
    {
        int x=q.front().first;
        pair <string,int> s=q.front().second;
        q.pop();
        if(s.second==0 && x==n)
        {
            cout<<s.first<<endl;
            return ;
        }
        for(int i=0;i<=9;i++)
        {
            if(x+i<=n)
            {
                int temp=s.second*10+i;
                int rem=temp%n;
                if(ver[x+i][rem])
                {
                    ver[x+i][rem]=false;
                    q.push(make_pair(x+i,make_pair(s.first+char(48+i),rem)));
               }
            }
        }
    }
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		memset(ver,true,sizeof(ver));
		cin>>n;
		if(n==1)cout<<"1\n";
		else bf();
	}
	return 0;
}
