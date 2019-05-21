#include <fstream>
#include <math.h>

using namespace std;

ifstream fin("kbiti.in");
ofstream fout("kbiti.out");

int binaryToBase10(int n) {

    int output = 0;

    for(int i=0; n > 0; i++) {

        if(n % 10 == 1) {
            output += pow(2, i);
        }
        n /= 10;
    }

    return output;
}


int main()
{
    int k,a;
    fin>>k;
    for(int i=1;i<=k;i++){
        fin>>a;
        int b=binaryToBase10(a)+1;
        fout<<b<<"\n";
    }
    return 0;
}
