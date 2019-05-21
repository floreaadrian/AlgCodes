//S1-b)
bool factprim(int n)
{
	int p=2,c=0;
	while(n>1)
	{
		while(n%p==0){
			c++;
			n=n/p;
		}
		if(c%2==0 && c!=0) return true;
		p++;
		c=0;
	}
	return false;
}
//
//
//
//
//S2-c)
bool dis(int n,int x[])
{
	for(int i=1;i<n;++i)
		if(x[i]==x[i+1]) return false;
	return true;
}

bool disre(int n,int x[])
{
	if(n==0) return true;
	if(x[n]==x[n-1])return false;
	disre(n-1,x);
}
//
//
//
//
//S3
