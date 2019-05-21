#include<stdio.h>

int main()
{
	FILE *fin,*fout;
	char c;
	int n;
	fin=fopen("cezark.in","r");
	fout=fopen("cezark.out","w");
	fscanf(fin,"%d",&n);
	c=fgetc(fin);
	c=fgetc(fin);
	while(c!='\n')
	{
		c='a'+(c-'a'+n)%26;;
		fputc(c,fout);
		c=fgetc(fin);
	}
	fclose(fin);
	fputc('\n',fout);
	fclose(fout);
	return 0;
}
