#include<stdio.h>

int ord[26];

int main()
{
	FILE *fin,*fout;
	int i,l,lmax,nmax;
	char c1,c2;
	fin=fopen("degrade.in","r");
	for(i=0;i<10;i++){
		c1=fgetc(fin);
		ord[c1-'a']=i;
	}
	fgetc(fin);
	l=1;
	lmax=1;
	nmax=1;
	c1=fgetc(fin);
	c2=fgetc(fin);
	while(c2!='\n'){
		if(ord[c2-'a']>=ord[c1-'a'])
		l++;
		else
		l=1;
		if(l>lmax){
			lmax=l;
			nmax=1;
		}else if(l==lmax)
		nmax++;
		c1=c2;
		c2=fgetc(fin);
	}
	fclose(fin);
	fout=fopen("degrade.out","w");
	fprintf(fout,"%d %d",lmax,nmax);
	fclose(fout);
	return 0;
}
