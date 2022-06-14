#ifndef TP_SIMCITY_MAPA_H
#define TP_SIMCITY_MAPA_H

#include "Tipos.h"

using namespace std;

class Mapa {
public:
    Mapa(set<Nat> verticales, set<Nat> horizontales);

    bool hayRio(Casilla pos);

    void unirMapa(Mapa m2);

    // Estas funciones, si bien no están en la especificación,
    // son necesarias para la interfaz con la clase aed2_servidor
    set<Nat> verticales();

    set<Nat> horizontales();

private:
    set<Nat> _verticales;
    set<Nat> _horizontales;
};

#endif //TP_SIMCITY_MAPA_H
