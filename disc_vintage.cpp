#include "disc_vintage.h"

DiscVintage::DiscVintage(int cc, string d, int n, double pb, string c, Data dt, string t, string a, bool mnt, int r)
    :Disc(cc,d,n,pb,c,dt,t,a){
    mint = mnt;
    raritate = r;
}

double DiscVintage::pretFinal() const{
    double p = Disc::pretFinal();
    p += 15 * raritate;
    return p;
}

void DiscVintage::afisare(ostream &dev) const{
    dev<<"---vintage";
    Disc::afisare(dev);
    dev<<mint<<" "<<raritate<<" ";
}
