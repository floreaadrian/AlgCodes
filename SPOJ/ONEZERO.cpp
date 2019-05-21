#include <iostream>

using namespace std;

const int RestMaxim = 100;

int nrCifre[RestMaxim];
int tata[RestMaxim];
short cifra[RestMaxim];
int coada[RestMaxim];
int N;

void printNumber( int rest )
{
    if ( tata[rest] != 0 )
    {
        printNumber( tata[rest] );
        cout << cifra[rest];
    }
}

int main()
{
    cin >> N;

    int st = 0, dr = 1;

    coada[ ++st ] = 1; /// adaug restul 1 în coadă
    nrCifre[1] = 1;    /// marchez faptul că am un număr de o cifră ce dă restul 1

    while ( st <= dr )
    {
        int rest = coada[ st++ ]; /// extrag restul curent din coadă

        for ( int i = 0; i <= 1; ++i ) /// încerc să adaug cifra i restului rest
                                       /// pot forma astfel resturile 10*rest și 10*rest+1 (mod N)
        {
            int new_rest = ( rest * 10 + i ) % N;

            if ( nrCifre[new_rest] == 0 ) /// dacă nu am mai întalnit acest rest
            {
                nrCifre[new_rest] = nrCifre[rest] + 1; /// îi stabilesc numărul de cifre
                cifra[new_rest] = i;                   /// marchez că am folosit cifra i pentru a ajunge din rest în new_rest
                tata[new_rest] = rest;                 /// marchez că am ajuns în new_rest din rest
                coada[ ++dr ] = new_rest;              /// adaug în coadă noul rest obținut
            }
        }
    }

    cout << "1";
    printNumber( 0 );

    return 0;
}
