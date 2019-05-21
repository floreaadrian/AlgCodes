#include<iostream>
#include<cstring>
using namespace std;
char pat[1000010];
char text[1000010];
int pref[1000010];
void prefix(char *s)
{
 int n=strlen(s),flag=1;
 int j=0,i;
 pref[0]=0;
 for(int i=1;i<n;i++)
 {
  while(j>0 && s[j]!=s[i])
  j=pref[j-1];
  if(s[i]==s[j]) 
  j++;
  pref[i]=j;
 }
 
 
}
void search(char *text,char *pat)
{
 int len=strlen(text),flag=1;
 int m=strlen(pat);
 int j=0;
 for(int i=0;i<len;i++)
 {
  while(j>0 && text[i]!=pat[j])
  j=pref[j-1];
  if(text[i]==pat[j])
  j++;
  if(j==m)
  {
  cout<<i-m+1<<"\n";
  j=pref[j-1];
  }
 }
 if(flag==1)
        cout<<"\n";
}
int main()
{
 int n;
 while(cin>>n)
        {
      memset(pref,0,sizeof(pref));
      cin>>pat;
  prefix(pat);
  cin>>text;
  search(text,pat);
 }
 
} 
