#include "Transakcija.h"

Transakcija::Transakcija()
{

    kapacitet=1;
    brRentanih=1;
    rentani=new Automobil [kapacitet];

    cin>>rentani[0];
    cin>>preuzimanje;
    cin>>vracanje;
    cin>>korisnik;
    Cijena();
    cijena=vratiCijenu();
    racun="Racun"+vratiKorisnika().vratiIme()+vratiKorisnika().vratiPrezime()+".txt";
}

Transakcija::  Transakcija(int brRentanih)   throw(GreskaDatum())
{
    int kapacitet=brRentanih*2;
    this->brRentanih=brRentanih;
    rentani=new Automobil [kapacitet];
    for(int i=0; i<brRentanih; i++)
    {
        cout<<"               Transakcija "<<i+1<<endl;
        cin>>rentani[i];
    }
    cout<<"Datum preuzimanja:"<<endl;
    cin>>this->preuzimanje;
    cout<<"Datum vracanja: "<<endl;
    cin>>this->vracanje;
    cout<<endl;
    if((this->vracanje-this->preuzimanje)>=0 )
    {
        cin>>korisnik;
    Cijena();
    cijena=vratiCijenu();
    racun="Racun"+vratiKorisnika().vratiIme()+vratiKorisnika().vratiPrezime()+".txt";

    }
    else
        throw(GreskaDatum());


}
Transakcija::~Transakcija()
{
    delete [] rentani;
}

Datum Transakcija::danPreuzimanja() const
{
    return preuzimanje;
}

Datum Transakcija::danVracanja() const
{
    return vracanje;
}

Automobil Transakcija::vratiAutomobil() const
{
    return rentani[0];
}

Automobil Transakcija::vratiAutomobil(int index) const
{
    return rentani[index];
}
Korisnik Transakcija::vratiKorisnika() const
{
    return korisnik;
}
int Transakcija::vratiBrRentanih() const
{
    return brRentanih;
}

void Transakcija::Cijena()
{
    cijena=100;
    if(vratiAutomobil().brojSjedista()>5)
        cijena+=50;
    if(vratiAutomobil().jesteAutomatik())
        cijena+=20;
    if(vratiAutomobil().imaKlimu())
        cijena+=10;
    if(danVracanja()-danPreuzimanja()>30)
        cijena*=0.90;
    if(placanjeGotovinom()==true)
        cijena*=0.90;
    cijena=cijena*(danVracanja()-danPreuzimanja());
}

double Transakcija::vratiCijenu() const
{

    return cijena;
}


string Transakcija::vratiRacun() const
{
    return racun;
}
/*
Transakcija::Transakcija(const Transakcija& other)
{

}

Transakcija& Transakcija::operator=(const Transakcija& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
*/


void Transakcija::ispis() const
{

    ofstream fout;
    string naziv;

    naziv="Racun"+vratiKorisnika().vratiIme()+vratiKorisnika().vratiPrezime()+".txt";

    fout.open(naziv.c_str());
    if (fout.is_open())
    {
        for(int i=0; i<vratiBrRentanih(); i++)
        {
            fout<<"Automobil    NO: "<<i+1<<endl;
            fout<< vratiAutomobil(i);
            fout<<endl;
        }

        fout<< vratiKorisnika();
        fout<<endl<<"Datum preuzimanja automobila: "<<danPreuzimanja()<<endl;
        fout<<"Krajnji datum za povrat automobila: "<<danVracanja()<<endl;
        if(danVracanja()-danPreuzimanja()>30 and placanjeGotovinom()==true)
            fout<<"S obzirom da iznajmljujete automobil na duzi period i zelite platiti gotovinom ostvarili ste popust od 20%"<<endl;
        if(danVracanja()-danPreuzimanja()>30)
            fout<<"S obzirom da iznajmljujete automobil na duzi period, ostvarili ste popust od 10% na pocetnu cijenu!"<<endl;
        if(vratiKorisnika().placanjeGotovinom()==true)
            fout<<"S obzirom da zelite platiti gotovinom ostvarili ste popust od 10% na pocetnu cijenu!"<<endl;
        fout<<"Broj dana na koji iznajmljujete automobil je: "<<danVracanja()-danPreuzimanja()<<endl;
        fout<<"Krajnji iznos:           "<<vratiCijenu()<<" KM"<<endl;
        fout.close();
    }

}


