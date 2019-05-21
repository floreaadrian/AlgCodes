#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
        scanf("%d",&n);
		if(n%2==0)
		for(int i=1;i<=n;i=i+2){
			if(i+1<=n){
				printf("%d ",i+1);
			}
			printf("%d ",i);
		}else if(n%2==1){
            int k=n-3;
            for(int i=1;i<=k;i=i+2)
            {
                if(i+1<=k){
				printf("%d ",i+1);
			    }
                printf("%d ",i);
            }
            printf("%d %d %d",n-1,n,n-2);
        }
		printf("\n");
	}
	return 0;
}
