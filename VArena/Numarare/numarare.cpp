#include<stdio.h>

int main()
{
	FILE *fin,*fout;
	char c;
	int inc=0,inr=0,nr=0,cv=0;
	fin=fopen("numarare.in","r");
	c=fgetc(fin);
	if(c>='a' && c<='z')
	{
		inc=1;
		cv=1;
	}else{
		inr=1;
		nr=1;
	}
	while(c!=EOF){
		c=fgetc(fin);
		if(inc){
			if(c>='0' && c<='9'){
				inc=0;
				inr=1;
				nr++;
			}else if(c>='a' && c<='z')
					{
						inc=1;
						inr=0;
					}
		}else
		if(inr){
			if(c>='a' && c<='z'){
				inc=1;
				inr=0;
				cv++;
			}else if(c>='0' && c<='9')
					{
					inc=0;
					inr=1;
					}
		}else
		c=fgetc(fin);
	}
	fclose(fin);
	fout=fopen("numarare.out","w");
	fprintf(fout,"%d\n%d",cv,nr);
	fclose(fout);
	return 0;
}
