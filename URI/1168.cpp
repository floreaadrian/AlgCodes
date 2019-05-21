#include<iostream>
#include <fstream>
using namespace std;
int main()
{
 
 
int led[10];
 
led[0]=6;
led[1]=2;
led[2]=5;
led[3]=5;
led[4]=4;
led[5]=5;
led[6]=6;
led[7]=3;
led[8]=7;
led[9]=6;
int n,i,leduri=0;
char c;
cin>>n;
for(i=1;i<=n;i++)
  {
    leduri=0;
    do
        {cin>>c;
 
         leduri=leduri+led[(int)(c-48)];
            }
while (cin.peek()!='\n');
        cout<<leduri<<" leds"<<endl;
  }
 
  return 0;
}
