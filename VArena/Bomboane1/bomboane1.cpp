#include<stdio.h>

int main()
{
	FILE *fin,*fout;
	char c;
	int s,nr,d;
	s=nr=0;
	fin=fopen("bomboane1.in","r");
	c=fgetc(fin);
	while(c!='\n')
	{
		if(c!='$')
		{
			if(c=='P')
			{
				s+=nr;
				nr=0;
			}else
			if(c=='C')
			{
				if(nr<=s)
				s-=nr;
				nr=0;
			}
			else
			nr=nr*10+c-'0';
		}
		c=fgetc(fin);
	}
	fclose(fin);
	d=2;
	while(s%d>0)
	d++;
	fout=fopen("bomboane1.out","w");
	fprintf(fout,"%d\n%d\n",s,d);
	fclose(fout);
	return 0;
}
