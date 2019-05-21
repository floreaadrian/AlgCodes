#include <iostream>

using namespace std;

int main()
{
    int n,c25=1,c50=0;
    cin>>n;
    int a;
    cin>>a;
    if(a!=25){
        cout<<"NO\n";
        return 0;
    }
    for(int i=1;i<n;++i)
    {
        cin>>a;
        bool ok=false;
        if(a==100){
            if(c50>0){
                if(c25>0)
                    {
                        c50--;
                        c25--;
                        ok=true;
                    }
            }else if(c25>2){
            c25-=3;ok=true;
            }
        }else if(a==50){
            c50++;
        if(c25>0)c25--,ok=true;
        }else if(a==25){
        c25++;ok=true;}
        if(!ok)
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}
