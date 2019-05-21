#include<iostream>
#include<map>
#include<cstdio>
#include<vector>
using namespace std;
vector< vector<int> > slick;
int getSlick(int,int,int,int);
int main()
{
    vector<int> sl;
    int m,n;
    int count,val,gethow;
    map<int,int> mymap;
    while(cin>>n>>m && n && m)
    {
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>val;
                sl.push_back(val);
            }
            slick.push_back(sl);
            sl.erase(sl.begin(),sl.end());
        }
        int total=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(slick[i][j]==1)
                {
                    count=getSlick(i,j,m,n);
                    if(mymap.find(count)->second<1000)
                        gethow=1+mymap.find(count)->second;
                    else
                        gethow=1;
                    mymap[count]=gethow;
                    total++;
                }
            }
        }
        map<int,int>::iterator it;
        cout<<total<<"\n";
        for(it=mymap.begin();it!=mymap.end();++it)
        {
            cout<<it->first<<" "<<it->second<<"\n";
        }
        mymap.erase(mymap.begin(),mymap.end());
        slick.erase(slick.begin(),slick.end());
    }
    return 0;
}
int getSlick(int i,int j,int m,int n)
{
    slick[i][j]=0;
	int count=1;
    if(j<n-1&&slick[i][j+1]==1)
    {
        
        count=count+getSlick(i,j+1,m,n);
    }

    if(j>0&&slick[i][j-1]==1)
    {
        count=count+getSlick(i,j-1,m,n);
    }
    if(i>0&&slick[i-1][j]==1)
    {
        count=count+getSlick(i-1,j,m,n);
    }
    if(i<m-1&&slick[i+1][j]==1)
    {
        count=count+getSlick(i+1,j,m,n);
    }
    return count;
}
