/*
ID: florea.2
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
    FILE *fin,*fout;
    fin = fopen("milk.in","r");
    fout = fopen("milk.out","w");
    int n,m,p,a,pr[1001]={0};
    fscanf(fin,"%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        fscanf(fin,"%d%d",&p,&a);
        pr[p]+=a;
    }
    int cost=0;
    for(int i=0;i<=1000;i++)
        if(pr[i]){
            if(pr[i] >= n){
                cost+= i*n;
                break;
            }else{
            cost+= i*pr[i];
            n-=pr[i];
            }
        }
    fprintf(fout,"%d\n",cost);
    return 0;
}
