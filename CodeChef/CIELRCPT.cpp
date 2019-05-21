#include<iostream>

using namespace std;

int main()
{
    int t,p,i,c,a,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
	    c=0;
        cin>>p;
        n=p%2048;
        a=p/2048;
        while(n)
        {
            if((n%2)==1)
            c++;
            n=n/2;
        }
        cout<<a+c<<"\n";
    }
    return 0;
}
