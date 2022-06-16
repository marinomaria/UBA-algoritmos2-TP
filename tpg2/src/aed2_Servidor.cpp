#include "aed2_Servidor.h"

aed2_Servidor::aed2_Servidor() : _server() {}

void aed2_Servidor::nuevaPartida(Jugador j, set<int> horizontales, set<int> verticales) {
    _server.registrar(j, verticales, horizontales);
}

void aed2_Servidor::unir(Jugador j1, Jugador j2) {
    _server.unir(j1, j2);
}

set<int> aed2_Servidor::riosHorizontales(Jugador j) const {
    SimCity s = _server.at(j);
    return s.mapa().horizontales();
}

set<int> aed2_Servidor::riosVerticales(Jugador j) const {
    SimCity s = _server.at(j);
    return s.mapa().verticales();
}

set<Casilla> aed2_Servidor::casas(Jugador j) const {
    set<Casilla> casillasCasa;
    SimCity s = _server.at(j);
    for (pair<Casilla , Nat> ks : s.casas()) {
        casillasCasa.insert(ks.first);
    }
    return casillasCasa;
}

set<Casilla> aed2_Servidor::comercios(Jugador j) const {
    set<Casilla> casillasComercio;
    SimCity s = _server.at(j);
    for (pair<Casilla , Nat> ks : s.comercios()) {
        casillasComercio.insert(ks.first);
    }
    return casillasComercio;
}

Nat aed2_Servidor::popularidad(Jugador j) const {
    SimCity s = _server.at(j);
    return s.popularidad();
}

Nat aed2_Servidor::nivel(Jugador j, Casilla c) const {
    const SimCity& s = _server.at(j);
    if (s.casas().count(c) == 1) {
        return s.nivelCasa(c);
    } else {
        return s.nivelComercio(c);
    }
}

bool aed2_Servidor::huboConstruccion(Jugador j) const {
    const SimCity& sim = _server.at(j);
    map<Casilla, Nat> casas = sim.casas();
    for (auto it = casas.begin(); it != casas.end(); it++) {
        if (it->second == 0) {
            return true;
        }
    }
    map<Casilla, Nat> comercios = sim.comercios();
    for (auto it = comercios.begin(); it != comercios.end(); it++) {
        if (it->second == sim.antiguedad()) {
            return true;
        }
    }
    return false;
}

void aed2_Servidor::agregarCasa(Jugador j, Casilla c) {
    _server.at(j).agregarCasa(c);
}

void aed2_Servidor::agregarComercio(Jugador j, Casilla c) {
    _server.at(j).agregarComercio(c);
}

void aed2_Servidor::avanzarTurno(Jugador j) {
    _server.at(j).avanzarTurno();
}

Nat aed2_Servidor::antiguedad(Jugador j) const {
    SimCity s = _server.at(j);
    return s.antiguedad();
}

