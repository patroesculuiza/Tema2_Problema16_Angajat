#ifndef ANGAJAT_H_INCLUDED
#define ANGAJAT_H_INCLUDED

#include <fstream>
#include <cstring>
using namespace std;


class Angajat
{
protected:
char *nume;
float salariu;
public:
Angajat();
Angajat(char *n, float sal);
Angajat(const Angajat &r);
void display();
float getSalariu();
void setSalariu(float s);
virtual float getsectie()=0;
virtual void citire(istream &is){char *n=new char[30];is>>n>>salariu;
nume=new char[sizeof(n)];strcpy(nume,n); delete[]n;}
virtual void afisare(ostream &o){o<<nume<<" "<<salariu<<" ";}
Angajat&operator=(const Angajat &ob);
virtual ~Angajat();
};
class Administrator : public Angajat {
int sectie;
public:
Administrator(){sectie=0;}
Administrator(char *n, float sal, int sec):Angajat(n,sal)
{
    sectie=sec;
}
Administrator(Administrator& r):Angajat(r.nume,r.salariu){sectie=r.sectie;}
void citire(istream &is){Angajat::citire(is);is>>sectie;}
void afisare(ostream &o){Angajat::afisare(o);o<<sectie;}
Administrator &operator=(const Administrator &ob)
{
    Angajat::operator=(ob);
    if(this!=&ob) sectie=ob.sectie;
    return *this;
}
float getsectie(){return sectie;}
~Administrator(){}
};

#endif // ANGAJAT_H_INCLUDED
