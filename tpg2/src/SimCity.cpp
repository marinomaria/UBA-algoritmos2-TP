#include "SimCity.h"

SimCity::SimCity(Mapa m) : _uniones(), _turnoActual(0), _casas(), _comercios(), _mapa(m) {};

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
            // Si no habia casa, o si el "nivel" (edad de la construccion) es mayor a la que habia
            if (res.count(tuplaCasa.first) == 0 || nivel > res[tuplaCasa.first]) {
                // Defino o redefino el nivel
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
            // Si no habia comercio, o si el "nivel" (edad de la construccion) es mayor al que habia
            if (res.count(tuplaComercio.first) == 0 || nivel > res[tuplaComercio.first]) {
                // Defino o redefino el nivel
                res[tuplaComercio.first] = nivel;
            }
        }
    }

    // uniones de casas
    map<Casilla, Nat> res_casas = casas();

    // si tenemos casa cuyas coordenadas coinciden con la de algun comercio, sin importar el nivel de la casa,
    // borramos dicho comercio de res
     for(const pair<Casilla, Nat> x : res_casas) {
         for (auto it = res.begin(); it != --res.end(); it++) {
                if (it->first==x.first){
                    res.erase(it++);
                }
            }
        }
    return res;
}

// El nivel usado por comercios() (edad) difiere del de esta funcion
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
    _uniones.insert(make_pair(&s2, _turnoActual - s2._turnoActual)); // Asocia diferencia de turnos inicial
};

// El nivel usado por casas() es identico al de una casa (su edad)
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
    } // tMax = _turnoActual - max(_turnoActuali) i en _uniones
    return _turnoActual - tMax;
    // return _turnoActual - turnoActual + max(_turnoActuali) i en uniones
    // = return max(_turnoActuali) i en uniones (justamente lo que quiero!)
}

bool SimCity::huboConstruccion() const {
    // Si el SimCity "padre" tiene alguna construccion de nivel (edad) 0
    for (const pair<Casilla, Nat>& p: _casas) {
        if (p.second == _turnoActual) {
            return true;
        }
    }
    for (const pair<Casilla, Nat>& p: _comercios) {
        if (p.second == _turnoActual) {
            return true;
        }
    }
    // Si alguno de los SimCity "hijos" tuvieron lo mismo (llamado recursivo)
    for (const pair<SimCity*, int>& p: _uniones) {
        // adaptacion para caso donde se avance el nivel de padre aunque no se haya avanzado
        // turno en simcity hijo
        if (p.first->huboConstruccion() && (_turnoActual != p.first->_turnoActual)) {
            return true;
        }
    }
    return false;
}
