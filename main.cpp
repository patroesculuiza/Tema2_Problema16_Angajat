#include <iostream>
#include <fstream>
#include <cstring>
#include "angajat.h"
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

Angajat::~Angajat(){salariu=0;delete[]nume;}
Angajat::Angajat()
{
    salariu=0;
    nume=NULL;
}
Angajat::Angajat(char *n,float sal)
{
    salariu=sal;
    nume=new char[sizeof(n)];
    strcpy(nume,n);
}
Angajat::Angajat(const Angajat &ob)
{
    salariu=ob.salariu;
    nume=new char[sizeof(ob.nume)];
    strcpy(nume,ob.nume);
}
Angajat &Angajat::operator=(const Angajat &ob)
{
    if(this!=&ob)
    {
        delete[]nume;
        nume=new char[sizeof(ob.nume)];
        strcpy(nume,ob.nume);
        salariu=ob.salariu;
    }
    return *this;
}
float Angajat::getSalariu()
{
    return salariu;
}
void Angajat::setSalariu(float s)
{
    salariu=s;
}
void Angajat::display()
{
    g<<nume<<" "<<salariu<<endl;
}
istream &operator>>(istream &is,Angajat &ob)
{
    ob.citire(is);
    return is;
}
ostream &operator<<(ostream &o,Angajat &ob)
{
    ob.afisare(o);
    return o;
}


istream &operator>>(istream &is, Administrator &ob)
{
    ob.citire(is);
    return is;
}
ostream &operator<<(ostream &o, Administrator &ob)
{
    ob.afisare(o);
    return o;
}

int main()
{
    int n;
    f>>n;
    Angajat*vec[n];
    int k;
    int ok=1;
for(int i = 0 ; i < n ; i++)
    {

       vec[i]=new(nothrow) Administrator();
      if(vec[i]!=NULL) vec[i]->citire(f);
          else { cout<<"error";ok=0;}
      if(ok==0) break;
    }
    if(ok==1){
        for(int i = 0 ; i < n ; i++)
        {
            vec[i]->afisare(g);
            g<<" "<<vec[i]->getsectie();
            g<<endl;
        }
  /* for(int i = 0 ; i < n ;i++)
   {
       if(Angajat *d=static_cast<Angajat*>(vec[i])) g<<d->getSalariu()<<endl;

       }*/
            }
     for (int i = 0; i < n; i++)
        delete vec[i];
}
