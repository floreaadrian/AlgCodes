#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int tt=1;tt<=t;++tt)
	{
		int n=0,ma=0,maurm=0,a;
		string str;
    	while(getline(cin, str))
    	{
        istringstream ss(str);
        int num;
        while(ss >> num)
        {
            if(num>ma){
				maurm=ma;
				ma=num;
			}
			n++;
        }
    	}
		if(n==ma) cout<<maurm; else cout<<ma;
		cout<<"\n";
	}
	return 0;
}
