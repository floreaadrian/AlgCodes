#include<stdio.h>

int v[10];

int main()
{
	FILE *fin,*fout;
	int n,i;
	char c;
	fin=fopen("magic1.in","r");
	fout=fopen("magic1.out","w");
	fscanf(fin,"%d ",&n );
	for(i=0;i<n;i++){
		c=fgetc(fin);
		fgetc(fin);
		if(c>='0' && c<='9')
		v[c-'0']=1;
		else
		{
		if(c<='z')
			c='A'+(c-'a');
			fputc(c,fout);
		}
	}
	fputc('\n',fout);
	fclose(fin);
	i=1;
	while(v[i]==0)
	i++;
	fputc(i+'0',fout);
	v[i]=0;
	for(i=0;i<10;i++)
	if(v[i]==1)
	fputc(i+'0',fout);
	fputc('\n',fout);
	fclose(fout);
	return 0;
}
