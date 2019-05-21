#include<stdio.h>

char cifre[32];

int main()
{
	FILE *fin,*fout;
	int n,i,nc,b;
	long long k;
	char ch;
	fin=fopen("ascunsa.in","r");
	fscanf(fin,"%d ",&n);
	nc=b=0;
	ch=fgetc(fin);
	while(ch!='\n'){
		if(ch<='9')
		cifre[nc]=ch-'0';
		else
		cifre[nc]=ch-'A'+10;
		if(cifre[nc]>b)	
		b=cifre[nc];
		nc++;
		ch=fgetc(fin);
	}
	fclose(fin);
	do{
	  b++;
	  k=0;
	  for(i=0;i<nc;i++)
	  k=k*b+cifre[i];	
	}while(k<=n);
	fout=fopen("ascunsa.out","w");
	fprintf(fout,"%lld %d\n",k,b);
	fclose(fout);
	return 0;
}
