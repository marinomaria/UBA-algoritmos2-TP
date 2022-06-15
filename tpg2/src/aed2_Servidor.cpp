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
    SimCity s = _server.at(j);
    Nat nivel = 0;
    if (s.casas().count(c) == 1) {
        nivel = s.nivelCasa(c);
    } else if (s.comercios().count(c) == 1) {
        nivel = s.nivelComercio(c);
    }
    return nivel;
}

// TODO: Checkear si efectivamente esta función tiene que devolver
// true sii hay al menos una construcción en el SimCity
bool aed2_Servidor::huboConstruccion(Jugador j) const {
    SimCity s = _server.at(j);
    return (s.casas().size() > 0 || s.comercios().size() > 0);
}

