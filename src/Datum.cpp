#include "Datum.h"



Datum::Datum() {
        dan= 1;
        mjesec = 1;
        godina = 1;
};

bool Datum::validan(int dan, int mjesec, int godina) const {

    if (godina <0) return false;
    if (mjesec >12 || mjesec <1) return false;
    if (dan >31 || dan <1) return false;

    if ((dan ==31 && ( mjesec ==2 || mjesec ==4 || mjesec ==6 || mjesec ==9 || mjesec ==11) ) )
            return false;
    if (dan ==30 && mjesec ==2)
        return false;

    if (godina<2000){
        if((dan==29 and mjesec==2) and ((godina-1900)%4!=0))
            return false;
    }

    if ( godina >2000){
            if ((dan ==29 && mjesec ==2) and !((godina-2000)%4==0)) return false;
    }

    return true;
}

Datum::Datum (int d, int m, int g) throw(GreskaDatum)
 {

        if(validan(d,m,g))
        {
            dan = d;
            mjesec = m;
            godina = g;
        }
        else
            throw(GreskaDatum());


};

Datum::Datum(const Datum& d)
{
    dan=d.dan;
    mjesec=d.mjesec;
    godina=d.godina;

}


void Datum::postaviDan(int d)
{
    dan=d;
}

void Datum::postaviMjesec(int m)
{
    mjesec=m;
}

void Datum::postaviGodinu(int g)
{
    godina=g;
}

int Datum::vratiDan() const { return dan ; };

int Datum::vratiMjesec() const { return mjesec ; };

int Datum::vratiGodinu() const { return godina ; };





int Datum::operator-(const Datum& d)
{
    int brDana=0, brPrvog=0, brDrugog=0;
    if(d.godina>godina)
        return -1;
    else
    {
        int mjeseci[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i=0; i<d.mjesec-1; i++)
            brPrvog+=mjeseci[i];
        brPrvog+=d.dan;
        for(int i=0; i<mjesec-1; i++)
            brDrugog+=mjeseci[i];
        brDrugog+=dan;


        brDana=(d.godina-godina)*365+(brDrugog-brPrvog);
        if( ((godina%4==0 and godina%100!=0) or godina%400 ==0) and mjesec<=2)
          brDana++;
        else if(((d.godina%4==0 and d.godina%100!=0) or d.godina%400 ==0) and d.mjesec>=2)
          brDana--;

  return brDana;


    }

}





ostream& operator<<(ostream& izlaz, const Datum& d){

        izlaz << d.vratiDan() << "."<< d.vratiMjesec() << "."<< d.vratiGodinu() << endl ;

    return izlaz;
}

istream& operator>>(istream& ulaz, Datum& d) throw(GreskaDatum){

    cout<<"Koristite standardni format DD/MM/YYYY: ";
    int dan, mjesec, godina;
    char znak;
    ulaz>>dan;
    ulaz>>znak;
    ulaz>>mjesec;
    ulaz>>znak;
    ulaz>>godina;
    d.postaviDan(dan);
    d.postaviMjesec(mjesec);
    d.postaviGodinu(godina);
    if(d.validan(dan, mjesec, godina))
        return ulaz;
    else
        throw(GreskaDatum());

    return ulaz;
}
