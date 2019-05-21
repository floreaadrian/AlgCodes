#include<iostream>
#include<string.h>

using namespace std;

int INF = 1000; //declaram INF si ii dam valoarea 1000
int g[50][50]; //declaram tabelul cu cel mult 50 de linii si coloane

int main()
{
	int t,M,i,j,k,cnt;
	char str[64];
	cin>>t; //citim numarul de cazuri
	while(t--) //parcurgem fiecare pas
	{
		cin>>str; //citim prima linie din tabel
		int M=strlen(str); //avand in vedere ca tabelul este patratic si M fiind numarul de coloane
		//inseamna ca M este si numarul de linii
		for(i=0;i<M;i++) //parcurgem fiecare elment de pe prima linie
			if(str[i]=='Y') // verificam daca este o conexiune intre primul element si elementul i
				g[0][i]=1; // daca exista inseamna ca dinstanta dintre ei este 1
			else
				g[0][i]=INF; // daca nu exista inseamna ca distanta este INF
		for(int j=1;j<M;++j){ // parcurgem restul liniilor
			cin>>str; //citim linia j
			for(i=0;i<M;i++) //parcurgem fiecare element de pe linia j
			if(str[i]=='Y') //verificam daca exista conexiune intre persoana i si persoana j
				g[j][i]=1; //daca exista inseamna ca dinstanta dintre ei este 1
			else
				g[j][i]=INF; //daca nu exista inseamna ca distanta este INF
		}
		int ma,indx; //declaram ma-maximul de prieteni,indx-indexul maximului
		ma=indx=0; //le dam la ambii valoare 1
		for(k=0;k<M;k++){ //parcurgem fiecare linie
			for(cnt=i=0;i<M;i++){ //facem cnt sa fie valoare coloanei actuale
				if(k!=i && g[k][i]==INF){ // daca nu suntem pe aceasi linie cu coloana si daca nu sunt prieteni
					for(j=0;j<M;j++){ //parcurgem din nou coloanele de la inceput
						if(i!=j){ //daca nu suntem pe aceasi linie cu coloana si daca nu sunt prieteni
							if(g[k][j]!=INF && g[i][j]!=INF) break; // daca am gasit un prieten comun oprim cautarea
						}
					}
					if(j<M) cnt++; // daca nu am ajuns pana la final cu cautarea crestem contorul de prieteni posibili
				}
			}
			if(cnt>ma){ //daca numarul actual de prieteni actuali estei mai mare decat celalalt, il inlocuim
				ma=cnt; //numarul de prieteni posibili actuali e inlocuit cu noul maxim
				indx=k; //inlocuim si id-ul acestuia
				}
		}
		cout<<indx<<" "<<ma<<"\n"; //afisam id-ul si numarul maxim de prieteni posibili
	}
	return 0;
}
