#include "SimCity.h"

SimCity::SimCity(Mapa m) : _uniones(), _turnoActual(0), _casas(), _comercios(), _mapa(m) {};

void SimCity::avanzarTurno(set<Casilla> casas, set<Casilla> comercios) {
    for (Casilla c : casas) {
        _casas.insert({c, _turnoActual});
    }

    for (Casilla c : comercios) {
        _comercios.insert({c, _turnoActual});
    }
}

Nat SimCity::popularidad() {
    return _uniones.size();
}

