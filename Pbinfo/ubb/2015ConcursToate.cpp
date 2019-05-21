//S1-a)
double euler(double eps)
{
	double rez = 1;
	int n = 1;
	double t = 1.0 / n;
	while (t >= eps){
		rez += t;
		n++;
		t = t / n;
	}
	return rez + t;
}
//
//
//
//
//S2-b)
