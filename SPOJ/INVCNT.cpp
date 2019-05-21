#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
 
#define MAXN 10000000 + 5
using namespace std;
 
int tree[MAXN];
int inp[200000 + 5];
int n;
int maxVal;
 
 
int read(int idx){
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 
void update(int idx, int val){
    while(idx <= maxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        maxVal = 0;
        for(int i = 0 ; i < n ; i++){
            cin>>inp[i];
            maxVal = max(maxVal, inp[i]);
        }
        long long res = 0;
        memset(tree, 0, sizeof(tree));
        for(int i = n - 1; i >= 0 ; i--){
            res += read(inp[i] - 1);
            update(inp[i], 1);
        }
        cout<<res<<"\n";
    }
}
