#include<bits/stdc++.h>

using namespace std;

int main(){
	int t ;
	int v_size;
	cin>>t;
	while(t--){
		int n;
		int i,k;
		cin>>n;
		if((n%3) ==0){
			v_size = 2*(n/3);
		}
		else if(((n-1)%3)==0){
			v_size = (2*((n-1)/3)) +1;
		}

		else{
			v_size =(2*((n-2)/3))+2;
		}
		if(v_size ==1) {
			cout<<"b\n";
			continue;
		}
		else if(v_size==2){
			cout<<"ba\n";
			continue;
		}
		else if(v_size==3){
			cout<<"bb\n";
			continue;
		}
		char v[v_size];
	if(!((n-2)%3 ==0)){
	for(i=0;i<v_size;i+=3){
		v[i]='a';
		v[v_size-i-1] = v[i];
		v[i+1]='b';
		v[v_size-i-2]=v[i+1];
		v[i+2]='c';
		v[v_size-i-3]=v[i+2];
	}
    }
    else {
	for(i=0;i<v_size-1;i+=3){
		v[i]='a';
		v[v_size -i-2] = v[i];
		v[i+1]='b';
		v[v_size-i-3]=v[i+1];
		v[i+2]='c';
		v[v_size-i-4]=v[i+2];

    }
    v[v_size]= 'd';
	}
	for(i=0;i<v_size;i++)cout<<v[i];
	cout<<"\n";
	}
	return 0;
}


