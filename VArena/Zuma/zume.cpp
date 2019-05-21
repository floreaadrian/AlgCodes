#include<stdio.h>

char s[200];

int main()
{
	FILE *fin,*fout;
	int n,i,j,di,dj,start,end;
	char c;
	fin=fopen("zuma.in","r");
	fscanf(fin,"%d ",&i);
	n=0;
	c=fgetc(fin);
	while(c!='\n'){
		s[n]=c;
		n++;
		c=fgetc(fin);
	}
	fclose(fin);
	i--;
	start=i;
	end=i+1;
	if(i>0 && i<(n-1) && s[i]==s[i-1] && s[i]==s[i+1]){
		j=end;
		di=2;
		dj=1;
		while(di>0 && dj>0 && di+dj>=3){
			start=i;
			end=j;
			c=s[i];
			while(i>=0 && s[i]==c)
			i--;
			while(j<n && s[j]==c)
			j++;
			di=start-i;
			dj=j-end;
		}
	}
	fout=fopen("zuma.out","w");
	for(i=0;i<=start;i++)
	fputc(s[i],fout);
	for(i=end;i<n;i++)
	fputc(s[i],fout);
	fputc('\n',fout);
	fclose(fout);
	return 0;
}
