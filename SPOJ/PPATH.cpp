#include <iostream>
#include <queue>
#include<math.h>
using namespace std;
int step,arr1[10000];
int putere(int a,int p)
{
    int i=1;
    while(p--)
    {
        i*=a;
    }
    return i;
}
int bfs(int f,int n)
{
    int pre,aici,now,k,a,b,i,j,top;
    queue<int> q;
    q.push(f);
    arr1[f]=1;
    pre=1;now=k=aici=0;
    while(q.empty()==0)
    {
        top=q.front();
        q.pop();
        if(top==n)
            {
                aici=1;
                break;
            }
        ++now;
        for(i=0;i<4;i++)
        {
            if(i==3)
                j=1;
            else
                j=0;
            while(j<10)
            {
                if(j!=((top/putere(10,i))%10))
                {
                    a=top-(((top/putere(10,i))%10)*putere(10,i))+j*putere(10,i);
                    if(arr1[a]==0)
                    {
                        q.push(a);
                        arr1[a]=1;
                        ++k;
                    }
                }
                j++;
            }
        }
        if(now==pre)
        {
            ++step;
            pre=k;
            now=0;
            k=0;
        }
    }
    return aici;
}
int main()
{
    int i,j,a,arr[10000],b,k,c,t;
    for(i=0;i<10000;i++)
        arr[i]=0;
    arr[0]=1;arr[1]=1;
    for(i=2;i<5000;i++)
    {
        for(j=i*2;j<10000;j+=i)
            arr[j]=1;
    }
    cin>>t;
    while(t--)
    {
        for(i=1000;i<10000;i++)
            arr1[i]=arr[i];
        cin>>a>>b;
        step=0;
        c=bfs(a,b);
        if(c==1)
        cout<<step<<"\n";
        else
            cout<<"Impossible\n";
    }

    return 0;
}
