#include "aed2_Servidor.h"

aed2_Servidor::aed2_Servidor() : _server() {}

void aed2_Servidor::nuevaPartida(Jugador j, set<Nat> horizontales, set<Nat> verticales) {
    _server.registrar(j, verticales, horizontales);
}

void aed2_Servidor::unir(Jugador j1, Jugador j2) {
    _server.unir(j1, j2);
}

set<Nat> aed2_Servidor::riosHorizontales(Jugador j) const {
    // todo: falta uniones de uniones
    SimCity s = _server.at(j);
    set<Nat> horizontales = s.mapa().horizontales();
    for (int i = 0; i < s.uniones().size(); ++i) {
        Mapa m = s.uniones()[i]->mapa();
        for (Nat h: m.horizontales()) {
            horizontales.insert(h);
        }
    }
    return horizontales;
}

set<Nat> aed2_Servidor::riosVerticales(Jugador j) const {
    SimCity s = _server.at(j);
    return set<Nat>(s.mapa().verticales());
}

set<Casilla> aed2_Servidor::casas(Jugador j) const {
    set<Casilla> casilla_casa;
    SimCity s = _server.at(j);
    for (pair<Casilla , Nat> ks : s.casas()) {
        casilla_casa.insert(ks.first);
    }
    return casilla_casa;
}

set<Casilla> aed2_Servidor::comercios(Jugador j) const {
    set<Casilla> casilla_comercio;
    SimCity s = _server.at(j);
    for (pair<Casilla , Nat> ks : s.comercios()) {
        casilla_comercio.insert(ks.first);
    }
    return casilla_comercio;
}

