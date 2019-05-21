#include<stdio.h>

char a[99][99];

char forme[12][3][3] = {
  { { 1, 0, 0 },
    { 1, 0, 0 },
    { 1, 1, 1 } },
  { { 1, 1, 1 },
    { 1, 0, 0 },
    { 1, 0, 0 } },
  { { 1, 1, 1 },
    { 0, 0, 1 },
    { 0, 0, 1 } },
  { { 0, 0, 1 },
    { 0, 0, 1 },
    { 1, 1, 1 } },
  { { 1, 0, 0 },
    { 1, 1, 1 },
    { 1, 0, 0 } },
  { { 1, 1, 1 },
    { 0, 1, 0 },
    { 0, 1, 0 } },
  { { 0, 0, 1 },
    { 1, 1, 1 },
    { 0, 0, 1 } },
  { { 0, 1, 0 },
    { 0, 1, 0 },
    { 1, 1, 1 } },
  { { 0, 1, 1 },
    { 1, 1, 0 },
    { 0, 1, 0 } },
  { { 0, 1, 0 },
    { 1, 1, 1 },
    { 0, 0, 1 } },
  { { 0, 1, 0 },
    { 0, 1, 1 },
    { 1, 1, 0 } },
  { { 1, 0, 0 },
    { 1, 1, 1 },
    { 0, 1, 0 } }
};

int main()
{
	FILE *fin,*fout;
	int m,n,l,c,lin,col,i,nrap;
	fin=fopen("joc1.in","r");
	fscanf(fin,"%d%d ",&n,&m);
	for(l=0;l<n;l++){
	for(c=0;c<m;c++)
		a[l][c]=fgetc(fin)-'0';
		fgetc(fin);
	}
	fclose(fin);
	nrap=0;
	for(lin=0;lin<=n-3;lin++)
	for(col=0;col<=m-3;col++){
		for(i=0;i<12;i++){
			l=c=0;
			while(l<3 && ((a[lin+l][col+c]==1) || (a[lin+l][col+c]==forme[i][l][c]))){
				c++;
				if(c>=3)
				{
					l++;
					c=0;
			}
		}
		if(l>=3)
		nrap++;
	  }
	}
	fout=fopen("joc1.out","w");
	fprintf(fout,"%d\n",nrap);
	fclose(fout);
	return 0;
}
