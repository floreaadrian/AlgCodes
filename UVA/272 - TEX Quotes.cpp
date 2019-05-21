#include<fstream>
#include<string.h>
using namespace std;

ifstream cin("date.in");
ofstream cout("date.out");

int main()
{
	char c;
	bool ok=1;
	while(cin>>c){
		if(c=='"')
		{
		if(ok)cout<<"``";else
		cout<<"''";
		ok=(!ok);}
		else cout<<c;
	}
	return 0;
}
