#include <bits/stdc++.h>
using namespace std;

int mm=0x3f3f3f3f;
int n,a,b,c;

void back(int x,int cost){
	if (x%4==0){
		mm = min(mm,cost);
		return;
	}
	if (x<0) return;
	if (cost>=mm) return;
	back(x+1,cost+a);
	back(x+2,cost+b);
	back(x+3,cost+c);
}

int main() {
	scanf("%d %d %d %d",&n,&a,&b,&c);
	if (n%4==0){
		printf("0");
	}else{
		back(n,0);
		printf("%d",mm);
	}
	return 0;
}
