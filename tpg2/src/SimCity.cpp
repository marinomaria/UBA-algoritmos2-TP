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

Mapa SimCity::mapa() const {
    Mapa m = _mapa;
    for (const pair<SimCity*, int>& p : _uniones) {
        m.unirMapa(p.first->mapa());
    }
    return m;
}

map<Casilla, Nat> SimCity::casas() const{
    map<Casilla, Nat> res = _casas;
    for (auto it = res.begin(); it != res.end(); it++) {
        it->second = _turnoActual - it->second;
    }
    for (const pair<SimCity*, int>& p : _uniones) {
        for (const pair<Casilla, Nat> tuplaCasa : p.first->_casas) {
            Nat nivel = _turnoActual - p.second - tuplaCasa.second;
            if (res.count(tuplaCasa.first) == 0 || nivel < res[tuplaCasa.first]) {
                res[tuplaCasa.first] = nivel;
            }
        }
    }
    return res;
}

map<Casilla, Nat> SimCity::comercios() const{
    map<Casilla, Nat> res = _comercios;
    for (auto it = res.begin(); it != res.end(); it++) {
        it->second = _turnoActual - it->second;
    }
    for (const pair<SimCity*, int>& p : _uniones) {
        for (const pair<Casilla, Nat> tuplaComercio : p.first->_comercios) {
            Nat nivel = _turnoActual - p.second - tuplaComercio.second;
            if (res.count(tuplaComercio.first) == 0 || nivel < res[tuplaComercio.first]) {
                res[tuplaComercio.first] = nivel;
            }
        }
    }
    return res;
}

Nat SimCity::nivelComercio(Casilla p) const {
    Nat maxNivel = this->comercios()[p];
    map<Casilla, Nat> casas = this->casas();
    for (map<Casilla, Nat>::iterator it = casas.begin(); it != casas.end(); it++) {
        if (abs(it->first.first - p.first) + abs(it->first.second - p.second) <= 3) {
            if (it->second > maxNivel) {
                maxNivel = it->second;
            }
        }
    }
    return maxNivel;
}

void SimCity::unir(SimCity& s2) {
    _uniones.insert(make_pair(&s2, _turnoActual - s2._turnoActual));
};


Nat SimCity::nivelCasa(Casilla p) const {
    return this->casas()[p];
}

void SimCity::avanzarTurno() {
    _turnoActual++;
}

Nat SimCity::popularidad() const {
    Nat res = _uniones.size();
    for (const pair<SimCity*, int>& p: _uniones) {
        res += p.first->popularidad();
    }
    return res;
}

void SimCity::agregarCasa(Casilla p) {
    _casas.insert(make_pair(p, _turnoActual));
}

void SimCity::agregarComercio(Casilla p) {
    _comercios.insert(make_pair(p, _turnoActual));
}

Nat SimCity::antiguedad() const {
    int tMax = 0;
    for (const pair<SimCity*, int>& p: _uniones) {
        if (p.second < tMax) {
            tMax = p.second;
        }
    }
    return _turnoActual - tMax;
}
