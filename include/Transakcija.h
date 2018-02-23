#ifndef Transakcija_H
#define Transakcija_H
#include <iostream>
#include <string>
#include <fstream>

#include <Datum.h>
#include <Korisnik.h>
#include <Automobil.h>




using namespace std;


class Transakcija : public Automobil, public Datum, public Korisnik
{
    public:
        Transakcija();
        Transakcija(int brRentanih)   throw(GreskaDatum());
        ~Transakcija();

       // Transakcija(const Transakcija& other);
       // Transakcija& operator=(const Transakcija& other);
        Datum danPreuzimanja() const;
        Datum danVracanja() const;
        Automobil vratiAutomobil() const;
        Automobil vratiAutomobil(int index) const;
        Korisnik vratiKorisnika() const;
        int vratiBrRentanih() const;
        void ispis() const;
        void Cijena();
        double vratiCijenu() const;
        string vratiRacun() const;

    protected:
        Datum preuzimanje, vracanje;
        Korisnik korisnik;
        Automobil *rentani;
        int kapacitet, brRentanih;
        double cijena;
        string racun;
};

#endif // Transakcija_H
