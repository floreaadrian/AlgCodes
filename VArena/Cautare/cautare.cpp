#include<stdio.h>

char a[100][100],b[100][100];

int main()
{
	FILE *fin,*fout;
	int m,n,lin,col,c,l,nrap;
	fin=fopen("cautare.in","r");
	fscanf(fin,"%d%d ",&m,&n);
	for(l=0;l<m;l++){
		for(c=0;c<m;c++)
		a[l][c]=fgetc(fin);
		fgetc(fin);
	}
	for(l=0;l<n;l++){
		for(c=0;c<n;c++)
		b[l][c]=fgetc(fin);
		fgetc(fin);
	}
	fclose(fin);
	nrap=0;
	for(lin=0;lin<=m-n;lin++)
	for(col=0;col<=m-n;col++)
	{
		l=c=0;
		while(l<n && a[lin+l][col+c]==b[l][c]){
			c++;
			if(c>=n){
				l++;
				c=0;
			}
		}
		if(l>=n)
		nrap++;
	}
	fout=fopen("cautare.out","w");	
	fprintf(fout,"%d\n",nrap);
	fclose(fout);
	return 0;
}
