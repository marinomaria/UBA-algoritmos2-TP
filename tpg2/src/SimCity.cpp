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

Nat SimCity::nivelComercio(Casilla p) {
    Nat maxNivel = _turnoActual - this->comercios()[p];
    map<Casilla, Nat> casas = this->casas();
    for (map<Casilla, Nat>::iterator it = casas.begin(); it != casas.end(); it++) {
        if (abs(it->first.first - p.first) + abs(it->first.second - p.second) == 3) {
            Nat nivel = _turnoActual - it->second;
            if (nivel > maxNivel) {
                maxNivel = nivel;
            }
        }
    }
    return maxNivel;
}