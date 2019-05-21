#include<stdio.h>

int a[100][100];

int main()
{
	FILE *fin,*fout;
	int m,n,l,c,aux;
	char ch;
	fin=fopen("matrix.in","r");
	for(l=0;l<n;l++)
	for(c=0;c<m;c++)
	fscanf(fin,"%d",&a[l][c]);
	ch=fgetc(fin);
	ch=fgetc(fin);
	while(ch!='\n'){
		if(ch=='F'){
			ch=fgetc(fin);
			if(ch=='H'){
				for(l=0;l<m/2;l++)
         		for(c=0;c<n;c++){
            	aux=a[l][c];
            	a[l][c]=a[m-1-l][c];
            	a[m-1-l][c]=aux;
          		}
				  }else{
          			for(c=0;c<n/2;c++)
          			for(l=0;l<m;l++){
           			aux=a[l][c];
            		a[l][c]=a[l][n-1-c];
            		a[l][n-1-c]=aux;
				  }
			}
		}else
		{             
      		ch=fgetc(fin);
      		if(ch=='H'){ 
        		for(l=0;l<m;l++){
          		aux=a[l][n-1];
          		for(c=n-1;c>0;c--)
            	a[l][c]=a[l][c-1];
          		a[l][0]=aux;
        		}
      			}else{          
        		  for(c=0;c<n;c++){
          		  aux=a[m-1][c];
          		  for(l=m-1;l>0;l--)
            	  a[l][c]=a[l-1][c];
          		  a[0][c]=aux;
        		  }
      		  }
    	}
    ch=fgetc(fin);
	}
	fclose(fin);
	fout=fopen("matrix.out","w");
	for(l=0;l<n;l++)
	{
		for(c=0;c<m;c++)
		fprintf(fout,"%d ",a[l][c]);
		fprintf(fout,"\n");
	}
	fclose(fout);
	return 0;
}
