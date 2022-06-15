#include "SimCity.h"

SimCity::SimCity(Mapa m) : _uniones(), _turnoActual(0), _casas(), _comercios(), _mapa(m) {};

void SimCity::avanzarTurno() {
    _turnoActual++;
}

Nat SimCity::popularidad() {
    return _uniones.size();
}

void SimCity::agregarCasa(Casilla p) {
    _casas.insert(make_pair(p, _turnoActual));
}

void SimCity::agregarComercio(Casilla p) {
    _comercios.insert(make_pair(p, _turnoActual));
}

Nat SimCity::antiguedad() {
    return _turnoActual;
}

