#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;
        string st;
        cin>>st;
        if(st=="INDIAN")
            k=200;
        else k=400;
        int s=0;
        while(n--)
            {
                string b;
                cin>>b;
                if(b=="CONTEST_WON")
                {
                    int l;
                    cin>>l;
                    s+=300;
                    if(l<20)
                        s+=20-l;
                }else
                if(b=="TOP_CONTRIBUTOR")
                    s+=300;
                else if(b=="BUG_FOUND"){
                    int l;
                    cin>>l;
                    s+=l;
                }else if(b=="CONTEST_HOSTED")
                s+=50;
            }
            cout<<s/k<<"\n";
    }
    return 0;
}
