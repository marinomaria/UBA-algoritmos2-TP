#ifndef TP_SIMCITY_MAPA_H
#define TP_SIMCITY_MAPA_H

#include "Tipos.h"

using namespace std;

class Mapa {
public:
    Mapa(set<int> verticales, set<int> horizontales);

    bool hayRio(Casilla pos);

    void unirMapa(Mapa m2);

    // Estas funciones, si bien no están en la especificación,
    // son necesarias para la interfaz con la clase aed2_servidor
    set<int> verticales();

    set<int> horizontales();

private:
    set<int> _verticales;
    set<int> _horizontales;
};

#endif //TP_SIMCITY_MAPA_H
