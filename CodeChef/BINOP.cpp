#include <iostream>

using namespace std;

int o,e,i,unu,z;
char s1[1000010],s2[1000010];

int main() {
    int t;
	cin>>t;
	while(t--)
	{
		o=e=0;unu=z=0;
		cin>>s1>>s2;
		for(i=0;s1[i];i++)
		{
			if(s1[i]=='0')
			z++;
			else
			unu++;
		}
		if(z==i||unu==i)
		{
			cout<<"Unlucky Chef\n";
			continue;
		}
		for(i=0;s1[i];i++)
		{
			if(s1[i]!=s2[i])
			{
				if(s1[i]=='0')
				o++;
				else
				e++;
			}
		}
		cout<<"Lucky Chef\n"<<max(o,e)<<"\n";
	}
	return 0;
}
