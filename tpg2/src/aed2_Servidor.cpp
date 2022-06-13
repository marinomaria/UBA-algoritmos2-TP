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
    return set<Nat>(s.mapa().horizontales());
}

set<Nat> aed2_Servidor::riosVerticales(Jugador j) const {
    SimCity s = _server.at(j);
    return set<Nat>(s.mapa().verticales());
}
