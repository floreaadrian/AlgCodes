#include<stdio.h>

char a[100][100];

int main()
{
	FILE *fin,*fout;
	int n,i,j;
	char ch;
	fin=fopen("diagonal.in","r");
	n=0;
	ch=fgetc(fin);
	while(ch!='\n'){
		a[0][n]=ch;
		n++;
		ch=fgetc(fin);
	}
	for(i=1;i<n;i++){
		for(j=0;j<n;j++)
		a[i][j]=fgetc(fin);
		fgetc(fin);
	}
	fclose(fin);
	fout=fopen("diagonal.out","w");
	for(i=n-1;i>0;i--)
	for(j=0;j<n-i;j++)
	fputc(a[i+j][j],fout);
	for(j=0;j<n;j++)
	for(i=0;i<n-j;i++)
	fputc(a[i][i+j],fout);
	fputc('\n',fout);
	for(j=0;j<n;j++)
	for(i=0;i<=j;i++)
	fputc(a[i][j-i],fout);
	for(i=1;i<n;i++)
	for(j=n-1;j>=i;j--)
	fputc(a[n-1+i+j][j],fout);
	fputc('\n',fout);
	fclose(fout);
	return 0;
}
