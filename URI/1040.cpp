#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    float a,b,c,d,z,medie,re,exam,ex;

    scanf("%f %f %f %f",&a,&b,&c,&d);

    medie=(((a*2)+(b*3)+(c*4)+(d*1))/10);

    printf("Media: %.1f\n",medie);


    if(medie>=7.0)
    {
        printf("Aluno aprovado.\n");
    }
    if(medie<5.0)
    {
        printf("Aluno reprovado.\n");
    }
    if(medie>=5.0 && medie<=6.9)
    {
        printf("Aluno em exame.\n");
        exam=z;

        scanf("%f",&ex);
        printf("Nota do exame: %.1f\n",ex);

        re=(medie+ex)/2;


        if(re>=5.0)
        {
            printf("Aluno aprovado.\n");
            printf("Media final: %.1f\n",re);
        }
        else if(re<=4.9)
        {
            printf("Aluno reprovado.\n");
            printf("Media final: %.1f\n",re);
        }

    }


    return 0;
}
