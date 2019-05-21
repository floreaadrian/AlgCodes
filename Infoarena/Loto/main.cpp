#include <fstream>
#include <set>

using namespace std;

ifstream fin("loto.in");
ofstream fout("loto.out");

int n,S,s[105];
set <int> myset;

inline void made(int x){
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            for(int k=j;k<=n;k++)
            if(s[i]+s[j]+s[k]==x)
            fout<<s[i]<<" "<<s[j]<<" "<<s[k]<<" ";
}

int main()
{
    fin>>n>>S;
    for(int i=1;i<=n;i++)
        fin>>s[i];
    for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j++)
    for(int k=j;k<=n;k++)
    myset.insert(s[i] + s[j] + s[k]);
     for(set<int> :: iterator it = myset.begin(), fin = myset.end() ; it != fin ; ++ it){
        if( myset.find(S-*it) != myset.end() ){
            made(S-*it);
            made(*it);
            return 0;
        }
    }
    fout << "-1\n";
    return 0;
}
