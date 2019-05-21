#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("nrtri.in");
ofstream g("nrtri.out");
int main()
{
	int n,a[801],i,c=0,sol=0,pn=0,mijl=0,j,st;
	f>>n;
	for(i=1;i<=n;++i)
	f>>a[i];
	sort(a+1,a+n+1);
	 for(i=1;i<=n-2;i++)
    {
        for(j=i+1;j<=n-1;j++)
        {
            st=j+1;
            pn=n;
            while(st<=pn)
            {
                mijl=(st+pn)/2;
                if(a[mijl]>a[i]+a[j])
                    pn=mijl-1;
                else
                    st=mijl+1;
            }
            sol=sol+pn-j;
        }
    }
    g<<sol;
	
}
