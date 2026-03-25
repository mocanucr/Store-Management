#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <ctime>

struct Data{
    int zi;
    int luna;
    int an;
};

inline int difAni(Data d){
    int varsta;

    time_t t = time(nullptr);
    tm* localTime = localtime(&t);
    Data azi;
    azi.zi =  localTime->tm_mday;
    azi.luna = localTime->tm_mon + 1;
    azi.an = localTime->tm_year + 1900;

    varsta = azi.an - d.an;
    if(azi.luna < d.luna || azi.luna == d.luna && azi.zi < d.zi)
        varsta--;
    return varsta;
}

#endif //DATA_H
