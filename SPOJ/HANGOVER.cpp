#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main()
{
    float a;
    cin>>a;
    while(a!=0.00)
    {
        float sum=0;
        int k=1;
        while(sum<=a)
        {
            sum=sum+(float)1/(i+1);
            i++;
        }
        printf("%d card(s)",i-1);
        cin>>a;
    }
    return 0;
}
