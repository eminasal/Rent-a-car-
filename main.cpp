#include <iostream>
#include <cstdlib>

#include "Datum.h"
#include "Korisnik.h"
#include "Automobil.h"
#include "Transakcija.h"
#include <string>
using namespace std;

int main()
{


    try{
     Transakcija prvi(1);
    cout<<"Printanje racuna "<<endl;
    cout<<"Da li zelite detaljan nalog transakcije?"<<endl;
    char nalog;
    cin>>nalog;
    prvi.vratiIme();
    prvi.ispis();
    if(nalog=='d' or nalog=='D')
    {
        system(prvi.vratiRacun().c_str());
    }



    }
    catch (int)
    {
        cout<<"Greska pri unosu! "<<endl;

    }
     catch(GreskaDatum)
    {
        cout<<"Greska u datumu!"<<endl;
    }







    return 0;
}
