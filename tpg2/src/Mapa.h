#ifndef TP_SIMCITY_MAPA_H
#define TP_SIMCITY_MAPA_H

#include "Tipos.h"

using namespace std;

class Mapa {
public:
    Mapa(set<Nat> verticales, set<Nat> horizontales);

    bool hayRio(Casilla pos);

    void unirMapa(Mapa m2);

private:
    set<Nat> _verticales;
    set<Nat> _horizontales;
};

#endif //TP_SIMCITY_MAPA_H
