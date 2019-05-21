#include<iostream>
using namespace std;

long long A[100000],B[100000],C[100000],D[100000];

void add(int A[], int B[])
{
      int i, t = 0;
      for (i=1; i<=A[0] || i<=B[0] || t; i++, t/=10)
              A[i] = (t += A[i] + B[i]) % 10;
      A[0] = i - 1;
}

void sub(int A[], int B[])
{
      int i, t = 0;
      for (i = 1; i <= A[0]; i++) {
              A[i] -= ((i <= B[0]) ? B[i] : 0) + t;
              A[i] += (t = A[i] < 0) * 10;
      }
      for (; A[0] > 1 && !A[A[0]]; A[0]--);
}

void golire()
{
	for int
}

int main()
{
	int t;
	string b,c,d;
	cin>>t;
	while(t--){
		cin>>b>>c>>d;
		cout<<sub(C,B)+(C-D);
	}
	return 0;
}
