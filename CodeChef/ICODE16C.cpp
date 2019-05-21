#include <iostream>
#include <fstream>

using namespace std;

ofstream fout("date.out");

int alp=0,beta=0;

int proc(int ti)
{
    if(ti<=0)
        alp++;
    else if(ti==1)
        beta++;
    else
    {
        proc(ti-1);
        proc(ti-2);
        proc(ti-3);
    }
}

int main()
{
    int t;
    proc(200);
    cout<<alp<<" "<<beta;
    return 0;
}
