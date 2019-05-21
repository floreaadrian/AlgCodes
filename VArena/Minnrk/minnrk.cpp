#include<stdio.h>

int fr[9];

int main()
{
	FILE *fin,*fout;
	int n,cf,i,k,no;
	char c;
	fin=fopen("minnrk.in","r");
	fout=fopen("minnrk.out","w");
	c=fgetc(fin);
	while(c!=' ')
	{
		fr[c-'0']++;
		c=fgetc(fin);
	}
	fscanf(fin,"%d",&k);
	fclose(fin);
	c=1;
	while(fr[c]==0)
	  c++;
	fputc(c+'0',fout);
	  fr[c]--;
	c=0;
	for(i=1;i<k;i++)
	{
		while(fr[c]==0)
		c++;
		fputc(c+'0',fout);
		fr[c]--;
	}
	fputc('\n',fout);
	fclose(fout);
	return 0;
}
