#include<stdio.h>

int main()
{
	FILE *fin,*fout;
	char c;
	fin=fopen("cezar.in","r");
	fout=fopen("cezar.out","w");
	c=fgetc(fin);
	while(c!='\n')
	{
		c='a'+(c-'a'+1)%26;
		fputc(c,fout);
		c=fgetc(fin);
	}
	fclose(fin);
	fputc('\n',fout);
	fclose(fout);
	return 0;
}
