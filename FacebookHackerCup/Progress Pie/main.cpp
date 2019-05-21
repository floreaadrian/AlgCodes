#include<bits/stdc++.h>
#define pi 3.14159265

using namespace std;

int main()
{
    FILE *fin,*fout;
    fin = fopen("input.in","r");
    fout = fopen("output.out","w");
    int t;
    fscanf(fin,"%d",&t);
    for(int i=1;i<=t;i++)
    {
        int pr,x,y;
        fscanf(fin,"%d%d%d",&pr,&x,&y);
        float unghi_cerc=(pr*2*pi)/(100.0);
        float unghi_pct=atan((float)(y-50)/(x-50));
        float distance=sqrt(pow(x-50,2)+pow(y-50,2));
        if(distance>50)
            fprintf(fout,"Case #%d: white\n",i);
        else
        {
            if(x>=50 && y>=50)
            {
              if(unghi_pct+unghi_cerc>=pi/2 && !(x==50 && unghi_cerc==(float)0))
              fprintf(fout,"Case #%d: black\n",i);
              else
              fprintf(fout,"Case #%d: white\n",i);

            }
            else if(x<50 && y<50)
            {
              if(unghi_pct+unghi_cerc>=3*pi/2)
               fprintf(fout,"Case #%d: black\n",i);
              else
                fprintf(fout,"Case #%d: white\n",i);
            }
            else if(x<50 && y>=50)
            {
              if(unghi_pct+unghi_cerc>=3*pi/2)
                fprintf(fout,"Case #%d: black\n",i);
              else
                fprintf(fout,"Case #%d: white\n",i);
            }
            else if(x>=50 && y<50)
            {
              if(unghi_pct+unghi_cerc>=pi/2)
              fprintf(fout,"Case #%d: black\n",i);
              else
              fprintf(fout,"Case #%d: white\n",i);

            }
        }
    }
    return 0;
}
