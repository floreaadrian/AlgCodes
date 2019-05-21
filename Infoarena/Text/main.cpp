#include <fstream>
using namespace std;

ifstream fin("text.in");
ofstream fout("text.out");

char a;
int lit,cuv;
bool OK;
int main()
{

    while(!(fin.eof()))
    {
        fin.get(a);
        if((a>='A' && a<='Z') || (a>='a' && a<='z'))
        {
            lit++;
            OK=true;
        }
        else if(OK)
        {
            cuv++;
            OK=false;
        }
    }
    fout<<lit/cuv;
    return 0;
}
