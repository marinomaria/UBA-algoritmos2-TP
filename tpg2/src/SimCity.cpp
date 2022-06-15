#include "SimCity.h"

SimCity::SimCity(Mapa m) : _uniones(), _turnoActual(0), _casas(), _comercios(), _mapa(m) {};

//void SimCity::avanzarTurno(set<Casilla> casas, set<Casilla> comercios) {
//    for (Casilla c : casas) {
//        _casas.insert({c, _turnoActual});
//    }
//
//    for (Casilla c : comercios) {
//        _comercios.insert({c, _turnoActual});
//    }
//}

Mapa SimCity::mapa() {
    Mapa m = _mapa;
    for (const SimCity* s : _uniones) {
        m.unirMapa(s->_mapa);
    }
    return m;
}

map<Casilla, Nat> SimCity::casas() const{
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

map<Casilla, Nat> SimCity::comercios() const{
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

void SimCity::unir(SimCity s2) {
    if (_turnoActual < s2._turnoActual){
        _turnoActual = s2._turnoActual;
    }
    _uniones.push_back(&s2);
};


Nat SimCity::nivelCasa(Casilla p) {
    Nat maxNivel = _turnoActual - this->casas()[p];
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

Nat SimCity::antiguedad() const {
    return _turnoActual;
}
