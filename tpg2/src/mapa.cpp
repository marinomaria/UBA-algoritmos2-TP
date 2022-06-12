
#include "mapa.h"

mapa::mapa(set<Nat> verticales, set<Nat> horizontales) : _verticales(verticales), _horizontales(horizontales) {}


bool mapa::hayRio(Casilla pos) {
    return _verticales.count(pos.first) == 1 or _horizontales.count(pos.second) == 1;
}

void mapa::unirMapa(mapa m2) {
    // La función insert se ocupa de no insertar duplicados
    for (Nat r : m2._verticales) {
        this->_verticales.insert(r);
    }
    for (Nat r : m2._horizontales) {
        this->_horizontales.insert(r);
    }
}
