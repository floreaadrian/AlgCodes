//S1-a)
void turnuri(int n, int &nrTurnuri, int &nrMonede) {
	nrMonede = 0;
	nrTurnuri = 0;
	int putere = 1;
	for (int inaltime = n; inaltime >= 1; inaltime--){
		nrTurnuri = nrTurnuri + putere;
		nrMonede = nrMonede + putere * inaltime;
		putere = putere * 2;
	}
}
//
//
//
//
//S2-b)
bool nrMagic(int x, int p, int q){
	int cifre[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int copie = x;
	while (copie != 0){
		int uc = copie % p;
		cifre[uc] = 1;
		copie = copie / p;
	}
	copie = x;
	while (copie != 0){
		int uc = copie % q;
		if (cifre[uc] == 0)
			return false;
		cifre[uc]++;
		copie = copie / q;
	}
	for (int i = 0; i < 10; i++){
		if (cifre[i] == 1)
			return false;
	}
	return true;
}

void sirNrMagice(int p, int q, int n, int &k, int sir[]){
	k = 0;
	for (int i = 1; i < n; i++){
		if (nrMagic(i, p, q))
			sir[k++] = i;
	}
}
//
//
//
//
//S1-c)
void inserare(int n,int a[])
{
	for(int i=n-1;i>=0;i--)
	{
		a[2*i]=a[i];
		int aux1=a[i];
		int aux2=1;
		while(aux1>1)
		{
			aux1/=2;
			aux2*=2;
		}
		a[2*i+1]=aux2;
	}
	n*=2;
}
