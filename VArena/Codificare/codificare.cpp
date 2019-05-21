#include<stdio.h>

char cod[100][20];

int main(){
	FILE *fin,*fout;
	int n,m,c,l,pas;
	char car;
	fin=fopen("codificare.in","r");
	fscanf(fin,"%d ",&n);
	l=c=0;
	pas=1;
	car=fgetc(fin);
	while(car!='\n'){
		cod[l][c]=car;
		c+=pas;
		if(c<0 || c>=n){
			c-=pas;
			pas=-pas;
			l++;
		}
		car=fgetc(fin);
	}
	fclose(fin);
	m=l;
	fout=fopen("codificare.out","w");
	for(c=0;c<n;c++)
	for(l=0;l<m;l++)
	fputc(cod[l][c],fout);
	fclose(fout);
	return 0;
}
