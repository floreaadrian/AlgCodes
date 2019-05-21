#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>


using namespace std;

#define maxn 10004

struct Station{
 int dis;
 int fuel;
 bool operator <(const Station& p) const{
   return dis > p.dis;
 }
};
Station a[maxn];
int heap[maxn];
int cur_in;
void insert(int x){
  cur_in++;
  int i=cur_in;
  while(i!=1){
    if(heap[i/2]<x)heap[i]=heap[i/2];
    else break;
    i/=2;
  }
  heap[i]=x;
}
int dmax(){
  if(cur_in==0) return -1;
  int max=heap[1];
  int value = heap[cur_in--];
  int i=1,fiu;
  while(i*2<=cur_in){
    fiu = (i*2);
    if((fiu+1) <= cur_in && heap[fiu+1] > heap[fiu]) fiu++;
    if(heap[fiu]>value) heap[i]=heap[fiu];
    else break;
    i=(fiu);
  }
  heap[i]=value;
  return max;
}
int comp(const void *_x,const void *_y){
    Station *x=(Station *)_x,*y=(Station *)_y;
        return y->dis-x->dis;
}
int main(){
  int n,i,k,t,fuel,dis;
  cin>>t;
  while(t--){
    cin>>n;
    for(i=n-1;i>=0;i--){
      cin>>a[i].dis>>a[i].fuel;
    }
    a[n].dis=0;
    a[n].fuel=0;
    sort(a,a+(n+1));
    cin>>dis>>fuel;
    i=0;k=0;cur_in=0;
    while(i<=n){
      while(i<=n && (dis - a[i].dis <= fuel)){
	fuel -= (dis-a[i].dis);
	dis = a[i].dis;
        insert(a[i].fuel);
	i++;
      }
      if(i<=n){
        int temp = dmax();
	if(temp==-1){
	  k=-1;
	  break;
	}
	fuel += temp;
        k++;
      }
    }
    cout<<k<<'\n';
  }
  return 0;
}
