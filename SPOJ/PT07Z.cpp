#include<iostream>
#include<vector>
#define max1(a,b) ((a)>(b)?(a):(b))
using namespace std;
int viz[10001],n;
vector <int> A[10001];

void citire_graf()
{
	int x,y;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		cin>>x>>y;
		A[x].push_back(y);
		A[y].push_back(x);
	}
}

int total=0;
int dfs(int nod)
{
    int m,m1=-1,m2=-1,nr_vec;
    viz[nod]=1;
    nr_vec=A[nod].size();
    for(int i=0;i<nr_vec;i++)
    {
        if(!viz[A[nod][i]]){
            m=dfs(A[nod][i]);
            if(m>=m1)
            {
                m2= m1;
                m1 = m;
            }
            else if(m>m2)
                m2=m;
        }
    }
    total = max1(total , m1+m2+2);
    return (m1 + 1);
}
int main()
{
	citire_graf();
	dfs(1);
	cout<<total;
	return 0;	
}
