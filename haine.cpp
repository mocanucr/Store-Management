#include "haine.h"

Haine::Haine(int cc, string d, int n, double p, string c, string m):Produs(cc,d, n, p){
    culoare = c;
    marca = m;
}

double Haine::pretFinal() const{
    return pretBaza + 20;
}

void Haine::afisare(ostream &dev) const{
    dev<<"---haine";
    Produs::afisare(dev);
    dev<<culoare<<" "<<marca<<" ";
}