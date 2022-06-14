#include "Servidor.h"

// TODO: verificar si esta función es estrictamente necesaria
// (ya que no está en la especificación)
SimCity Servidor::at(Jugador j1) const {
    return _trie.at(j1);
}