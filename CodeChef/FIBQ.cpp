#include<iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
using namespace std;

pair<int,int> st[1000008];
int arr[1000008]={0};

pair<int,int> createTree(int ss, int se, int si)
{
    if(ss==se)
    {
        st[si].first=arr[ss];
        st[si].second=INT_MIN;
        return st[si];
    }
    int mid=(ss+se)/2;
    pair<int,int> t1=createTree(ss,mid,si*2+1);
    pair<int,int> t2=createTree(mid+1,se,si*2+2);
    int a[4];
    a[0]=t1.first;
    a[1]=t1.second;
    a[2]=t2.first;
    a[3]=t2.second;
    sort(a,a+4);
    st[si].first=a[3];
    st[si].second=a[2];
    return st[si];
}

void update(int ss, int se, int si,int val,int i)
{
    if(ss==se)
    {
        arr[ss]=val;
        st[si].first=val;
        st[si].second=INT_MIN;
        return;
    }
        if(val>st[si].first)
        {
            int f=st[si].first;
            st[si].first=val;
            if(st[si].second<f)
            {
                st[si].second=f;
            }
        }
        else if(st[si].second<val)
        {
            st[si].second=val;
        }

    int mid=(ss+se)/2;
    if(mid>=i)
    {
        update(ss,mid,si*2+1,val,i);
    }
    else if(mid<i)
    {
        update(mid+1,se,si*2+2,val,i);
    }
    return;
}

pair<int,int> query(int ss, int se, int qs, int qe, int si)
{
    pair<int,int> temp;
    if(qs>se || qe<ss)
    {
        temp.first=INT_MIN;
        temp.second=INT_MIN;
        return temp;
    }
    if(qs<=ss && se<=qe)
    {
        return st[si];
    }
    int mid=(ss+se)/2;
    pair<int,int> t1=query(ss,mid,qs,qe,si*2+1);
    pair<int,int>t2=query(mid+1,se,qs,qe,si*2+2);
    int a[4];
    a[0]=t1.first;
    a[1]=t1.second;
    a[2]=t2.first;
    a[3]=t2.second;
    sort(a,a+4);
    temp.first=a[3];
    temp.second=a[2];
    return temp;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n,x,y,q;
    char c;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    createTree(0,n-1,0);
    while(q--)
    {
        cin>>c>>x>>y;
        if(c=='C')
            update(0,n-1,0,y,x-1);
        if(c=='Q')
        {
            pair<int,int> ans=query(0,n-1,x-1,y-1,0);
            cout<<ans.first+ans.second<<endl;
        }
    }
    return 0;
}
