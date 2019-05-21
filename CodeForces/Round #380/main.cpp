#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

 int main(){
 	std::ios::sync_with_stdio(false);
 	int n,m;
 	cin>>n>>m;
 	vector < vector <int> > a(n,vi(m,0));
 	for(int i=0;i<n;++i)
 		for(int j=0;j<m;++j)
 			cin>>a[i][j];
 		int c=0;
 		for(int i=0;i<n;++i)
 		for(int j=0;j<m;++j)
 					if(a[i][j]==0){
 						for(int x=j-1;x>=0;x--)
 							if(a[i][x]==1){
 								c++;
 								break;
 							}
 						for(int x=j+1;x<m;x++)
 							if(a[i][x]==1){
 								c++;
 								break;
 							}
 						for(int x=i-1;x>=0;x--)
 							if(a[x][j]==1){
 								c++;
 								break;
 							}
 						for(int x=i+1;x<n;x++)
 							if(a[x][j]==1){
 								c++;
 								break;
 							}
        }
    cout<<c<<"\n";
    return 0;
}
