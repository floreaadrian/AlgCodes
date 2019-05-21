#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int c,d,l,p;
	while(t--)
	{
		cin>>c>>d>>l;
        p=c-2*d;
        if(p<0)p=0;
        if(l%4!=0){cout<<"no\n";}
        else{
            l=l/4;
            l=l-d;
            if(l>=p && l<=c){cout<<"yes\n";}
            else{cout<<"no\n";}
        }
    }
    return 0;
}
