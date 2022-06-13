#ifndef TP_SIMCITY_SERVIDOR_H
#define TP_SIMCITY_SERVIDOR_H

#include "SimCity.h"
#include "string_map.h"

class Servidor {
public:
    Servidor();
    void registrar(Jugador j, set<Nat> verticales, set<Nat> horizontales);
    void avanzarTurno(Jugador j, set<Casilla> casas, set<Casilla> comercios);
    void unir(Jugador j1, Jugador j2);
    SimCity at(Jugador j1) const;
private:
    string_map<SimCity> _trie;
};

SimCity Servidor::at(Jugador j1) const {
    return _trie.at(j1);
}

#endif //TP_SIMCITY_SERVIDOR_H
