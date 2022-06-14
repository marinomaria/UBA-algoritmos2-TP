#ifndef TP_SIMCITY_SIMCITY_H
#define TP_SIMCITY_SIMCITY_H

#include "Tipos.h"
#include "Mapa.h"
using namespace std;

class SimCity {
public:
    SimCity(Mapa m);

    void avanzarTurno(set<Casilla> casas, set<Casilla> comercios);

    Mapa mapa();

    map<Casilla, Nat> casas();

    map<Casilla, Nat> comercios();

    Nat nivelComercio(Casilla p);

    Nat nivelCasa(Casilla p);

    void unir(SimCity s2);

    vector<SimCity*> uniones();

private:
    vector<SimCity*> _uniones;
    Nat _turnoActual;
    map<Casilla, Nat> _casas;
    map<Casilla, Nat> _comercios;
    Mapa _mapa;

};

#endif //TP_SIMCITY_SIMCITY_H
