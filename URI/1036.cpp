#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
double a,b,c,r1,r2,d;
scanf("%lf %lf %lf",&a,&b,&c);
d=(pow(b,2)-(4*a*c));
r1=(-b+sqrt(d))/(2*a);
r2=(-b-sqrt(d))/(2*a);
if(a!=0 && d>0)
{
    cout<<"R1 = "<<fixed<<setprecision(5)<<r1<<"\n"<<"R2 = "<<r2<<"\n";
}
else{
    printf("Impossivel calcular\n");
}

return 0;
}
