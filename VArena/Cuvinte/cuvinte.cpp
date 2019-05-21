#include<stdio.h>

int main()
{
	FILE *fin,*fout;
	int n,incuv;
	char c;
	fin=fopen("cuvinte.in","r");
	c=fgetc(fin);
	incuv=n=0;
	while(c!='\n')
	{
	if(c!=' ' && c!=',' && c!='.')
	{
		if(incuv==0)
		{
			n++;
			incuv=1;
		}
	}
		else
		incuv=0;
		c=fgetc(fin);
    }
	fclose(fin);
	fout=fopen("cuvinte.out","w");
	fprintf(fout,"%d",n);
	fclose(fout);
	return 0;
}
