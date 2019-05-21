#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n=0;
    while(!cin.eof())
    {
        char c[4];
        cin>>c;
        if(c[0]=='c')
            {
                cin>>c;
                cout<<n<<"\n";
                n=0;
            }
        if(c[0]=='*')n+=4;
        if(c[1]=='*')n+=2;
        if(c[2]=='*')n+=1;
    }
    return 0;
}
