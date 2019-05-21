#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int sum[1005];

int main(){
	int n, m;
	scanf("%d%d",&n,&m);
	vector<int>a(n);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	vector<int>l(m), r(m);
	for(int i=0;i<m;++i)scanf("%d%d",&l[i],&r[i]);
	for(int j=0;j<m;++j){
		for(int i=0;i<n;++i){
			if (i + 1 >= l[j] && i + 1 <= r[j])sum[j] += a[i];
		}
	}
	int res = 0;
	for(int i=0;i<m;++i){
		if (sum[i] + res > res)res += sum[i];
	}
	printf("%d",res);
	return 0;
}
