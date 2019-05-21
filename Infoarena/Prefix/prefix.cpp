#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
 
using namespace std;
 
const int maxn = 2000005;
 
char a[maxn];
int n, pi[maxn];
 
int main() {
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");
    int t;
    fin>>t;
    while(t--){
    fin >> a + 1;
    n = strlen(a + 1);
    int k = 0;
    for(int i = 2 ; i <= n ; ++ i) {
        while(k > 0 && a[k + 1] != a[i])
            k = pi[k];
        if(a[k + 1] == a[i])
            ++ k;
        pi[i] =  k;
	}
	int solve=0;
	for(int i=n;i>=2;i--)
	if(pi[i] && !(i % (i - pi[i])))
	{
	solve=i;break;}
	fout<<solve<<"\n";
	memset(pi,0,sizeof(pi));
	memset(a,0,sizeof(a));
	}
	return 0;
}
