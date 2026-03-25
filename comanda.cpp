#include "comanda.h"

int Comanda::nr = 0;

Comanda::Comanda(Data d, vector<Produs *> &p, vector<int> &c) {
    id = nr;
    nr++;
    dataComanda = d;
    produse = p;
    cantitai = c;
    val = valComanda();
    durataSol = calcDurataSol();
}

double Comanda::valComanda() const {
    double s = 0;
    for (auto p : produse) {
        s += p->pretFinal();
    }
    return s;
}

bool Comanda::esteValida() const {
    double valFaraLvr = 0;
    int nrDisc = 0, nrHaine = 0;
    for (auto p : produse) {
        valFaraLvr += p->pretFinal();
        if (p->esteDisc() || p->esteDiscVintage()) nrDisc++;
        if (p->esteHaina()) nrHaine++;
    }
    if (valFaraLvr > 100 && nrDisc <= 5 && nrHaine <= 3)
        return 1;
    else return 0;
}

void Comanda::afisare(ostream &dev) const {
    dev<<endl;
    dev<<"Comanda"<<endl;
    dev<<id<<" "<<dataComanda.zi<<"."<<dataComanda.luna<<"."<<dataComanda.an<<" ";
    dev<<durataSol<<" "<<valComanda()<<endl;
    dev<<"Produse:"<<endl;
    for (auto p : produse) {
        p->afisare(dev);
    }
}

int Comanda::calcDurataSol() {
    int s = 0;
    for (auto p : produse) {
        s += p->getTimpLivrare() + p->getTimpImpachetare();
    }
    return s;
}





