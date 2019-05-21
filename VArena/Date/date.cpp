#include<fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int szile[12]={0,31,28,31,30,31,30,31,31,30,31,30};

int main()
{
	int i,z1,l1,a1,z2,l2,a2,nbisect,nz1,nz2;
	for(i=2;i<12;i++)
	szile[i]+=szile[i-1];
	fin>>z1>>l1>>a1>>z2>>l2>>a2;
	fin.close();
	a1--;
	nbisect=a1/4-a1/100+a1/400;
	nz1=a1*365+nbisect+szile[l1-1]+z1;
	a1++;
	if(l2>2 && ((a1%400==0) || ((a1%4==0) && (a1%100!=0))))
	nz1++;
	a2--;
	nbisect=a2/4-a2/100+a2/400;
	nz2=a2*365+nbisect+szile[l2-1]+z2;
	a2++;
	if(l2>2 && ((a2%400==0) || ((a2%4==0) && (a2%100!=0))))
    nz2++;
	fout<<nz2-nz1;
	fout.close();
	return 0;
}
