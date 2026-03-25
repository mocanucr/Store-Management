#include "operator.h"

Operator::Operator():Angajat(){}

Operator::Operator(string n, string p, string cnp, Data d):Angajat(n,p,cnp,d){}

void Operator::afisare(ostream &dev) const{
    dev<<"---operator";
    Angajat::afisare(dev);
}

double Operator::salariu() const{
    int s = Angajat::salariu();
    s *= 1;
    s += valComenziProcesate * 0.005;
    time_t t = time(nullptr);
    tm* localTime = localtime(&t);
    int lunaCurenta = localTime->tm_mon + 1;
    int l = (CNP[3] - '0') * 10 + (CNP[4] - '0');
    if(lunaCurenta == l) s += 100;
    return s;
}

void Operator::addValComenziProcese(double v) {
    valComenziProcesate += v;
}

void Operator::afisareSalariu(ostream &dev) const{
    double s = salariu();
    dev<<endl;
    dev<<"salariu: "<<s;
}