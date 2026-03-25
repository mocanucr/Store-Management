#ifndef DISC_H
#define DISC_H

#include "produs.h"

class Disc:public Produs{
protected:
    string casaDiscuri;
    Data dataVanzare;
    string trupa;
    string album;
    int timpLivrare = 2; //zile
    int timpImpachetare = 1; //zile
public:
    Disc();
    Disc(int, string, int, double, string, Data, string, string);
    void afisare(ostream &) const;
    double pretFinal() const;
    virtual bool esteDisc() const { return true; }
    int getTimpLivrare() const { return 3; } // tot 3 zile livrarea
    int getTimpImpachetare() const { return 1; } // o zi impachetarea
};

#endif //DISC_H
