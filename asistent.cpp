#include "asistent.h"

Asistent::Asistent():Angajat(){}

Asistent::Asistent(string n, string p, string cnp, Data d):Angajat(n,p,cnp,d){}

void Asistent::afisare(ostream &dev) const{
    dev<<"---asistent";
    Angajat::afisare(dev);
}

double Asistent::salariu() const{
    int s = Angajat::salariu();
    s *= 0.75;
    time_t t = time(nullptr);
    tm* localTime = localtime(&t);
    int lunaCurenta = localTime->tm_mon + 1;
    int l = (CNP[3] - '0') * 10 + (CNP[4] - '0');
    if(lunaCurenta == l) s += 100;
    return s;
}

void Asistent::afisareSalariu(ostream &dev) const{
    double s = salariu();
    dev<<endl;
    dev<<"salariu: "<<s;
}