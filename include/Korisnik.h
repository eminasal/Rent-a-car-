#ifndef KORISNIK_H
#define KORISNIK_H

#include <iostream>
#include <string>
using namespace std;


class Korisnik
{
    public:
        Korisnik();
        Korisnik(string ime, string prezime, string brojTelefona, bool gotovina);
        Korisnik(const Korisnik& k);
        string vratiIme() const;
        string vratiPrezime() const;
        string vratiBrojTelefona() const;
        virtual void ispis() const;
        bool placanjeGotovinom() const;
        void postaviIme(string ime);
        void postaviPrezime(string prezime);
        void postaviBrojTelefona(string brojTelefona);
        void nacinPlacanja(bool gotovina);
        friend ostream& operator<<(ostream& izlaz,const  Korisnik& k);
        friend istream& operator>>(istream& ulaz, Korisnik& k);

    protected:
        string ime, prezime, brojTelefona;
        bool gotovina;

};

#endif // KORISNIK_H
