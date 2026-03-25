#include "produs.h"

Produs::Produs(int c, string d, int n, double p){
    cod = c;
    denumire = d;
    nrProduse = n;
    pretBaza = p;
}

void Produs::adaugaProduse(int nr){
    nrProduse += nr;
}

int Produs::getCod() const{
    return cod;
}

void Produs::afisare(ostream &dev) const{
    dev<<endl;
    dev<<cod<<" "<<denumire<<" "<<nrProduse<<" "<<pretBaza<<" ";
}