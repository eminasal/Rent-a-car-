#include "Korisnik.h"


Korisnik::Korisnik()
{
    ime="";
     prezime="";
      brojTelefona="";
      gotovina=0;

}
  Korisnik::Korisnik(string ime, string prezime, string brojTelefona, bool gotovina)
  {
      this-> ime=ime;
      this-> prezime=prezime;
      this-> brojTelefona=brojTelefona;
      this-> gotovina=gotovina;



  }

  Korisnik::Korisnik(const Korisnik& k)
  {

        ime=k.ime;
        prezime=k.prezime;
        brojTelefona=k.brojTelefona;
        gotovina=k.gotovina;


  }

string Korisnik::vratiIme() const
        {
            return ime;
        }
string Korisnik::vratiPrezime() const
        {
            return prezime;
        }
string Korisnik::vratiBrojTelefona() const
        {
            return brojTelefona;
        }

void Korisnik::ispis() const
{
    cout<<"Korisnicki profil"<<endl;
    cout<<"Ime: "<<vratiIme()<<endl<<"Prezime: "<<vratiPrezime()<<endl<<"Kontakt telefon: "<<vratiBrojTelefona()<<endl;
    cout<<"Korisnik trenutno nema u posjedu iznajmljenih automobila"<<endl ;

}

bool Korisnik::placanjeGotovinom() const
{
    return gotovina;
}

void Korisnik::postaviIme(string ime)
{
    this->ime=ime;
}

void Korisnik::postaviPrezime(string prezime)
{
    this->prezime=prezime;
}

void Korisnik::postaviBrojTelefona(string brojTelefona)
{
    this->brojTelefona=brojTelefona;
}

void Korisnik::nacinPlacanja(bool gotovina)
{
    this->gotovina=gotovina;
}

ostream& operator<<(ostream& izlaz,const  Korisnik& k)
{
    izlaz<<"Ime: "<<k.vratiIme()<<endl<<"Prezime: "<<k.vratiPrezime()<<endl<<"Kontakt telefon: "<<k.vratiBrojTelefona()<<endl;
    if(k.placanjeGotovinom())
        izlaz<<"Korisnik je odlucio placati gotovinom. "<<endl;
    return izlaz;
}
istream& operator>>(istream& ulaz, Korisnik& k)
{

    string ime, prezime, brojTelefona;
    char gotovina;
    cout<<"Unesite podatke korisnika: "<<endl<<"Ime: ";
    ulaz>>ime;
    k.postaviIme(ime);
    cout<<"Prezime: ";
    ulaz>>prezime;
    k.postaviPrezime(prezime);
    cout<<"Broj telefona: ";
    ulaz>>brojTelefona;
    k.postaviBrojTelefona(brojTelefona);
    cout<<"Da li zelite platiti gotovinom? U tom slucaju imate 10% popusta! (D ili N)";
    ulaz>>gotovina;
    if(gotovina=='D'  or gotovina=='d')
        k.nacinPlacanja(1);
    else
        k.nacinPlacanja(0);
    return ulaz;
}
