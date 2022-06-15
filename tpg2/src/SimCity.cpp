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

Mapa SimCity::mapa() {
    Mapa m = _mapa;
    for (const SimCity* s : _uniones) {
        m.unirMapa(s->_mapa);
    }
    return m;
}

map<Casilla, Nat> SimCity::casas() {
    map<Casilla, Nat> res = _casas;
    for (const SimCity* s : _uniones) {
        for (const pair<Casilla, Nat> tuplaCasa : s->_casas) {
            // Si la posición ya está ocupada por una casa de una unión anterior
            // O del SimCity original
            if (res.count(tuplaCasa.first) == 1) {
                // Si la casa que ya estaba ahí se agregó en un turno posterior
                // (es decir, tiene nivel inferior)
                if (res[tuplaCasa.first] > tuplaCasa.second) {
                    res[tuplaCasa.first] = tuplaCasa.second;
                }
            // Si la posición *no* está ocupada por una casa ni por un
            // comercio anterior
            } else if (this->comercios().count(tuplaCasa.first) < 1) {
                res.insert(tuplaCasa);
            }
        }
    }
    return res;
}

map<Casilla, Nat> SimCity::comercios() {
    map<Casilla, Nat> res = _comercios;
    for (const SimCity* s: _uniones) {
        for (const pair<Casilla, Nat> tuplaComercio: s->_comercios) {
            // Si la posición ya está ocupada por un comercio de una unión anterior
            // O del SimCity original
            if (res.count(tuplaComercio.first) == 1) {
                // Si el comercio que ya estaba ahí se agregó en un turno posterior
                // (es decir, tiene nivel inferior)
                if (res[tuplaComercio.first] > tuplaComercio.second) {
                    res[tuplaComercio.first] = tuplaComercio.second;
                }
            } else {
                res.insert(tuplaComercio);
            }
        }
    }
    return res;
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

