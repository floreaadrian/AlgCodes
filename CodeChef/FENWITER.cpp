#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
    cin>>t;
    while(t--){
    	string l1,l2,l3;
    	int n;
    	cin>>l1>>l2>>l3;
    	scanf("%d",&n);
    	int l1l=l1.length();
    	int l2l=l2.length();
    	int l3l=l3.length();
    	int cl3=0,cl2=0,cl1=0,x=0;
    	int ok=0,ok1=0,ok2=0;
    	for(int i=l3l-1;i>=0;i--){
    		if(l3[i]=='0'&&ok==0){
    			ok=1;
    			l3[i]='1';
    	}
    		if(ok==1&&l3[i]=='1') cl3++;
    	}
    	for(int i=0;i<l2l;i++)
    		if(l2[i]=='1')
    			x++;
    	if(ok==0){
    		 ok2=0;
    			ok1=1;
    	for(int i=l2l-1;i>=0;i--){
   				if(l2[i]=='0'&&ok==0){
   					ok2=1;
   					l2[i]='1';
    			}
    			if(ok2==1&&l2[i]=='1') cl2++;
    	}
    	}
    	else ok2=1;
    	if(ok2==0){
    		 ok=0;
    	for(int i=l1l-1;i>=0;i--){
    			if(l1[i]=='0'&&ok==0){
    				ok=1;
    				l1[i]='1';
   				}
   				if(ok==1&&l1[i]=='1') cl1++;
   		}
   		}
    	else{
    		for(int i=0;i<l1l;i++)
    			if(l1[i]=='1')
    				cl1++;
    	}
    		if(ok1==0)
    			printf("%d\n",cl1+n*x+cl3);
    		else if(ok1==1&&ok2==1)
    			printf("%d\n",cl1+(n-1)*x+cl2+cl3);
    		else if(ok1==1&&ok2==0)
    				{
    				    int ans=cl1+n*cl2+cl3;
    				    if(ans==0)
                            printf("1\n");
                        else
    				    printf("%d\n",ans);
    				}
    	}
	 return 0;
}
