#include<iostream>
#include<string.h>

using namespace std;

char a[256],v[]="aeiou",l[]="bcdfghjklmnpqrstvwxyz";//22-5

bool vo(int i)
{
    for(int j=0;j<5;++j)
    if(v[j]==a[i])return true;
    return false;
}

bool co(int i){
    for(int j=0;j<21;++j)
        if(l[j]==a[i])return true;
    return false;
}

int main()
{

 int p,c=0,i;
 cin.getline(a,256);
 p=strlen(a);
 for(i=0;i<p;++i)
 {
 	if(co(i-1) && vo(i) && co(i+1))
 	c++;
 }
 cout<<c;
}
