#ifndef HAINE_H
#define HAINE_H

#include "produs.h"

class Haine:public Produs{
protected:
    string culoare;
    string marca;
public:
    Haine();
    Haine(int, string, int, double, string, string);
    void afisare(ostream &) const;
    double pretFinal() const;
    virtual bool esteHaina() const { return true; }
    int getTimpLivrare() const override{ return 3;} //3 zile livrarea
    int getTimpImpachetare() const override{return 2;} // 2 zile impachetarea
};

#endif //HAINE_H
