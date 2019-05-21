#include<iostream>
#include<string.h>
using namespace std;
char caracter(char c){
   if( c >= 'A' && c <= 'Z')
      return c;
   else if( c >= 'a' && c <= 'z' )
      return c-('a'-'A');
}
int main()
{
	
	 bool danca;
   char str[1001];
	  while( gets(str) ){
      
      danca=true;
      for(int i=0; str[i] != '\0'; i++){
         if( str[i] != ' ' ){
            if( danca ){
               str[i] = caracter(str[i]);
               danca=false;
            }else{
               danca=true;
            }
         }

      }
      cout << str << "\n";


   }
   

	return 0;
}
