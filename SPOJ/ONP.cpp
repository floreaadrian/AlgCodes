#include <iostream>
#include <stack>
#include <cctype>
#include <cstring>
#include <stdio.h>

using namespace std;

int main ()
{
    int t;
    scanf("%d",&t);
    char su[1000];
    stack <char> s;
    for(int tt=1;tt<=t;++tt)
    {
        cin>>su;
        int len = strlen (su);
        for(int i=0;i<len;i++ )
        {
            if(isalpha(su[i]))
                cout << su[i];
            else if(su[i] == ')' )
            {
                cout << s.top ();
                s.pop ();
            }
            else if (su[i] != '(' )
                s.push (su[i]);
        }
        printf("\n");
    }
    return 0;
}
