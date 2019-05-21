#include <bits/stdc++.h>

using namespace std;

bool cmp (int i,int j) { return (i>j); }

int main()
{
    FILE *fin,*fout;
    fin = fopen("input.in","r");
    fout = fopen("output.txt","w");
    int t;
    fscanf(fin,"%d",&t);
    for(int test=1;test<=t;test++)
    {
        int n,w,v[105];
        fscanf(fin,"%d",&n);
        for(int i=0;i<n;++i)
        fscanf(fin,"%d",&v[i]);
        sort(v,v+n);
        int i=0,j=n-1,cont=0;
        while(i<j)
        {
            if(v[j]>=50)cont++;
            else {
                int mid=50/v[j];
                if(i+mid-1<j){
                    cont++;
                    i+=mid;
                }
            }
            j--;
        }
        fprintf(fout,"Case #%d: %d\n",test,cont);
    }
    return 0;
}
