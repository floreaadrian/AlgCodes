#include<iostream>
#include<string.h>
using namespace std;


	int car_dis = 0,n;
    char s[105];
    bool apare[30];
    
int main()
{
	cin>>s;
	n=strlen(s);
	
	for(int i = 0 ; i < n ; ++ i)
		if(!apare[s[i] - 'a']){

			++car_dis;
			apare[s[i] - 'a']=1;
		}
			
	if(car_dis%2==0)
		cout<<"CHAT WITH HER!";
	else 
		cout<<"IGNORE HIM!";
}
