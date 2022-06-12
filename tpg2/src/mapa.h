#ifndef TP_SIMCITY_MAPA_H
#define TP_SIMCITY_MAPA_H

#include "Tipos.h"
#include <set>

using namespace std;

class mapa {
public:
    mapa(set<Nat> verticales, set<Nat> horizontales);

    bool hayRio(Casilla pos);

    void unirMapa(mapa m2);

private:
    set<Nat> _verticales;
    set<Nat> _horizontales;
};

#endif //TP_SIMCITY_MAPA_H
