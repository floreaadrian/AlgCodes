#include <fstream>
#include <iostream>

using namespace std;

char a;
int lit,cuv;
bool OK;
int main()
{
    bool b=true;
    int litm=0;
    while(!(cin.eof()))
    {
        cin.get(a);
        if((a>='A' && a<='Z'))
        {
            lit++;
            OK=true;
        }else if(a>='a' && a<='z')
        {
            litm++;
            OK=true;
        }
        else if(OK)
        {
            OK=false;
            if(litm==0 && lit>1)
                cuv++;
            litm=0;
            lit=0;
        }
    }
    cout<<cuv;
    return 0;
}
