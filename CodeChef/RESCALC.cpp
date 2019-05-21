#include <iostream>
#include <string.h>

using namespace std;

int adu(int c)
{
    if(c==4) return 1;
    if(c==5) return 2;
    if(c==6) return 4;
    return 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c[105],ty,ha[105][7];
        cin>>n;
        memset(ha,0,sizeof(ha));
        for(int i=1;i<=n;++i)
        {
            cin>>c[i];
            for(int j=0;j<c[i];++j)
            {
                cin>>ty;
                ha[i][ty]++;
            }
        }
        int cot;
        for(int i=1;i<=n;++i)
        {
            do{
            cot=0;
            for(int j=1;j<=6;++j)
                if(ha[i][j]){
                    cot++;
                    ha[i][j]--;
                }
            c[i]+=adu(cot);
            }while(cot>=4);
        }
        int ma=0,in,cc=1;
        for(int i=1;i<=n;++i)
        {
            if(c[i]>ma)
            {
                in=i;
                ma=c[i];
                cc=1;
            }else
            if(ma==c[i])
            cc++;
        }
        if(cc>=2)cout<<"tie\n";
        else if(in==1)cout<<"chef\n";
        else cout<<in<<"\n";
    }
    return 0;
}
