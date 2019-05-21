#include <iostream>

using namespace std;

int n,m,semn=0;
char a[105][105];

bool valid(int x,int y)
{
    return x>=1 && x<=n && y>=1 && y<=m;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;i<=m;++j)
    {
        cin>>a[i];
        if(a[i]!="." && a[i]!="*")
            semn++;
    }
    int acm=0,i=1,j=1;
    flag ok=false;
    while(acm<=semn || !ok){
        if()
    }
    return 0;
}
