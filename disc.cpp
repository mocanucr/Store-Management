#include "disc.h"

Disc::Disc(int cc, string d, int n, double p, string c, Data dt, string t, string a):Produs(cc,d, n, p){
    casaDiscuri = c;
    dataVanzare = dt;
    trupa = t;
    album = a;
}

double Disc::pretFinal() const{
    return pretBaza + 5;
}

void Disc::afisare(ostream &dev) const{
    dev<<"---disc";
    Produs::afisare(dev);
    dev<<casaDiscuri<<" "<<dataVanzare.zi<<"."<<dataVanzare.luna<<"."<<dataVanzare.an<<" ";
    dev<<trupa<<" "<<album<<" ";
}