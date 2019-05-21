#include<stdio.h>

int main()
{
	FILE *fin,*fout;
	fin=fopen("fgetc.in","r");
	fout=fopen("fgetc.out","w");
	char c;
	int n=0;
	c=fgetc(fin);
	while(c!='\n')
	{
		n=n*10+c-'0';
		c=fgetc(fin);
	}
	fclose(fin);
	fprintf(fout,"%d",n);
	fclose(fout);
	return 0;
}
