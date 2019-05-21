#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

ifstream fin("perechivocale1.in");
ofstream fout("perechivocale1.out");

bool verf(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        return true;
    return false;
}

int main()
{
    vector <string> a;
    while(!fin.eof())
    {
        char s[41];
        fin.getline(s,40);
        int ln=s.size();
        for(int i=0;i<ln;++i)
            if(verf(s[i])&& verf(s[i+1])){
                char c=s[i];
                a.push_back(c);
            }
        for(auto it: a)
            fout<<a<<" ";
    }
    return 0;
}
