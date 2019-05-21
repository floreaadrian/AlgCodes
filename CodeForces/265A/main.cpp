#include <iostream>

using namespace std;

int main()
{
    string s,s1;
    int k=0,j=0;
    cin>>s>>s1;
    int len=s1.size();
    for(int i=0;i<len;++i)
        if(s1[i]==s[k])k++;
    cout<<k+1;
    return 0;
}
