#include "manager.h"

Manager::Manager():Angajat(){}

Manager::Manager(string n, string p, string cnp, Data d):Angajat(n,p,cnp,d){}

void Manager::afisare(ostream &dev) const{
    dev<<"---manager";
    Angajat::afisare(dev);
}

double Manager::salariu() const{
    int s = Angajat::salariu();
    s *= 1.25;
    return s;
}

void Manager::afisareSalariu(ostream &dev) const{
    double s = salariu();
    dev<<endl;
    dev<<"salariu: "<<s;
}