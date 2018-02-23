#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

#include <iostream>
using namespace std;

class Automobil
{
    public:
        Automobil();
        Automobil(string proizvodac, string model,int brojSjedista, int snaga, string gorivo, bool klima, bool automatik);
        Automobil& operator=(const Automobil& ds);
        int vratiSnagu() const;
        string vratiGorivo() const;
        string vratiModel() const;
        bool imaKlimu() const;
        bool jesteAutomatik() const;
        int brojSjedista() const;
        void postaviProizvodac(string proizvodac);
        void postaviModel(string model);
        void postaviSnagu(int snaga);
        void postaviGorivo(string gorivo);
        void postaviKlimu(bool klima);
        void postaviMjenjac(bool automatik);
        void postaviBrojSjedista(int brojSjedista);
        friend ostream& operator<<(ostream& izlaz, const Automobil& A);
        friend istream& operator>>(istream& ulaz, Automobil& A) throw(int);

    protected:
        int brojSjed;
        bool klima;
        bool automatik;
        string gorivo, proizvodac, model;
        int snaga;
};

#endif // AUTOMOBIL_H
