#include "Automobil.h"

Automobil::Automobil()
{
    this->proizvodac="";
    this->model="";
    this->brojSjed=0;
    this->snaga=0;
    this->gorivo="";
    this->klima=false;
    this->automatik=false;

}
Automobil::Automobil(string proizvodac, string model, int brojSjedista, int snaga, string gorivo, bool klima, bool automatik)
{
    this->proizvodac=proizvodac;
    this->model=model;
    this->brojSjed=brojSjedista;
    this->snaga=snaga;
    this->gorivo=gorivo;
    this->klima=klima;
    this->automatik=automatik;

}

Automobil& Automobil::operator=(const Automobil& d)
{
    if(this==&d)
        return *this;
    else
    {
        proizvodac=d.proizvodac;
        model=d.model;
        brojSjed=d.brojSjed;
        snaga=d.snaga;
        gorivo=d.gorivo;
        klima=d.klima;
        automatik=d.automatik;

    }

}
int Automobil::vratiSnagu() const
{
    return snaga;
}
string Automobil::vratiGorivo() const
{
    return gorivo;
}
bool Automobil::imaKlimu() const
{
    return klima;
}

bool Automobil::jesteAutomatik() const
{
    return automatik;
}

int Automobil::brojSjedista() const
{
    return brojSjed;
}

string Automobil::vratiModel() const
{
    return proizvodac+" "+model;
}


 void Automobil::postaviProizvodac(string proizvodac)
 {
     this->proizvodac=proizvodac;
 }

void Automobil::postaviModel(string model)
{
     this->model=model;
}

void Automobil::postaviSnagu(int snaga)
{
     this->snaga=snaga;
}

void Automobil::postaviGorivo(string gorivo)
{
    this->gorivo=gorivo;
}

void Automobil::postaviKlimu(bool klima)
{
    this->klima=klima;
}

void Automobil::postaviMjenjac(bool automatik)
{
    this->automatik=automatik;
}

void Automobil::postaviBrojSjedista(int brojSjedista)
{
    this->brojSjed=brojSjedista;
}







ostream& operator<<(ostream& izlaz, const Automobil& A)
{
    izlaz<<""<<A.vratiModel()<<endl;
    izlaz<<"Snaga: "<<A.vratiSnagu()<<endl;
    izlaz<<"Gorivo: "<<A.vratiGorivo()<<endl;
    if(A.jesteAutomatik())
        izlaz<<"Automobil ima automatik mjenjac"<<endl;
    else
        izlaz<<"Automobil ima rucni mjenjac"<<endl;
    if(A.imaKlimu())
        izlaz<<"Automobil ima ugradenu klimu"<<endl;
    else
        izlaz<<"Automobil ne posjeduje klimu"<<endl;
    izlaz<<"Maksimalan broj putnika je: "<<A.brojSjedista()<<endl;
    return izlaz;
}

istream& operator>>(istream& ulaz, Automobil& A) throw (int)
{
    string proizvodac, model, gorivo;
    char klima,automatik;
    int snaga;
    int brojSjedista;

    cout<<"Unesite podatke automobila koji zelite iznajmiti: "<<endl;
    cout<<"Proizvodac: ";
    ulaz>>proizvodac;
    A.postaviProizvodac(proizvodac);
    cout<<"Model: ";
    ulaz>>model;
    A.postaviModel(model);
    cout<<"Snaga: (unesite cjelobrojni iznos) ";
    if(ulaz>>snaga)
        A.postaviSnagu(snaga);
    else
        throw 1;


    cout<<"Gorivo: ";
    cin>>gorivo;
    A.postaviGorivo(gorivo);

    cout<<"Maksimalan broj putnika: (unesite cjelobrojni iznos) ";
    if(ulaz>>brojSjedista)
        A.postaviBrojSjedista(brojSjedista);
    else
        throw 2;
    cout<<"Da li zelite klimu? (D ili N)";
    ulaz>>klima;
    if(klima=='D' or klima=='d')
        A.postaviKlimu(1);
    else
        A.postaviKlimu(0);
    cout<<"Da li zelite automatik mjenjac? (D ili N)";
    ulaz>>automatik;
    if(automatik=='D' or automatik=='d')
        A.postaviMjenjac(1);
    else
        A.postaviMjenjac(0);
    cout<<endl;
    return ulaz;
}
