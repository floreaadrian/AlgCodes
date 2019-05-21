#include<stdio.h>

char c;

int main()
{
	FILE *fin,*fout;
	int a,b,s,tip,p10;
	fin=fopen("ecuatie2.in","r");
	p10=0;
	a=b=s=0;
	c=fgetc(fin);
	fout=fopen("ecuatie2.out","w");
	if(c=='x')
	{
		c=fgetc(fin);
		if(c=='+'){
			tip=2;
		}else if(c=='-'){
			tip=4;
		}else if(c=='*'){
			tip=6;
		}else if(c==':'){
			tip=8;
		}
		c=fgetc(fin);
		while(c!='=')
		{
			a=a*10+c-'0';
			c=fgetc(fin);
		}
		c=fgetc(fin);
		while(c!='\n')
		{
			b=b*10+c-'0';
			c=fgetc(fin);
		}
	}else {
	while(c!='-' && c!='+' && c!='*' && c!=':'){
		a=a*10+c-'0';
		c=fgetc(fin);
	}
	if(c=='+'){
		tip=1;
	}else if(c=='-'){
		tip=3;
	}else if(c=='*'){
		tip=5;
	}else if(c==':'){
		tip=7;
	}
	fgetc(fin);
	fgetc(fin);
	c=fgetc(fin);
	while(c!='\n'){
		b=b*10+c-'0';
		c=fgetc(fin);
	}
	}
	fclose(fin);
	
	if(tip==2 || tip==1)
	s=b-a;
	if(tip==3)
	s=a-b;
	if(tip==4)
	s=a+b;
	if(tip==5 || tip==6)
	s=b/a;
	if(tip==7)
	s=a/b;
	if(tip==8)
	s=a*b;
	fprintf(fout,"%d\n%d ",tip,s);
	fclose(fout);
	return 0;
}
