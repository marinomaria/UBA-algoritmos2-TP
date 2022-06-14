#include "Servidor.h"

// TODO: verificar si esta función es estrictamente necesaria
// (ya que no está en la especificación)
SimCity Servidor::at(Jugador j1) const {
    return _trie.at(j1);
}

Servidor::Servidor() : _trie() {};

void Servidor::registrar(Jugador j, set<Nat> verticales, set<Nat> horizontales) {
    pair<string, SimCity> p = make_pair(j, SimCity(Mapa(verticales, horizontales)));
    _trie.insert(p);
}

void Servidor::unir(Jugador j1, Jugador j2) {
    SimCity s1 = _trie.at(j1);
    SimCity s2 = _trie.at(j2);
    s1.unir(s2);
}

