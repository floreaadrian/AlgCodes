//S1-a)
void triunghiPascal(int r, int linie[]){
	int linieNoua[33];
	linie[0] = 1; linie[1] = 1;
	for (int ri = 2; ri <= r; ri++){
		linieNoua[0] = 1;
		linieNoua[ri] = 1;
		for (int i = 1; i < ri; i++){
			linieNoua[i] = linie[i - 1] + linie[i];
		}
		for (int i = 0; i <= ri; i++){
			linie[i] = linieNoua[i];
		}
	}
}
//
//
//
//
//S1-b)
