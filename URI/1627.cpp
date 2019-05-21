#include<iostream>
using namespace std;
int main()
{
	int at,ad,bt,bd,n,h;
	cin>>n;
	for(int f=1;f<=n;f++)
	{
		int aa=0,bb=0;
		cin>>at>>ad>>bt>>bd>>h;
		h-=at-bt;
		aa+=ad;bb+=bd;
		bool ok=true;
		while(ok)
		{
			if(aa<bb)
			{
				h-=at;
				if(h<=0)
				{
				cout<<"Andre\n";
				break;
		    	}
				aa+=ad;
			}
			if(bb>aa)
			{
				h-=bt;
				if(h<=0)
				{
				cout<<"Beto\n";
				break;
				}
				bb+=bd;
			}
			if(bb==aa)
			{
				h-=at;
				if(h<=0)
				{
				cout<<"Andre\n";
				break;
				}
				aa+=ad;
				h-=bt;
				if(h<=0)
				{
				cout<<"Beto\n";
				break;
				}
				bb+=bd;
			}
		}
	}
	return 0;
}
