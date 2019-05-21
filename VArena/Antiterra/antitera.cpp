#include<stdio.h>

int main()
{
	FILE *fin,*fout;
	fin=fopen("antiterra.in","r");
	int n,s;
	char c;
	c=' ';
	s=0;
	while(c!='\n')
	{
		fscanf(fin,"%d",&n);
		c=fgetc(fin);
		if(c=='-')
		{
		n=-n;
		c=fgetc(fin);
		}else if(c=='+')
		c=fgetc(fin);
		s+=n;	
	}
	fclose(fin);
	fout=fopen("antiterra.out","w");
	fprintf(fout,"%d",s);
	fclose(fout);
	return 0;
}
