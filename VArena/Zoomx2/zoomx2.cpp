#include<stdio.h>

char m1[51][51],m2[102][102];

int main()
{
	FILE *fin,*fout;
	int n,i,j;
	fin=fopen("zoomx2.in","r");
	fscanf(fin,"%d ",&n);
	for(i=0;i<n;i++){
	for(j=0;j<n;j++)
		m1[i][j]=fgetc(fin);
		fgetc(fin);
	}
	fclose(fin);
	n*=2;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		m2[i][j]=m1[i/2][j/2];
	fout=fopen("zoomx2.out","w");
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	fputc( m2[i][j], fout);
	fputc('\n',fout);
	}
	fclose(fout);
	return 0;
}
