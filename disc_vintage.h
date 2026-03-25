#ifndef DISC_VINTAGE_H
#define DISC_VINTAGE_H

#include "disc.h"

class DiscVintage:public Disc{
public:
    bool mint;
    int raritate;
public:
    DiscVintage();
    DiscVintage(int, string, int, double, string, Data, string, string, bool, int);
    void afisare(ostream &) const;
    double pretFinal() const;
    virtual bool esteDiscVintage() const { return true; }
};

#endif //DISC_VINTAGE_H
