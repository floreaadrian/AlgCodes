#include<stdio.h>

int main()
{
	FILE *fin,*fout;
	char c;
	int s=0,n;
	fin=fopen("plusminus.in","r");
	fscanf(fin,"%d",&s);
	c=fgetc(fin);
	while(c==' ')
	{
		c=fgetc(fin);
		fscanf(fin,"%d",&n);
		if(c=='+')
		s+=n;
		else
		s-=n;
		c=fgetc(fin);
	}
	fclose(fin);
	fout=fopen("plusminus.out","w");
	fprintf(fout,"%d",s);
	fclose(fout);
	return 0;
}
