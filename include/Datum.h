#ifndef DATUM_H
#define DATUM_H
#include <iostream>


using namespace std;

class GreskaDatum{};

class Datum
{
    public:
        Datum();
        bool validan(int dan, int mjesec, int godina) const;
        Datum(int d, int m, int y) throw(GreskaDatum);
        Datum(const Datum& d);
        void postaviDan(int d);
        void postaviMjesec(int m);
        void postaviGodinu(int g);
        int vratiDan()      const;
        int vratiMjesec()   const;
        int vratiGodinu()   const;


        int operator-(const Datum& d);
        friend ostream& operator<<(ostream& izlaz, const Datum& d);
        friend istream& operator>>(istream& ulaz, Datum& d) throw(GreskaDatum);
    protected:
        int dan, mjesec, godina;
};








#endif // DATUM_H
