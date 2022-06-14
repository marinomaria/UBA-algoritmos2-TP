#include "aed2_Servidor.h"

aed2_Servidor::aed2_Servidor() : _server() {}

void aed2_Servidor::nuevaPartida(Jugador j, set<Nat> horizontales, set<Nat> verticales) {
    _server.registrar(j, verticales, horizontales);
}

void aed2_Servidor::unir(Jugador j1, Jugador j2) {
    _server.unir(j1, j2);
}

set<Nat> aed2_Servidor::riosHorizontales(Jugador j) const {
    SimCity s = _server.at(j);
    return s.mapa().horizontales();
}

set<Nat> aed2_Servidor::riosVerticales(Jugador j) const {
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

