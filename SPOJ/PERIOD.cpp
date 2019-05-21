#include <iostream>
#include <string.h>
#include <vector>
 
using namespace std;
 
const int maxn = 2000005;
 
char a[maxn];
int n, pi[maxn];
 
int main() {
    int t,len,c=1;
    cin>>t;
    while(t--){
    cin>>len;
    cin >> a + 1;
    n = strlen(a + 1);
    cout<<"Test case #"<<c++<<"\n";
    int k = 0;
    for(int i = 2 ; i <= n ; ++ i) {
        while(k > 0 && a[k + 1] != a[i])
            k = pi[k];
        if(a[k + 1] == a[i])
            ++ k;
        pi[i] =  k;
	}
	int solve=0;
	for(int i=2;i<=n;i++)
	if(pi[i] && !(i % (i - pi[i])))
	{
		cout<<i<<" "<<i / (i - pi[i])<<"\n";
	}
	memset(pi,0,sizeof(pi));
	memset(a,0,sizeof(a));
	}
	return 0;
}
